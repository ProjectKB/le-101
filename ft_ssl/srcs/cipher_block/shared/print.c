#include "ft_ssl.h"

void	print_salt_key_iv(t_hash *h)
{
	ft_printf("salt: ");
	ft_hexstr(h->des.salt, 8);
	ft_printf("key:  ");
	ft_print_bits_to_hexa(h->des.key, 64);
	ft_printf("iv:   ");
	ft_print_bits_to_hexa(h->des.iv, 64);
}

void	remove_padding(t_hash *h)
{
	int pad;
	int end;

	end = (h->des.turn - 1) * 8;
	pad = h->des.output[end - 1];
	h->des.output[end - pad] = '\0';
}

void	print_des(t_hash *h, int mod, char *stdin)
{
	//h->arg = h->des.output;
	//base64_custom(h, FALSE);

	remove_padding(h);
	ft_printf("%s", h->des.output);

	exit(0);
}
