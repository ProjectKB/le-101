#include "ft_ssl.h"

static void	transform_buffer(t_md5 *md5, __uint32_t *buf, __uint32_t e, int i)
{
	__uint32_t	tmp;

	tmp = buf[3];
	buf[3] = buf[2];
	buf[2] = buf[1];
	buf[1] = buf[1] + rotl(buf[0] + e + \
	md5->words[g_wi[i]] + g_sin[i], g_shift[i]);
	buf[0] = tmp;
}

static void	transform_block(t_md5 *md5)
{
	int			i;
	int			j;
	int			k;
	__uint32_t	buf[4];

	i = -1;
	j = -1;
	k = -1;
	while (++i < 4)
		buf[i] = md5->buf[i];
	while (++j < 64)
		transform_buffer(md5, buf, \
		g_round_functions[j / 16](buf[1], buf[2], buf[3]), j);
	while (++k < 4)
		md5->buf[k] += buf[k];
}

static void	special_process(t_md5 *md5)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -4;
	k = -1;
	while (++k < 16 && (j += 4) < 64)
		md5->words[k] = md5->input[j + 3] << 24 | md5->input[j + 2] << 16 | \
		md5->input[j + 1] << 8 | md5->input[j];
	transform_block(md5);
	while (++i < 56)
		md5->input[i] = 0;
}

void		proceed_block_md5(t_hash *h)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	j = h->md5.nb_bits % 64 - 1;
	k = -1;
	l = -4;
	h->md5.nb_bits += (__uint64_t)h->rest;
	while (++i < h->rest)
		h->md5.input[++j] = h->line[i];
	if (i == 64)
	{
		while (++k < 16 && (l += 4) < 64)
			h->md5.words[k] = h->md5.input[l + 3] << 24 | \
			h->md5.input[l + 2] << 16 | \
			h->md5.input[l + 1] << 8 | h->md5.input[l];
		transform_block(&h->md5);
	}
	if (test_bit(&h->flag, FLAG_P))
		h->md5.stdin = ft_strjoin2(h->md5.stdin, h->line);
}

void		proceed_last_block_md5(t_hash *h)
{
	int	i;
	int	j;
	int	k;
	int	start;
	int	block_len;

	i = -1;
	j = -4;
	k = -1;
	start = h->md5.nb_bits % 64;
	block_len = start < 56 ? 56 : 64;
	while (start < block_len)
		h->md5.input[start++] = g_padding[++i];
	if (start > 56)
		special_process(&h->md5);
	while (++k < 14 && (j += 4) < 56)
		h->md5.words[k] = h->md5.input[j + 3] << 24 | \
		h->md5.input[j + 2] << 16 | h->md5.input[j + 1] << 8 | h->md5.input[j];
	h->md5.words[14] = (__uint32_t)(h->md5.nb_bits << 3);
	h->md5.words[15] = (__uint32_t)((h->md5.nb_bits << 3) >> 32);
	transform_block(&h->md5);
	digest_message(&h->md5);
}
