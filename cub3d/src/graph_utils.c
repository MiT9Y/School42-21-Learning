/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:42:02 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 07:24:30 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_argb
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_argb;

static t_argb	get_argb(int color)
{
	t_argb	res;

	res.a = (color & 0xFF000000) >> 24;
	res.r = (color & 0x00FF0000) >> 16;
	res.g = (color & 0x0000FF00) >> 8;
	res.b = (color & 0x000000FF);
	return (res);
}

int	merge_pixel(int down, int up)
{
	t_argb	d;
	t_argb	u;
	t_argb	r;

	u.a = (up & 0xFF000000) >> 24;
	if (u.a == 0)
		return (up);
	else if (u.a == 255)
		return (down);
	else
	{
		d = get_argb(down);
		u = get_argb(up);
		r.a = (d.a * u.a) / 255;
		r.r = (u.r * (255 - u.a) + d.r * (u.a - r.a)) / (255 - r.a);
		r.g = (u.g * (255 - u.a) + d.g * (u.a - r.a)) / (255 - r.a);
		r.b = (u.b * (255 - u.a) + d.b * (u.a - r.a)) / (255 - r.a);
		return (r.a << 24 | r.r << 16 | r.g << 8 | r.b);
	}
}

void	draw_img(t_image dst, t_image src, int xz, int yz)
{
	int	x;
	int	y;

	y = -1;
	while (++y < src.h)
	{
		x = -1;
		while (++x < src.w)
			dst.pimg[(y + yz) * dst.w + x + xz] = merge_pixel
				(dst.pimg[(y + yz) * dst.w + x + xz], src.pimg[y * src.w + x]);
	}
}

void	draw_pixel(t_image dst, int x, int y, int color)
{
	if (x >= 0 && x < dst.w && y >= 0 && y < dst.h)
		dst.pimg[y * dst.w + x] = merge_pixel(dst.pimg[y * dst.w + x], color);
}
