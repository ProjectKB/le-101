/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_canva.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 15:17:37 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 11:36:21 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_canva(int nb, char ***tab)
{
	int		size;
	char	**canva;
	int		i;
	int		j;

	size = 2;
	i = 0;
	while (size * size < nb)
		size++;
	while ((*tab)[i])
		i++;
	if (nb / 4 == 1 && (ft_strlen(*tab[0]) == 4 || i == 4))
		size++;
	i = -1;
	if (!(canva = ft_dbstrnew(size)))
		ft_error();
	while (++i < size)
	{
		j = 0;
		if (!(canva[i] = ft_strnew(size)))
			ft_error();
		while (j < size)
			canva[i][j++] = '.';
	}
	return (canva);
}
