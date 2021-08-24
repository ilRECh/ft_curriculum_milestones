/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:20:40 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 22:33:52 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_char2(t_list *lst)
{
	char	**tabs;
	int		len;

	len = ft_lstsize(*lst);
	tabs = (char **)malloc(sizeof(char *) * (len + 1));
	tabs[len] = NULL;
	lst->cur = lst->end;
	while (len--)
	{
		tabs[len] = lst->cur->content;
		lst->cur = lst->cur->prev;
	}
	return (tabs);
}

void	lst_trimmer(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	tmp->cur = tmp->head;
	while (tmp->cur)
	{
		trimmer(tmp->cur->content, "\"\' ");
		tmp->cur = tmp->cur->next;
	}
}
