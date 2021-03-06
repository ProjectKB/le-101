/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 13:37:36 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:17:42 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "./includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*maillon;
	t_list	*tmp;

	maillon = *alst;
	while (maillon)
	{
		tmp = maillon->next;
		del(maillon->content, maillon->content_size);
		free(maillon);
		maillon = tmp;
	}
	*alst = NULL;
}
