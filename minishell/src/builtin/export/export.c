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

static char	**split_by_eq(char *arg)
{
	char	*tmp;
	char	**result;

	tmp = ft_strchr(arg, '=');
	result = ft_calloc(2, sizeof(char *));
	if (!result)
		ft_exit(NULL);
	if (tmp)
	{
		result[0] = ft_strndup(arg, tmp - arg);
		result[1] = ft_strndup(tmp + 1, ft_strlen(tmp + 1));
	}
	else
	{
		result[0] = ft_strdup(arg);
		result[1] = NULL;
	}
	return (result);
}

static int	check_plus(char **split)
{
	char	*tmp;

	if (split[0][ft_strlen(split[0]) - 1] == '+')
	{
		split[0][ft_strlen(split[0]) - 1] = 0;
		if (getvalue(split[0]))
		{
			tmp = split[1];
			split[1] = ft_strjoin(getvalue(split[0]), split[1]);
			free(tmp);
		}
	}
	return (1);
}

int	ft_export(char **args)
{
	int		iter_1;
	char	**split;

	if (!*(++args))
		return (print_exp());
	iter_1 = -1;
	while (args[++iter_1])
	{
		split = split_by_eq(args[iter_1]);
		if (check_plus(split) && check_var(split[0]))
		{
			add_to_env(split);
			add_to_exprt(split);
			free_split(split);
		}
		else
		{
			error_str("export: "
				"not valid in this case: "), printf("%s\n", split[0]);
			free_split(split);
			break ;
		}
	}	
	return (0);
}
