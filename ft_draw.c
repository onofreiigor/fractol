#include "fractol.h"
#include "libft/libft.h"

void ft_img_pixel_put(t_img *img, int x, int y, int color)
{
	int pixel;

	pixel = y * img->size_line + x * 4;
	// img->addr[pixel] = 0;
	// img->addr[pixel + 1] = (color>>16) & 0x00;
	// img->addr[pixel + 2] = (color>>8) & 0xFF;
	// img->addr[pixel + 3] = color & 0xFF;
	*(int*)(img->addr + pixel) = color;
}