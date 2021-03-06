/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fix_impossible_flag.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:28:56 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 07:13:13 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	fix_impossible_comb(char **flag)
{
	if (ft_strchr(*flag, '0') && ft_strchr(*flag, '-'))
		ft_remove_char_from_str(flag, '0');
	if (ft_strchr(*flag, '+') && ft_strchr(*flag, ' '))
		ft_remove_char_from_str(flag, ' ');
}

void	fix_impossible_flag(char **flag, t_ci c_i)
{
	if (c_i == di && ft_strchr(*flag, '#'))
		ft_remove_char_from_str(flag, '#');
	if (c_i == u && ft_strchr(*flag, '#'))
		ft_remove_char_from_str(flag, '#');
	if ((c_i == u || c_i == o) && ft_strchr(*flag, '+'))
		ft_remove_char_from_str(flag, '+');
	if ((c_i == x || c_i == X) && ft_strchr(*flag, ' '))
		ft_remove_char_from_str(flag, ' ');
	if ((c_i == x || c_i == X) && ft_strchr(*flag, '+'))
		ft_remove_char_from_str(flag, '+');
	if ((c_i == c || c_i == s || c_i == p) && ft_strchr(*flag, '#'))
		ft_remove_char_from_str(flag, '#');
	if ((c_i == c || c_i == s || c_i == p || c_i == spe) \
													&& ft_strchr(*flag, '+'))
		ft_remove_char_from_str(flag, '+');
	if ((c_i == c || c_i == s || c_i == p || c_i == spe) \
													&& ft_strchr(*flag, ' '))
		ft_remove_char_from_str(flag, ' ');
	if ((c_i == c || c_i == s || c_i == p) && ft_strchr(*flag, '0'))
		ft_remove_char_from_str(flag, '0');
}

void	del_flag_repetition(char **flag)
{
	char	c;

	if (*flag)
		while ((c = ft_nb_char_occur(*flag)) != '|')
			ft_remove_one_char_from_str(flag, c);
}

void	transform_flag(t_arg *param)
{
	fix_impossible_flag(&param->flag, param->c_i);
	fix_impossible_comb(&param->flag);
	del_flag_repetition(&param->flag);
}
