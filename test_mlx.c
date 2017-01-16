// gcc test_mlx.c  -L.. -lmlx -L/usr/include/../lib -lXext -lX11 -lm

#include <stdio.h>
#include <mlx.h>

int main()
{
	void *mlx_ptr;
	void *mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "Hello");
	mlx_pixel_put(mlx_ptr, mlx_win, 100, 100, 0x0FFFFFF);
	printf("Start mlx:\n");
	while (1)
	{
		if (getchar() == 'A')
			return (0);
	}
	return (0);
}