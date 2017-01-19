#include "fractol.h"
#include "libft/libft.h"

t_seg *ft_rotate_xy(t_seg *seg)
{
	t_seg *tmp;
	int x1;
	int y1;
	int x2;
	int y2;

	tmp = seg;
	while (tmp != NULL)
	{
		x1 = tmp->x1;
		y1 = tmp->y1;
		x2 = tmp->x2;
		y2 = tmp->y2;
		
		x1 = round(tmp->x1 * cos(AL) + tmp->y1 * sin(AL) + tmp->x1 - tmp->x1 * cos(AL) + tmp->y1 * sin(AL));
		y1 = round(tmp->x1 * sin(AL) + tmp->y1 * cos(AL) - tmp->y1 - tmp->x1 * sin(AL) - tmp->y1 * cos(AL));

		x2 = round(tmp->x2 * cos(AL) - tmp->y2 * sin(AL) + tmp->x1 - tmp->x1 * cos(AL) + tmp->y1 * sin(AL));
		y2 = round(tmp->x2 * sin(AL) + tmp->y2 * cos(AL) - tmp->y1 - tmp->x1 * sin(AL) - tmp->y1 * cos(AL));
		
		tmp->x1 = x1;
		tmp->y1 = y1;
		tmp->x2 = x2;
		tmp->y2 = y2;
		tmp = tmp->next;
	}
	return (seg);
}

/* Rotirea in jurul unui punc F(x,y).

x' = x*cos(al) - y*sin(al) + xf - xf*cos(al) + yf*sin(al);
y' = x*sin(al) + y*cos(al) + yf - xf*sin(al) - yf*cos(al);

*/
