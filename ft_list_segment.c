#include "fractol.h"
#include "libft/libft.h"

t_seg *ft_new_seg(int x1, int y1, int z1, int x2, int y2, int z2)
{
	t_seg *new;

	new = (t_seg*)malloc(sizeof(t_seg));
	new->x1 = x1;
	new->y1 = y1;
	new->z1 = z1;
	new->x2 = x2;
	new->y2 = y2;
	new->z2 = z2;
	new->next = NULL;
	return (new);
}

void	ft_add_seg(t_seg *seg, int x1, int y1, int z1, int x2, int y2, int z2)
{
	t_seg *tmp;

	tmp = seg;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_new_seg(x1, y1, z1, x2, y2, z2);
}

void	ft_print_seg(void *mlx_ptr, void *win_ptr, t_seg *seg)
{
	t_seg *tmp;

	tmp = seg;
	while (tmp != NULL)
	{
		printf("(%d,%d,%d) - (%d,%d,%d)\n", tmp->x1, tmp->y1, tmp->z1, 
			tmp->x2, tmp->y2, tmp->z2);
		ft_line(mlx_ptr, win_ptr, tmp->x1, tmp->y1, tmp->x2, tmp->y2);
		tmp = tmp->next;
	}
}

t_seg	*ft_to_seg(int **ar)
{
	t_seg *seg;
	int i;
	int j;

	i = 1;
	j = 0;
	seg = ft_new_seg(j, i - 1, ar[i][j], j + 1, i - 1, ar[i][j + 1]);
	while (i < ar[0][0])
	{
		while (j < ar[0][1] - 1)
		{
			if (i == ar[0][0] - 1)
				ft_add_seg(seg, j, i - 1, ar[i][j], j + 1, i - 1, ar[i][j + 1]);
			else if (j == ar[0][1] - 1)
				ft_add_seg(seg, j, i - 1, ar[i][j], j, i, ar[i + 1][j]);
			else
			{
				ft_add_seg(seg, j, i - 1, ar[i][j], j + 1, i - 1, ar[i][j + 1]);
				ft_add_seg(seg, j, i - 1, ar[i][j], j, i, ar[i + 1][j]);
			}
			//printf("x: %d, y: %d, z: %d\n", tmp->x, tmp->y, tmp->z);
			j++;
		}
		j = 0;
		i++;
	}
	//printf("x1: %d y1: %d x2: %d y2: %d\n", seg->x1, seg->y1, seg->x2, seg->y2);
	return (seg);
}