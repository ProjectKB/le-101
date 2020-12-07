#include "ft_ssl.h"

void print_base64(t_hash *h, int mod, char *stdin)
{
	if (test_bit(&h->flag, FLAG_O))
		write_output(h);
	else if (test_bit(&h->flag, FLAG_D))
		ft_printf ("%s", h->base64.output);
	else
		ft_printf ("%s\n", h->base64.output);
}