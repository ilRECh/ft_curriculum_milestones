/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:37:03 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 21:42:13 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	is_builtins(char *str)
{
	int	x;

	x = ft_strlen(str);
	if (x < 1)
		return (FALSE);
	if (!ft_strncmp("cd", str, x)
		|| !ft_strncmp("echo", str, x)
		|| !ft_strncmp("env", str, x)
		|| !ft_strncmp("exit", str, x)
		|| !ft_strncmp("export", str, x)
		|| !ft_strncmp("pwd", str, x)
		|| !ft_strncmp("unset", str, x))
		return (TRUE);
	return (FALSE);
}
