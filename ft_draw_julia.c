#include "fractol.h"
#include "libft/libft.h"

void ft_draw_julia(t_img *img)
{
	double c_re;
	double c_im;
	double new_re, new_im, old_re, old_im;
	int color;
	int test=0;
	int max_iter = 10;

	int x = 0;
	int y = 0;
	int i = 0;

	printf("Julia");
	c_re = -0.7;
	c_im = 0.27015;

	while (y < H)
	{
		while (x < W)
		{
			new_re = 1.5 * (x - W / 2) / (0.5 * img->zoom * W) + img->move_x;
			new_im = (y - H / 2) / (0.5 * img->zoom * H) + img->move_y;
			x++;
			i = 0;
			while (i < max_iter)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + c_re;
				new_im = 2 * old_re * old_im + c_im;
				if ((new_re * new_re + new_im * new_im) > 4)
					break ;
				color = i % 0xffffff;
				/*color = ft_rgb_to_int(ft_calc_rgb(
					ft_calc_hsv(i % 256, 255, 255 * (i < max_iter))));*/
				if (color > test)
				{
					test = color;
					//printf("test: %04x %d ", test, i);
				}
				/*color = ((i * (255/max_iter))<<16) | (((i * (255 / max_iter)))<<8) 
					|(((i * (255 / max_iter)) * (i < max_iter)));*/
				/*color = ((i * (256/max_iter)&0x0ff)<<16)|(((i * 255 / max_iter)&0x0ff)<<8) 
					|(((i * 255 / max_iter) * (i < max_iter))&0x0ff);*/
				//color = i * (y*255)/W+((((W-x)*255)/W)<<16)+(((y*255)/H)<<8);

				ft_img_pixel_put(img, x, y, color);
				i++;
			}
		}
		x = 0;
		y++;
	}
}