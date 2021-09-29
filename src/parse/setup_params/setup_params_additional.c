/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_params_additional.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:08:48 by name              #+#    #+#             */
/*   Updated: 2021/09/29 11:11:04 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline bool	check_num(char *number)
{
	while (number && *number)
		if (!ft_isdigit(*number++))
			return (false);
	return (true);
}

inline bool	check_len_value(char **rgb)
{
	return ((ft_strlen(rgb[0]) > 3 || ft_strlen(rgb[0]) < 1
			|| !check_num(rgb[0]))
		|| (ft_strlen(rgb[1]) > 3 || ft_strlen(rgb[1]) < 1
			|| !check_num(rgb[1]))
		|| (ft_strlen(rgb[2]) > 3 || ft_strlen(rgb[2]) < 1
			|| !check_num(rgb[2])));
}
