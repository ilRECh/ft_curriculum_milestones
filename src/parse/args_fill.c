/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcobbler <vcobbler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 06:19:43 by csamuro           #+#    #+#             */
/*   Updated: 2021/08/24 22:34:11 by vcobbler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**argv_fill_1(char *str1)
{
	char	**argv;

	argv = (char **) malloc(sizeof(char *) * 2);
	argv[0] = str1;
	argv[1] = NULL;
	return (argv);
}

char	**argv_fill_2(char *str1, char *str2)
{
	char	**argv;

	argv = (char **) malloc(sizeof(char *) * 3);
	argv[0] = str1;
	argv[1] = str2;
	argv[2] = NULL;
	return (argv);
}
