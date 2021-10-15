#include "cub3d.h"

#define MLX_RED 0x800000
#define MLX_GRN 0x008000
#define MLX_BLU 0x000080
#define MLX_BLK 0x000000
#define MLX_WHT 0xFFFFFF
#define MLX_GRY 0x666666

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

// // закрашиваю квадратик пикселей
// void	drow_big_pixel(char c, t_image *img, t_point topnt, t_point	px)
// {
// 	unsigned int		colour = 0xFF000000;
// 	t_point	i;

// 	if (c == '1')
// 		colour = MLX_WHT;
// 	else if (c == '0')
// 		colour = MLX_GRY;
// 	else if (c == 'W')
// 		colour = MLX_GRN;
// 	px.x *= topnt.x;
// 	px.y *= topnt.y;
// 	i.x = (i.y = -1);
// 	while (++i.y < topnt.y)
// 	{
// 		while (++i.x < topnt.x)
// 			pixel_put(img, px.x + i.x, px.y + i.y, colour);
// 		i.x = -1;
// 	}
// }

// Закрашиваю изображение, (стена, пол или игрок)
void	draw_to_img_minmap(t_image *img_map, char **map, t_point topnt)
{
	t_point	px;

	px.x = (px.y = -1);
	while (map[++px.y])
	{
		while (map[px.y][++px.x])
		{
			fill_rect_to_img(t_image *img, const t_point *start, const t_point *end, const unsigned int colour);
		}
			// drow_big_pixel(map[px.y][px.x], img_map, topnt, px);
		px.x = -1;
	}
}

// рисую миникарты
void	create_img_minimap(t_all *all)
{
	// t_point	position;
	t_point	topnt;

	//	set SCALE for map pixel
	topnt.x = (all->screen_size.x / all->map_size.x) / 6;
	topnt.y = (all->screen_size.y / all->map_size.y) / 6;

	// position.x = 

	draw_to_img_minmap(all->buff, all->map, topnt);
}

// рисую изображение миникарты и задаю коодинаты игроку
void	draw_mimap(t_all *all)
{
	all->map_size = map_len(all->map);
	set_plrpos(all);
	set_plr(all, all->plrpos.x, all->plrpos.y, 0.5f);
	create_img_minimap(all);
}
