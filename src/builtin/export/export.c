/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:53:53 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/25 22:53:53 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_args(char **environ_, char **args)
{
	int		iter_1;
	char	*tmp;

	iter_1 = -1;
	while (args[++iter_1])
	{
		tmp = ft_strchr(args[iter_1], '=');
		if (tmp)
		{
			tmp = ft_strndup(args[iter_1], tmp - args[iter_1]);
			if (check_arg_in_exprt(args[iter_1], true))
				set_arg_value(tmp, args[iter_1]);
			else
				ft_lstadd_back(&g_param->exprt, ft_strdup(args[iter_1]));
			if (getvalue(tmp))
				setvalue(tmp, ft_strchr(args[iter_1], '=') + 1);
			else
				(*environ_ = ft_strdup(args[iter_1])), environ_++;
			free(tmp);
		}
		else
		{
			if (!check_arg_in_exprt(args[iter_1], false))
				ft_lstadd_back(&g_param->exprt, ft_strdup(args[iter_1]));
		}
	}
}

int	ft_export(char **args)
{
	int				env_count;
	int				iter_1;
	char			**environ_;

	if (!*(++args))
		return (print_exp());
	if (check_args(args))
		return (1);
	env_count = env_counter() + count_args(args);
	environ_ = ft_calloc(env_count + 1, sizeof(char *));
	iter_1 = -1;
	while (g_param->env[++iter_1])
		(environ_[iter_1] = g_param->env[iter_1]);//, free(g_param->env[iter_1]);
	free(g_param->env);
	copy_args(environ_ + iter_1, args);
	g_param->env = environ_;
	return (0);
}
