/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_canva.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 15:17:37 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 18:36:36 by rcepre      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**create_canva(int nb, int size)
{
	char	**canva;
	int		i;
	int		j;

	while (size * size < nb)
		size++;
	i = -1;
	if (!(canva = ft_dbstrnew(size)))
		display_error();
	while (++i < size)
	{
		j = 0;
		if (!(canva[i] = ft_strnew(size)))
			display_error();
		while (j < size)
			canva[i][j++] = '.';
	}
	return (canva);
}