/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_piece_to_canva.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 21:41:40 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 13:38:04 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	ft_piece_to_canva(char ***canva, int y, int x, char **piece)
{

	int			i;
	int			j;

	i = 0;
	j = 0;
	while (piece[i] != NULL)
	{
		j = 0;
		while (piece[i][j])
		{
			if ((*canva)[y + i][x + j] == '.')
				(*canva)[y + i][x + j] = piece[i][j];
			j++;
		}
		i++;
	}
	return (1);
}
