/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 05:51:58 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 08:08:59 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_src_arr
{
	t_image	*img;
	int		x_img;
	float	step;
	int		yb;
	int		ye;
}	t_src_arr;

static int	get_next_el(t_src_render **arr, float *min)
{
	float	dist;
	int		i;
	int		res;

	if (!arr)
		return (-1);
	dist = MAXFLOAT;
	res = -1;
	i = -1;
	while (arr[++i])
	{
		if (arr[i]->dist < dist && arr[i]->dist > *min)
		{
			dist = arr[i]->dist;
			res = i;
		}
	}
	*min = dist;
	return (res);
}

static void	init_src_el(t_src_arr ***src, t_src_render *el)
{
	int	i;

	i = add_arr_el((void ***)src, sizeof(t_src_arr));
	(*src)[i]->img = el->img;
	(*src)[i]->x_img = (int)(el->pos * el->img->w);
	if ((*src)[i]->x_img < 0)
		(*src)[i]->x_img = 0;
	else if (!((*src)[i]->x_img < el->img->w))
		(*src)[i]->x_img = el->img->w - 1;
	if (el->size < 2.0)
	{
		(*src)[i]->yb = -1;
		(*src)[i]->ye = -1;
	}
	else
	{
		(*src)[i]->yb = (int)lroundf((HEIGHT - el->size) / 2);
		(*src)[i]->ye = HEIGHT - (*src)[i]->yb;
		(*src)[i]->step = (el->img->h - 0.001) / (HEIGHT - ((*src)[i]->yb * 2));
	}
}

static void	init_src_arr(t_src_arr ***src, t_src_render **arr)
{
	float	dist;
	int		i;

	dist = -1;
	i = get_next_el(arr, &dist);
	while (!(i < 0))
	{
		init_src_el(src, arr[i]);
		i = get_next_el(arr, &dist);
	}
	drop_arr((void **)arr);
}

static unsigned int	get_pixel_color(t_src_arr *el, int y, int bg)
{
	int	a;
	int	b;

	a = (int)((y - el->yb) * el->step);
	b = el->x_img;
	return (merge_pixel(el->img->pimg[a * el->img->w + b], bg));
}

void	ray_render(t_main_data *md, int x, t_src_render **arr)
{
	int				i;
	int				y;
	unsigned int	bg;
	t_src_arr		**src;

	y = -1;
	src = NULL;
	init_src_arr(&src, arr);
	while (++y < HEIGHT)
	{
		bg = 0xFF000000;
		i = -1;
		while (src[++i])
		{
			if (src[i]->yb > y || y >= src[i]->ye)
				break ;
			bg = get_pixel_color(src[i], y, bg);
			if (!(bg & 0xFF000000))
				break ;
		}
		if (bg != 0xFF000000)
			md->scr.buf.pimg[y * md->scr.buf.w + x] = (int)bg;
	}
	drop_arr((void **)src);
}
