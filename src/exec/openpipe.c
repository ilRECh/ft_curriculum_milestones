/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:31:14 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/24 21:40:28 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*\
 *
 *		Opens pipe if direction is true, and assigns rdrct->pipe.pipefd[1] to
 *	out list for the child writer to write. If the direction is false, then
 *	assigns rdrct->pipe values to rdrct->inall. 
 *
\*/
int	openpipe(t_rdrct *rdrct, int direction)
{
	if (direction)
	{
		rdrct->pipe.is = true;
		pipe(rdrct->pipe.pipefd);
		ft_lstadd_back(&rdrct->out, (void *)((long long)rdrct->pipe.pipefd[1]));
	}
	else
	{
		rdrct->pipe.is = false;
		rdrct->inall.is = true;
		rdrct->inall.pipefd[0] = rdrct->pipe.pipefd[0];
		rdrct->inall.pipefd[1] = rdrct->pipe.pipefd[1];
	}
	return (0);
}
