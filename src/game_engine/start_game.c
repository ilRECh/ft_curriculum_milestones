/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:20:05 by ilRECh            #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    cub3d(char *map)
{
    static t_all    all;
    int                fd;

    if (!ft_strrchr(map, '.') || ft_strncmp(ft_strrchr(map, '.') + 1, "cub", 4))
    {
        printf(RED "Error\n" RESET "invalid file\n");
        return (1);
    }
    
    fd = open(map, O_RDONLY);
    
    if (!fd || (read(fd, NULL, 0) < 0 && !close(fd)))
    {
        printf(RED "Error\n" RESET "invalid file\n");
        return (1);
    }

    if (setup_all(&all))
    {
        printf(RED "Error\n" RESET "no space left\n");
        return (1);
    }
    
    if (parse(&all, fd))
    {
        printf(RED "Error\n" RESET "invalid file formatting: %s\n", all.err);
        fall(&all);
        return (1);
    }
    
    game(&all);

    return (0);
}
