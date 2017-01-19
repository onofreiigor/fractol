/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:15:17 by ionofrei          #+#    #+#             */
/*   Updated: 2016/12/03 14:22:46 by ionofrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void	ft_error(char *er)
{
	printf("%s error\n", er);
	exit (1);
}

 int	ft_printf_key(int keykode, void *param)
 {
 	//printf("key kode %d\n", keykode);
 	if (keykode == KEY_LINUX)
 		exit (1);

 	param++;
 	param--;
 	return (0);
 }

int ft_mouse(int key, int x, int y, void *param)
{
	//printf("mouse key: %d x = %d y = %d\n", key, x, y);
	if (key == 53 && x == 0 && y == 0)
		exit (1);
	param++;
	param--;
	return (0);
}

t_seg *ft_draw_square()
{
	t_seg *square;

	square = ft_new_seg(50, 50, 0, 100, 50, 0);

	return (square);
}

int	main()
{
	void *mlx_ptr;
	void *win_ptr;
	t_seg *segment;
	//double t = 4.5;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 500, "Hello MLX");

	segment = ft_draw_square();
	ft_print_seg(mlx_ptr, win_ptr, segment);
	segment = ft_rotate_xy(segment);
	ft_print_seg(mlx_ptr, win_ptr, segment);

	mlx_key_hook(win_ptr, ft_printf_key, 0);
	mlx_mouse_hook(win_ptr, ft_mouse, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
