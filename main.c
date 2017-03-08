#include "fractol.h"
#include "libft/libft.h"

void	ft_error(char *er)
{
	ft_putstr("ERROR: ");
	ft_putstr(er);
	ft_putstr("!\n");
	exit(1);
}

int		ft_key_hook(int keykode, t_mlx *mlx)
{
	if (keykode == KEY_LINUX)
		exit(1);
	if (keykode == 65363)
		mlx->img.move_x += 0.02;
	if (keykode == 65361)
		mlx->img.move_x -= 0.02;
	if (keykode == 65362)
		mlx->img.move_y -= 0.02;
	if (keykode == 65364)
		mlx->img.move_y += 0.02;
	if (keykode == 65451)
		mlx->img.zoom *= mlx->img.zoom;
	if (keykode == 65453)
		mlx->img.zoom = sqrt(mlx->img.zoom);
	//printf("%d\n", keykode);
	ft_expose_img(mlx);
//	param++;
	return (0);
}

int ft_mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == 1)
		mlx->img.zoom += 1;
	else if (button == 3)
		mlx->img.zoom += -1;
	// mlx->img.move_x += 0.003;
	// mlx->img.move_y += 0.003;
	x++;
	y++;
	ft_expose_img(mlx);
	return (0);
}

int	ft_expose_img(t_mlx *mlx)
{
	if (mlx->img.fr == 1)
		ft_mandelbrot_draw(&mlx->img);
	else if (mlx->img.fr == 2)
		ft_draw_julia(&mlx->img);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0 ,0);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx mlx;

	ac++;
	ac--;
	ft_init_mlx(&mlx);
	mlx.img.fr = ft_select_fractol(av);
	mlx_mouse_hook(mlx.win_ptr, ft_mouse_hook, &mlx);
	mlx_expose_hook(mlx.win_ptr, ft_expose_img, &mlx);
	mlx_key_hook(mlx.win_ptr, ft_key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
