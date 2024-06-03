/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <csamuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:37:03 by csamuro           #+#    #+#             */
/*   Updated: 2021/09/03 21:19:10 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	is_builtins(char **in)
{
	int		x;
	char	*str;

	str = trimmer(ft_strdup(*in), "\"\'", FULL);
	x = ft_strlen(str);
	if (x++ > 0 && (!ft_strncmp("cd", str, x)
			|| !ft_strncmp("echo", str, x)
			|| !ft_strncmp("env", str, x)
			|| !ft_strncmp("exit", str, x)
			|| !ft_strncmp("export", str, x)
			|| !ft_strncmp("pwd", str, x)
			|| !ft_strncmp("unset", str, x)))
	{
		free (*in);
		*in = str;
		return (TRUE);
	}
	else
		free (str);
	return (FALSE);
}
