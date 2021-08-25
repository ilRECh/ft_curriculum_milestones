/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:20:51 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/24 21:40:27 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*\
 *
 *		read from all descriptors stored in the out list,
 *	write the read stuff to the infd descriptor. Close these descriptors.
 *	The infd descriptor will be passed to a program as input further.
 *
\*/
void	in(t_list *in, int infd)
{
	int		rd;
	char	buf[1000];

	rd = 1;
	in->cur = in->head;
	while (in->cur)
	{
		while (rd > 0)
		{
			rd = read((int)in->cur->content, buf, 1000);
			write(infd, buf, rd);
		}
		close((int)in->cur->content);
		in->cur = in->cur->next;
		rd = 1;
	}
	ft_lstclear(in, ft_close);
}

/*\
 *
 *		Fucntion for a child writer, who will read from outfd,
 *	and put everything in fds in the out list.
 *
\*/
void	out(t_list *out, int outfd)
{
	int		rd;
	char	buf[1000];

	rd = 1;
	if (out && ft_lstsize(*out))
	{
		while (rd > 0)
		{
			out->cur = out->head;
			rd = read(outfd, buf, 1000);
			while (out->cur)
			{
				write((int)out->cur->content, buf, rd);
				out->cur = out->cur->next;
			}
		}
	}
	else
	{
		while (rd > 0)
		{
			rd = read(outfd, buf, 1000);
			write(1, buf, rd);
		}
	}
}
