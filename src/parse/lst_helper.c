/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:40 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/03 20:47:54 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_char2(t_list *lst)
{
	char	**tabs;
	int		len;

	len = ft_lstsize(*lst);
	if (!lst || !lst->head)
		return (NULL);
	tabs = NULL;
	if (len)
	{
		tabs = (char **)ft_calloc(sizeof(char *), (len + 1));
		tabs[len] = NULL;
		lst->cur = lst->head;
		while (lst->cur && lst->cur->next)
			lst->cur = lst->cur->next;
		lst->end = lst->cur;
	}
	while (len--)
	{
		tabs[len] = slash_parse(lst->cur->content);
		lst->cur = lst->cur->prev;
	}
	ft_lstclear(lst, NULL);
	return (tabs);
}

// void	lst_trimmer(t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	tmp->cur = tmp->head;
// 	trimmer(tmp->cur->content, "\"\' ");
// }
