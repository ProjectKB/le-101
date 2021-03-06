/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   precision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 18:19:47 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/16 06:30:54 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*precision_tr(char *content, t_arg *arg)
{
	if (arg->pre == -1 && arg->c_i != p)
		return (content);
	if (arg->c_i == s && !(arg->pre > ft_strlen(content)))
		return (ft_strfsub(content, 0, arg->pre));
	if (!arg->pre && arg->c_i != c &&
	arg->c_i != f && arg->c_i != p && !ft_atoi(content))
		ft_remove_char_from_str(&content, '0');
	if (arg->pre > ft_strlen(content))
		while (ft_strlen(content) != arg->pre && arg->c_i != s)
			content = ft_charrjoin(content, '0');
	if (arg->pre == ft_strlen(content) && ft_strchr(content, '-'))
		content = ft_charrjoin(content, '0');
	if (arg->c_i == p && arg->pre == -1)
		return (ft_strfsjoin("0x", content));
	else if (arg->c_i == p && ft_strlen(content) == 1 && content[0] == '0')
		return (ft_strfdup("0x", content));
	else if (arg->c_i == p)
		return (ft_strfsjoin("0x", content));
	return (content);
}
