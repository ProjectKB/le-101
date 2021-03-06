/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 13:50:26 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 22:06:41 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		exceed_board(t_filler *f, int y, int x)
{
	return (x + f->px_max >= f->bx_max || y + f->py_max >= f->by_max ? 1 : 0);
}

int		occupied(t_filler *f, int sy, int sx)
{
	int	i;
	int	j;

	i = -1;
	f->score.c = 0;
	while (++i < f->py_max && (j = -1))
		while (++j < f->px_max)
		{
			if (f->board[sy + i][sx + j] == f->c_los || \
									f->board[sy + i][sx + j] == f->c_los + 32)
				if (f->piece[i][j] == '*')
					return (1);
			if (f->board[sy + i][sx + j] == f->c_win || \
									f->board[sy + i][sx + j] == f->c_win + 32)
				if (f->piece[i][j] == '*')
					f->score.c++;
		}
	if (f->score.c != 1)
		return (1);
	return (0);
}

void	place_piece(t_filler *f, int sy, int sx)
{
	int	i;
	int	j;

	i = -1;
	f->score.v_t = 0;
	while (++i < f->py_max && (j = -1))
		while (++j < f->px_max)
			f->score.v_t += f->iboard[i + sy][j + sx];
	if (f->score.v_t < f->score.v)
	{
		f->score.x = sx;
		f->score.y = sy;
		f->score.v = f->score.v_t;
	}
}

void	resolve(t_filler *f)
{
	int	i;
	int	j;

	i = -1;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
			if (!exceed_board(f, i, j) && !occupied(f, i, j))
				place_piece(f, i, j);
	f->score.v = 1000000;
	f->score.v_t = 0;
}
