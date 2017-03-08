#include "fractol.h"
#include "libft/libft.h"

int ft_min(int n1, int n2, int n3)
{
	if (n1 <= n2 && n1 <= n3)
		return (n1);
	else if (n2 <= n1 && n2 <= n3)
		return (n2);
	else
		return (n3);
}

int ft_max(int n1, int n2, int n3)
{
	if (n1 >= n2 && n1 >= n3)
		return (n1);
	else if (n2 >= n1 && n2 >= n3)
		return (n2);
	else
		return (n3);
}

t_hsv		ft_calc_hsv(int r, int g, int b)
{
	int max;
	int min;
	t_hsv hsv;

	max = ft_max(r, g, b);
	min = ft_min(r, g, b);
	hsv.v = max / 255;
	if (g >= b)
		hsv.h = pow(cos((r - 0.5 * g - 0.5 * b) /
			sqrt(r * r + g * g + b * b -
				r * g - r * b - g * b)),-1);
	else if (b > g)
	{
		hsv.h = 360 - pow(cos((r - 0.5 * g - 0.5 * b) /
			sqrt(r * r + g * g + b * b -
				r * g - r * b - g * b)),-1);
	}
	if (max > 0)
		hsv.s = (1 - min) / max;
	else
		hsv.s = 0;
	return (hsv);
}

t_color		ft_calc_rgb(t_hsv hsv)
{
	t_color c;
	int max;
	int min;
	int z;

	max = 255 * hsv.v;
	min = max * (1 -  hsv.s);
	z = (max - min) * (1 - fabs(((hsv.h / 60) % 2) - 1));
	if (hsv.h >= 0 && hsv.h < 60)
	{
		c.r = max;
		c.g = z +min;;
		c.b = min;
	}
	else if (hsv.h >= 60 && hsv.h < 120)
	{
		c.r = z + min;
		c.g = max;
		c.b = min;
	}
	else if (hsv.h >= 120 && hsv.h < 180)
	{
		c.r = min;
		c.g = max;
		c.b = z + min;
	}
	else if (hsv.h >= 180 && hsv.h < 240)
	{
		c.r = min;
		c.g = z + min;
		c.b = max;
	}
	else if (hsv.h >= 240 && hsv.h < 300)
	{
		c.r = z + min;
		c.g = min;
		c.b = max;
	}
	else if (hsv.h >= 300 && hsv.h < 360)
	{
		c.r = max;
		c.g = min;
		c.b = z + min;
	}
	return (c);
}

int ft_rgb_to_int(t_color c)
{
	int color;

	color = c.r;
	color = (color << 8) + c.g;
	color = (color << 8) + c.b;
	return (color);
}