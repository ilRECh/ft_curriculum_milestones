#ifndef MOUSE_H
# define MOUSE_H

# include "fdf.h"

static int	mouse_move(int x, int y, t_mouse *mouse)
{
	uint8_t	condition;

	condition = abs(abs(mouse->x) - abs(x)) >= DRAW_STEP
		|| abs(abs(mouse->y) - abs(y)) >= DRAW_STEP;
	if (mouse->is_pressed == 1 && condition)
	{
		translate((x - mouse->x) * 0.14, (y - mouse->y) * 0.14, mouse->map, mouse->mlx);
		mouse->x = x;
		mouse->y = y;
	}
	else if (mouse->is_pressed == 2 && condition
		&& mouse->mlx.projection != PARALLEL)
	{
		//rotate();
		mouse->x = x;
		mouse->y = y;
	}
	else if (mouse->is_pressed == 4 || mouse->is_pressed == 5)
		(void)0;//scale()
	return (0);
}

static int mouse_press(int button, int x, int y, t_mouse *mouse)
{
	if (button != 3)
	{
		mouse->x = x;
		mouse->y = y;
		mouse->is_pressed = button;
		return (0);
	}
	else if (button == 3 && mouse->mlx.projection == ISOMETRIC)
		parallel(mouse->map, &mouse->mlx);
	else if (button == 3 && mouse->mlx.projection == PARALLEL)
		isometric(mouse->map, &mouse->mlx);
	draw(mouse->map, mouse->mlx);
	return (0);
}

static int mouse_release(int button, int x, int y, t_mouse *mouse)
{
	(void)button;
	(void)x;
	(void)y;
	mouse->is_pressed = 0;
	return (0);
}

#endif