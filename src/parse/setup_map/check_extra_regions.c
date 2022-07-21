/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra_regions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 23:44:53 by name              #+#    #+#             */
/*   Updated: 2022/07/21 13:48:39 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define STANDARD_FIELD_SYM      '0'
#define STANDARD_WALL_SYM       '1'
#define ENCRYPTED_FIELD_SYM     'A'
#define ENCRYPTED_WALL_SYM      'B'
#define ENCRYPTED_PLAYER_SYM    'Z'
#define OUTSIDE_MAP_SYM         ' '

typedef struct s_any
{
    int    x;
    int    y;
}   t_any;

typedef enum e_mode
{
    _encrypt,
    _decrypt
}   t_mode;

static inline bool check_symbol(t_mode mode, int y, int x, t_all *all)
{
    if (all->map[y][x] == OUTSIDE_MAP_SYM)
        return (true);
    else if (mode == _encrypt)
    {
        if (all->map[y][x] == ENCRYPTED_FIELD_SYM
            || all->map[y][x] == ENCRYPTED_WALL_SYM
            || all->map[y][x] == ENCRYPTED_PLAYER_SYM)
            return (true);
    }
    else if (mode == _decrypt)
    {
        if (all->map[y][x] == '0' || all->map[y][x] == '1'
            || all->map[y][x] == all->plrpos.direction)
            return (true);
    }
    return (false);
}

static void    proceed(t_mode mode, int y, int x, t_all *all)
{
    if (check_symbol(mode, y, x, all))
        return ;
    else if (mode == _encrypt)
        all->map[y][x] = 'A' * (all->map[y][x] == '0')
            + 'B' * (all->map[y][x] == '1')
            + 'Z' * (all->map[y][x] == all->plrpos.direction);
    else if (mode == _decrypt)
        all->map[y][x] = '0' * (all->map[y][x] == 'A')
            + '1' * (all->map[y][x] == 'B')
            + all->plrpos.direction * (all->map[y][x] == 'Z');
    proceed(mode, y - 1, x, all);
    proceed(mode, y - 1, x - 1, all);
    proceed(mode, y, x - 1, all);
    proceed(mode, y + 1, x - 1, all);
    proceed(mode, y + 1, x, all);
    proceed(mode, y + 1, x + 1, all);
    proceed(mode, y, x + 1, all);
    proceed(mode, y - 1, x + 1, all);
}

static bool    find_any(t_any *any, t_all *all, t_mode mode)
{
    any->y = -1;
    while (all->map[++any->y])
    {
        any->x = -1;
        while (all->map[any->y][++any->x])
        {
            if (mode == _encrypt && all->map[any->y][any->x] == STANDARD_FIELD_SYM)
                return (true);
            else if (mode == _decrypt && all->map[any->y][any->x] == ENCRYPTED_FIELD_SYM)
                return (true);
        }
    }
    return (false);
}

//'0' == 'A'
//'1' == 'B'
//all->plrpos.direction == 'Z'

bool    check_extra_regions(t_all *all)
{
    t_any    any;

    find_any(&any, all, _encrypt);
    proceed(_encrypt, any.y, any.x, all);
    if (find_any(&any, all, _encrypt))
        return (true);
    find_any(&any, all, _decrypt);
    proceed(_decrypt, any.y, any.x, all);
    return (false);
}
