/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilRECh <ilRECh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:43:35 by csamuro           #+#    #+#             */
/*   Updated: 2022/07/21 13:47:22 by ilRECh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    image_to_window(t_all *all, const t_image *img, t_point position)
{
    return (mlx_put_image_to_window \
    (all->win->mlx, all->win->win, img->img, position.x, position.y));
}

t_image    *xpm_to_new_image(t_all *all, char *path_to_xpm)
{
    t_image    *img;

    img = malloc(sizeof(t_image));
    if (!img)
        exit(EXIT_FAILURE);
    img->img = mlx_xpm_file_to_image \
        (all->win->mlx, path_to_xpm, &img->size.x, &img->size.y);
    img->addr = mlx_get_data_addr \
        (img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    return (img);
}

t_image    xpm_to_image(t_all *all, char *path_to_xpm)
{
    t_image    img;

    img.img = mlx_xpm_file_to_image \
        (all->win->mlx, path_to_xpm, &img.size.x, &img.size.y);
    img.addr = mlx_get_data_addr \
        (img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    return (img);
}

int    image_free(t_all *all, t_image    *img, bool mode)
{
    int    ret;

    if (img && img->img && all && all->win && all->win->win)
    {
        ret = mlx_destroy_image(all->win->mlx, img->img);
        if (mode)
            free (img);
        return (ret);
    }
    return (-1);
}
