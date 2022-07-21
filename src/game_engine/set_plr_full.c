/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plr_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:54:27 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    set_plrpos(t_all *all)
{
    t_point    i;

    i = pnt_s(-1);
    while (++i.y < all->map_size.y)
    {
        while (++i.x < all->map_size.x)
        {
            if (ft_strchr("EWSN", all->map[i.y][i.x]))
            {
                all->plrpos.direction = all->map[i.y][i.x];
                all->plrpos.x = i.x;
                all->plrpos.y = i.y;
                all->map[i.y][i.x] = '0';
                i.y = all->map_size.y;
                break ;
            }
        }
        i.x = -1;
    }
}

static float    get_start_dir(char c)
{
    if (c == 'S')
        return (0);
    else if (c == 'N')
        return (degToRad(180));
    else if (c == 'E')
        return (degToRad(90));
    return (degToRad(-90));
}

// Вызов должен быть осуществлен строго после ( set_plrpos(t_all, map_size); )
void    set_plr(t_all *all, float x, float y)
{
    all->plr = malloc(sizeof(t_player));
    all->plr->x = x;
    all->plr->y = y;
    all->plr->dir = get_start_dir(all->plrpos.direction);
}
