#include "ft_ssl.h"

void    init_des(t_hash *h)
{
	h->des.key_gen = 0;
	h->des.iv = 0;
	h->des.turn = 0;
	h->nb_bytes = 8;
	h->des.rest = 0;
	if (!(h->des.output = (unsigned char*)malloc(sizeof(char) * h->nb_bytes + 1)))
        print_and_quit("Congrats, you broke malloc.\n", 2);
	//EVP_bytes_to_Key(h, (const unsigned char *)"password", FALSE);
	h->des.key = 0xB96F5BE8BEBFF50C;
	h->des.iv = 0x6591CADBEC326648;
	//h->des.buf = 0x123456ABCD132536;
	generate_key2(h);
	//init_key(h);
}

static void	prepare_output(t_hash *h)
{
	int i;
	int shift;

	i = -1;
	shift = 64;
	while (++i < 8 && (shift -= 8) != -1)
		h->des.output[h->des.turn * 8 + i] = (unsigned char)(h->des.buf >> shift);
	++h->des.turn;
}

void	init_buf(t_hash *h)
{
	int i;
	int shift;
	int pad;

	i = 0;
	shift = 64;
	if (h->des.turn)
		h->des.iv = h->des.buf;
	h->des.buf = 0;
	while (i < h->rest && (shift -= 8) != -1)
		h->des.buf |= ((uint64_t)h->line[i++] << shift);
	if (h->rest != h->nb_bytes && (pad = h->nb_bytes - h->rest) != -1)
		while (i++ < h->nb_bytes && (shift -= 8) != -1)
			h->des.buf |= ((uint64_t)pad << shift);
	if (h->i == DES_CBC)
		h->des.buf ^= h->des.iv;
}

void    proceed_block_des(t_hash *h)
{
    int i;

	i = 16;
	h->line[0] = 0x90; 
	h->line[1] = 0x2A;
	h->line[2] = 0xA8;
	h->line[3] = 0x2D;
	h->line[4] = 0x09;
	h->line[5] = 0xCD;
	h->line[6] = 0xC8;
	h->line[7] = 0x82;
	if (h->rest != h->nb_bytes)
		h->des.rest = h->rest;
	if (!(h->des.output = ft_realloc(h->des.output, h->des.turn * 8, h->nb_bytes + 1)))
        free_and_quit("Congrats, you broke malloc.\n", h->des.output, 2);
	init_buf(h);
    h->des.buf = permut_x_bits(&h->des.buf, g_ip, 64, 64);
    h->des.lpt = (h->des.buf >> 32);
    h->des.rpt = (h->des.buf & 0xFFFFFFFF);
    while (--i > -1)
    {
		//generate_key(h, &i);
		h->des.lpt_next = h->des.rpt;
        h->des.rpt_gen = permut_x_bits(&h->des.rpt, g_e, 32, 48);
        h->des.rpt_gen ^= h->des.keys[i];
		h->des.rpt_gen = s_box_substitution(&h->des.rpt_gen);
		h->des.rpt_gen = permut_x_bits(&h->des.rpt_gen, g_p, 32, 32);
		h->des.rpt = (h->des.rpt_gen ^ h->des.lpt);
		h->des.lpt = h->des.lpt_next;
    }
	h->des.buf = (h->des.rpt << 32) | h->des.lpt;
	h->des.buf = permut_x_bits(&h->des.buf, g_ep, 64, 64);
	ft_print_bits_to_hexa(h->des.buf, 64);
	exit(0);
	prepare_output(h);
}

/* void    proceed_block_des(t_hash *h)
{
    int i;

	i = 16;
	if (h->rest != h->nb_bytes)
		h->des.rest = h->rest;
	if (!(h->des.output = ft_realloc(h->des.output, h->des.turn * 8, h->nb_bytes + 1)))
        free_and_quit("Congrats, you broke malloc.\n", h->des.output, 2);
	//init_buf(h);
    h->des.buf = permut_x_bits(&h->des.buf, g_ip, 64, 64);
    h->des.lpt = (h->des.buf >> 32);
    h->des.rpt = (h->des.buf & 0xFFFFFFFF);
    while (--i > -1)
    {
		//generate_key(h, &i);
		h->des.lpt_next = h->des.rpt;
        h->des.rpt_gen = permut_x_bits(&h->des.rpt, g_e, 32, 48);
        h->des.rpt_gen ^= h->des.keys[i];
		h->des.rpt_gen = s_box_substitution(&h->des.rpt_gen);
		h->des.rpt_gen = permut_x_bits(&h->des.rpt_gen, g_p, 32, 32);
		h->des.rpt = (h->des.rpt_gen ^ h->des.lpt);
		h->des.lpt = h->des.lpt_next;
    }
	h->des.buf = (h->des.rpt << 32) | h->des.lpt;
	h->des.buf = permut_x_bits(&h->des.buf, g_ep, 64, 64);
	ft_print_bits_to_hexa(h->des.buf, 64);
	exit(0);
	prepare_output(h);
} */

void	proceed_last_block_des(t_hash *h)
{
	if (!h->des.rest)
		proceed_block_des(h);
}