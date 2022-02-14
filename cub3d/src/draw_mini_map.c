/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:46:20 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 07:05:18 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	clean_mini_map(t_image img)
{
	int	x;
	int	y;

	y = -1;
	while (++y < img.h)
	{
		x = -1;
		while (++x < img.w)
			img.pimg[y * img.w + x] = 0x80FFFFFF;
	}
}

static void
	init_draw_wall(t_main_data *md, t_ipoint *p_b, t_ipoint *p_e, t_ipoint *p)
{
	p_b->x = (int)((md->player.posx - 3.5) * 30);
	p_b->y = (int)((md->player.posy - 3.5) * 30);
	p_e->x = (int)((md->player.posx + 3.5) * 30);
	p_e->y = (int)((md->player.posy + 3.5) * 30);
	p->y = p_b->y - 1;
}

static void	draw_wall(t_main_data *md)
{
	t_ipoint	p_b;
	t_ipoint	p_e;
	t_ipoint	p_m;
	t_ipoint	p;

	init_draw_wall(md, &p_b, &p_e, &p);
	while (++p.y < p_e.y)
	{
		p.x = p_b.x - 1;
		while (++p.x < p_e.x)
		{
			p_m.x = p.x / 30;
			p_m.y = p.y / 30;
			if (p_m.x >= 0 && p_m.x < md->map.w && p_m.y >= 0
				&& p_m.y < md->map.h && p.x >= 0 && p.y >= 0)
			{
				if (md->map.el[p_m.y * md->map.w + p_m.x].type == '1')
					draw_pixel(md->mini_map, p.x - p_b.x,
						p.y - p_b.y, 0x70808080);
				else if (md->map.el[p_m.y * md->map.w + p_m.x].type != '0')
					draw_pixel(md->mini_map, p.x - p_b.x,
						p.y - p_b.y, 0x7020B2AA);
			}
		}
	}
}

static void	draw_sp(t_main_data *md)
{
	int			i;
	t_fpoint	sp;
	t_fpoint	pl_b;
	t_fpoint	pl_e;
	t_ipoint	p;

	i = -1;
	while (md->sprs[++i])
	{
		sp.x = md->sprs[i]->x;
		sp.y = md->sprs[i]->y;
		pl_b.x = md->player.posx - 4.0;
		pl_b.y = md->player.posy - 4.0;
		pl_e.x = md->player.posx + 4.0;
		pl_e.y = md->player.posy + 4.0;
		if (sp.x >= pl_b.x && sp.x < pl_e.x && sp.y >= pl_b.y && sp.y < pl_e.y)
		{
			p.x = (int)((sp.x - pl_b.x) * 30) - 15;
			p.y = (int)((sp.y - pl_b.y) * 30) - 15;
			draw_rhomb(md->mini_map, p, 13, 0x206A5ACD);
		}
	}
}

void	draw_mini_map(t_main_data *md)
{
	int		x;
	int		y;
	float	a;

	clean_mini_map(md->mini_map);
	draw_wall(md);
	draw_sp(md);
	y = -1;
	while (++y < 210)
	{
		x = -1;
		while (++x < 210)
		{
			a = atan2f((float)(y - 105), (float)(x - 105));
			if (a < 0.0)
				a = -1 * a;
			else
				a = 2 * PI - a;
			a = angle_math(a - md->player.posa);
			if (a > (2 * PI) - (FOV * PI / 360) || a < FOV * PI / 360)
				draw_pixel(md->mini_map, x, y, 0xB0FFD700);
		}
	}
	draw_rhomb(md->mini_map, (t_ipoint){105, 105}, 13, 0xFFD700);
	draw_img(md->scr.buf, md->mini_map, 5, 5);
}
