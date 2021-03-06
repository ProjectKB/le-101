#include "ft_ssl.h"

static int welcome_to_hell(t_hash *h)
{
	int rt;
	int rt2;

	rt2 = 0;
	rt = read(h->fd, h->line, h->nb_bytes);
	if (rt != h->nb_bytes)
	{
		rt2 = read(h->fd, &(h->line[rt]), h->nb_bytes - rt);
		return (rt + rt2);
	}
	return (rt);
}

static int	read_bytes(t_hash *h, int mod)
{
	int			i;
	int			j;
	static int	count = 0;
	static int	stop = FALSE;

	i = -1;
	j = count * h->nb_bytes - 1;
	ft_bzero(h->line, h->nb_bytes + 1);
	if (mod != STRING && !test_bit2(&h->action, CHANGE_MOD))
		return (welcome_to_hell(h));
	if (!h->arg || stop)
	{
		stop = FALSE;
		count = 0;
		return (0);
	}
	while (++i < h->nb_bytes)
	{
		if (!h->arg[++j] && (stop = TRUE))
			return (i);
		h->line[i] = h->arg[j];
	}
	if (!h->arg[j] && (stop = TRUE))
		return (i);
	count++;
	return (h->nb_bytes);
}

int			process(t_hash *h, int mod)
{
	if ((h->fd = get_fd(h->arg, mod)) == -1 && mod == FILE)
		return (no_such_file(h));
	g_init_functions[h->i](h);
	while ((h->rest = read_bytes(h, mod)) > 0)
		g_proceed_block_functions[h->i](h);
	if (h->rest == -1)
		freexit(h, "There was a problem while reading.\n", 2);
	g_proceed_last_block_functions[h->i](h);
	g_print_functions[h->i](h, mod);
	g_free_functions[h->i](h);
	close(h->fd);
	return (0);
}
