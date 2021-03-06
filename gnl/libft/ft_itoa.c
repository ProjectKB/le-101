/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 17:56:28 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:17:35 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

static int		ft_count_number(int n)
{
	int		count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	if (n <= 0)
		count++;
	return (count);
}

static void		ft_reverse_str(char *str)
{
	int		start;
	int		end;
	int		swap;

	start = 0;
	end = 0;
	if (str[start] == '-')
		start++;
	while (str[end + 1])
		end++;
	while (start < end)
	{
		swap = str[start];
		str[start] = str[end];
		str[end] = swap;
		start++;
		end--;
	}
}

static int		ft_particular_case(char *str, int i, long *nb)
{
	if (*nb < 0)
	{
		*nb *= -1;
		str[0] = '-';
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	nb;

	i = 0;
	nb = n;
	if (!(str = (char*)malloc(sizeof(*str) * ft_count_number(nb) + 1)))
		return (NULL);
	if (!nb)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	if (nb < 0)
		i = ft_particular_case(str, i, &nb);
	while (nb != 0)
	{
		str[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	str[i] = '\0';
	ft_reverse_str(str);
	return (str);
}
