/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:19:49 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/24 21:40:21 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*\
 *
 *		Looks for either braces sublst, or command to execute.
 *	sublst->cur will point to the element with above containings at the end
 *	of the func execution.
 *
\*/
void	find_sublst_or_command(t_list *sublst)
{
	sublst->cur = sublst->head;
	while (sublst->cur && sublst->cur != sublst->end && !((t_parse *)sublst->cur->content)->argv[0])
		sublst->cur = sublst->cur->next;
	//if ()
}
