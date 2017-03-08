#include "fractol.h"
#include "libft/libft.h"

void ft_all_fractol(void)
{
	ft_putstr("Name fractol:\n");
	ft_putstr("Julia = J\n");
	ft_putstr("Molbernot = M\n");
	ft_putstr("Xfr = X\n");
	exit(1);
}

int ft_select_fractol(char **av)
{
	if (ft_strcmp(av[1], "J"))
		return (1);
	else if (ft_strcmp(av[1], "M"))
		return (2);
	else if (ft_strcmp(av[1], "X"))
		return (3);
	return (0);
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W, H, "Fractal");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, W, H);
	mlx->img.addr = mlx_get_data_addr(mlx->img_ptr, &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
}