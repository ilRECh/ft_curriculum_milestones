/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprtutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 20:54:52 by vcobbler          #+#    #+#             */
/*   Updated: 2021/08/27 21:26:53 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_counter(void)
{
	int	iter_1;

	iter_1 = -1;
	while (g_param->env[++iter_1])
		;
	return (iter_1);
}

int	count_args(char **args)
{
	int		iter_1;
	int		additional;
	char	*tmp;

	iter_1 = -1;
	additional = 0;
	while (args[++iter_1])
	{
		tmp = ft_strchr(args[iter_1], '=');
		if (tmp)
		{
			tmp = ft_strndup(args[iter_1], tmp - args[iter_1]);
			if (!getvalue(tmp))
				additional++;
			free(tmp);
		}
	}
	return (additional);
}

int	check_args(char **args)
{
	int	iter_1;
	int	iter_2;

	iter_1 = -1;
	while (args[++iter_1])
	{
		iter_2 = -1;
		while (args[iter_1][++iter_2])
			if (isspace(args[iter_1][iter_2]))
				return (error_str("not allowed: "),
					printf("%s\n", args[iter_1]), 1);
	}
	return (0);
}

int	check_arg_in_exprt(char *arg, bool iseqsign)
{
	char	*cont;
	bool	found;
	bool	ret;

	ret = false;
	g_param->exprt.cur = g_param->exprt.head;
	while (g_param->exprt.cur)
	{
		cont = g_param->exprt.cur->content;
		if (iseqsign)
			arg = ft_strndup(arg, ft_strchr(arg, '=') - arg);
		found = !ft_strncmp(arg, cont, ft_strlen(arg));
		if (found && *(cont + ft_strlen(arg)) == 0)
		{
			g_param->exprt.cur->content = ft_strjoin(cont, "=");
			free(cont);
			ret = true;
		}
		else if (found && *(cont + ft_strlen(arg)) == '=')
			ret = true;
		g_param->exprt.cur = g_param->exprt.cur->next;
	}
	if (iseqsign)
		free(arg);
	return (ret);
}

void	set_arg_value(char *word, char *new_value)
{
	char	*cont;

	g_param->exprt.cur = g_param->exprt.head;
	while (g_param->exprt.cur)
	{
		cont = g_param->exprt.cur->content;
		if (!ft_strncmp(word, cont, ft_strlen(word))
			&& ((*(cont + ft_strlen(word)) == 0)
				|| ((*(cont + ft_strlen(word)) == '='))))
		{
			g_param->exprt.cur->content = ft_strdup(new_value);
			free(cont);
			return ;
		}
		g_param->exprt.cur = g_param->exprt.cur->next;
	}
}
