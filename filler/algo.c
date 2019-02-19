/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 13:50:26 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 18:32:00 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	transform_map(t_filler *f)
{
	int	i;
	int	j;
	int vx;
	int vy;

	i = -1;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
			if (f->board[i][j] == '.')
			{
				vx = j >= f->last.x ? j - f->last.x : f->last.x - j;
				vy = i >= f->last.y ? i - f->last.y : f->last.y - i;
				f->board[i][j] = vx >= vy ? vx + 33 : vy + 33;
			}
}

int		exceed_board(t_filler *f, int sy, int sx)
{
	if (sx + f->px_max >= f->bx_max || sy + f->py_max >= f->by_max)
		return (1);
	return (0);
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
			if (f->board[sy + i][sx + j] == f->c_los || f->board[sy + i][sx + j] == f->c_los + 32)
				return (1);
			else if (f->board[sy + i][sx + j] == f->c_win || f->board[sy + i][sx + j] == f->c_win + 32)
				f->score.c++;
		}
	if (f->score.c != 1)
		return (1);
	return (0);
}

void	calcul_score(t_filler *f, int sy, int sx)
{
	int	i;
	int	j;

	i = -1;
	f->score.v_t = 0;
	while (++i < f->py_max && (j = -1))
		while (++j < f->px_max)
			f->score.v_t += f->board[i + sy][j + sx];
	if (f->score.v_t && f->score.v_t < f->score.v)
	{
		f->score.x = sx;
		f->score.y = sy;
		f->score.v = f->score.v_t;
	}
}

void        resolve(t_filler *f)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < f->by_max && (j = -1))
		while (++j < f->bx_max)
			if (!exceed_board(f, i, j) && !occupied(f, i, j))
				calcul_score(f, i, j);
	f->score.v = 10000;
	f->score.v_t = 0;
}
