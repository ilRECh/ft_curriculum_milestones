#include "fdf.h"
#include "mouse.h"

static int	mlxclose(int keycode, t_conf *mlx)
{
	if (keycode == 53)
	{	
		mlx_destroy_window(mlx->instance, mlx->window);
		exit(0);
	}
	else if (keycode < 0)
		exit(0);
	return (0);
}

void	hooks_setup(t_mouse	*mouse)
{
	mlx_hook(mouse->mlx.window, 2, 1L << 0, mlxclose, &mouse->mlx);
	mlx_hook(mouse->mlx.window, 17, 1L << 17, mlxclose, (void *) -1);
	mlx_hook(mouse->mlx.window, 4, 1L << 2, mouse_press, mouse);
	mlx_hook(mouse->mlx.window, 6, 1L << 6, mouse_move, mouse);
	mlx_hook(mouse->mlx.window, 5, 1L << 3, mouse_release, mouse);
}
