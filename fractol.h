#ifndef __FRACTOL_H
# define __FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# define KEY_MAC 53
# define KEY_LINUX 65307
# define W_MAX 1920
# define H_MAX 1080
# define W 1200
# define H 600

typedef struct s_img
{
	char *addr;
	int bpp;
	int size_line;
	int endian;
	double zoom;
	double move_x;
	double move_y;
	int fr;
}			t_img;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	t_img img;
}	t_mlx;

typedef struct s_color
{
	int r;
	int g;
	int b;
}	t_color;

typedef struct s_hsv
{
	int h;
	int s;
	int v;
}	t_hsv;

void ft_draw_julia(t_img *img);
void ft_img_pixel_put(t_img *img, int x, int y, int color);
int	ft_expose_img(t_mlx *mlx);
void	ft_error(char *er);
int ft_rgb_to_int(t_color c);
t_color		ft_calc_rgb(t_hsv hsv);
t_hsv		ft_calc_hsv(int r, int g, int b);
void ft_draw(t_img *img);
void	ft_mandelbrot_draw(t_img *img);
void ft_img_pixel_put(t_img *img, int x, int y, int color);
int ft_select_fractol(char **av);
void	ft_init_mlx(t_mlx *mlx);

#endif