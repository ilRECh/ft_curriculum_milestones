#include "cub3d.h"

// считаю габариты карты x & y
t_point		map_len(char **maps)
{
	t_point	point;

	point.x = (point.y = 0);
	while (maps[point.y][point.x])
		point.x++;
	while (maps[point.y])
		point.y++;
	return (point);
}

t_win	*mlx_create( int width, int height )
{
	t_win	*win;

	win = malloc(sizeof(t_win));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, width, height, "default");
	return (win);
}

void    init(t_all *all)
{
    all->map_size = map_len(all->map);
	all->win = mlx_create(all->screen_size.x, all->screen_size.y);
	set_background(all);
// Создаю изображение для миниарты
	all->img_map = new_image(all->win->mlx, point_multiple(all->map_size, point_set(16, 16)));
// Задаю стартовые позиции игрока
	set_plrpos(all);
	set_plr(all, all->plrpos.x - 0.5f, all->plrpos.y - 0.5f, 0.5f);

// Подгоняю позиции игрока под пиксельный размер карты
	all->plr->x *= all->img_map->size.x / all->map_size.x;
	all->plr->y *= all->img_map->size.y / all->map_size.y;
// стены
	all->whalls[0] = xpm_to_image(all, all->textures[0]);
	all->whalls[1] = xpm_to_image(all, all->textures[1]);
}