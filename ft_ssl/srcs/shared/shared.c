#include "ft_ssl.h"

static int	read_bytes(t_hash *h, int mod)
{
	int			i;
	int			j;
	static int	count = 0;
	static int	stop = FALSE;

	i = -1;
	j = count * h->nb_bytes - 1;
	if (mod != STRING && !h->change_mod)
		return (read(h->fd, h->line, h->nb_bytes));
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
	char			*stdin;

	if (!(h->line = ft_memalloc(h->nb_bytes + 1)))
		free_and_quit("Congrats, you broke malloc.\n", h->base64.output, 2);
	if (mod == STDIN)
		stdin = ft_strdup("");
	if ((h->fd = get_fd(h->arg, mod)) == -1 && mod == FILE)
		return (no_such_file(h));
	g_init_functions[h->i](h);
	while ((h->rest = read_bytes(h, mod)))
	{
		if (h->rest == -1)
			read_error(h);
		g_proceed_block_functions[h->i](h);
		if (mod == STDIN)
			stdin = ft_strjoin2(stdin, h->line);
	}
	g_proceed_last_block_functions[h->i](h);
	g_print_functions[h->i](h, mod, stdin);
	if (mod == STDIN)
		free(stdin);
	return (0);
}
