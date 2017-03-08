#include "fractol.h"
#include "libft/libft.h"

void	ft_mandelbrot_draw(t_img *img)
{
	int h = 0, w = 0;
	double x = 0.0, y = 0.0;
	int max_iter = 100;
	double tmp = 0.0;
	int i = 0;
	while (w < W)
	{
		while (h < H)
		{
			while (x * x + y * y < 4 && i < max_iter)
			{
				tmp = x * x - y * y -2.5;
				y = 2 * x * y -1;
				x = tmp;
				i++;
			}
			h++;
		}
		printf("%d  ", i);
		ft_img_pixel_put(img, w, h, i);
		i = 0;
		w++;
	}
}