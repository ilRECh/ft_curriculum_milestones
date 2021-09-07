/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:40 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/03 23:04:03 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_dlist	*ft_lst_getlast(t_list *lst)
{
	t_dlist	*tmp;

	tmp = lst->head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

char	**list_to_char2(t_list *lst)
{
	char	**tabs;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(*lst);
	if (!lst || !lst->head)
		return (NULL);
	tabs = NULL;
	if (len)
	{
		tabs = (char **)ft_calloc(sizeof(char *), (len + 1));
		tabs[len] = NULL;
		lst->cur = (lst->end = ft_lst_getlast(lst));
	}
	while (len--)
	{
		tabs[len] = slash_parse(lst->cur->content);
		lst->cur = lst->cur->prev;
	}
	// while (tabs && tabs[++len])
	// 	trimmer(tabs[len], "\"\'");
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
