/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_and_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:23:17 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 21:42:42 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_print_tab(char **split_dots)
{
	if (split_dots && *split_dots)
		while (*split_dots)
			printf(YELLOW " |%s| " RESET, *split_dots++);
}

char	*test_opers(unsigned short oper)
{
	if (oper == 1)
		return (ft_strdup(">"));
	if (oper == 2)
		return (ft_strdup("<"));
	if (oper == 3)
		return (ft_strdup("<<"));
	if (oper == 4)
		return (ft_strdup(">>"));
	if (oper == 5)
		return (ft_strdup(";"));
	if (oper == 6)
		return (ft_strdup("&&"));
	if (oper == 7)
		return (ft_strdup("||"));
	if (oper == 8)
		return (ft_strdup("|"));
	return(ft_strdup("0"));
}

void	test_print_lst(t_list *lst, int i)
{
	t_parse	*par;

	lst->cur = lst->head;
	while (lst->cur)
	{
		par = (t_parse *)(lst->cur->content);
		if (par->argv && *par->argv && !(par->oper > 4 && par->oper < 9)
			&& !ft_strncmp(CASE, (*par->argv), ft_strlen(CASE)))
		{
			printf(MAGENTA_BOLD "\n|%*s( sub_lst %d" RESET,(i) * 4, " ", i + 1);
			test_print_lst((t_list *)par->argv[1], i + 1);
			printf(MAGENTA_BOLD "\n|%*s) %s" RESET, (i) * 4, " ", test_opers(par->oper));
		}
		else
		{
			if (!(par->oper > 4 && par->oper < 9))
			{
				printf(BLUE "\n|%*s" RESET, i * 4, " ");
				printf(RED " %s " RESET, test_opers(par->oper));
				printf(BLUE "%-5s" RESET, *(par->argv));
				test_print_tab(&(par->argv)[1]);
			}
			else
				printf(MAGENTA_BOLD "\n| %*s" RED "%s "\
				 RESET, (i + 1) * 4, " ", test_opers(par->oper));
		}
		lst->cur = lst->cur->next;
	}
}
