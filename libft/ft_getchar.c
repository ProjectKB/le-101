/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_getchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 14:02:19 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 18:43:06 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	ft_getchar(void)
{
	char	c;

	read(0, &c, 1);
	return (c);
}
