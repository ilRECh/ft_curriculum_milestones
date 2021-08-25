/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_exec.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:42:22 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 22:42:23 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_EXEC_H
# define ADDITIONAL_EXEC_H

static inline void	init(int *pid, int *exitcode, t_rdrct **rdrct, t_list *lst)
{
	*pid = 0;
	*exitcode = 0;
	*rdrct = ft_calloc(1, sizeof(t_rdrct));
	lst->cur = lst->head;
}

#endif // ADD_EXEC_H