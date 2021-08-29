/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:20:51 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/29 21:16:57 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in(t_list *in, int infd)
{
	long	rd;
	char	*buf;

	rd = 1;
	in->cur = in->head;
	buf = malloc(sizeof(char) * 10000);
	if (!buf && error_str("f*q i'ma DEADBEEF"))
		exit(1);
	while (in->cur)
	{
		while (rd > 0)
		{
			rd = read((int)in->cur->content, buf, 10000);
			rd = write(infd, buf, rd);
		}
		close((int)in->cur->content);
		in->cur = in->cur->next;
		rd = 1;
	}
	free(buf);
	ft_lstclear(in, NULL);
}

void	out(t_list *out, int outfd)
{
	int		rd;
	char	buf[1000];

	rd = 42;
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
