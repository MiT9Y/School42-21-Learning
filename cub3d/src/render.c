/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:25:46 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 08:09:57 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	render_frame(t_main_data *md, t_src_render ***ra)
{
	int	x;
	int	bg_p;

	x = -1;
	bg_p = (HEIGHT / 2) * WIDTH;
	while (++x < bg_p)
		md->scr.buf.pimg[x] = md->bg.ceil;
	x--;
	bg_p = HEIGHT * WIDTH;
	while (++x < bg_p)
		md->scr.buf.pimg[x] = md->bg.floor;
	x = -1;
	while (++x < WIDTH)
	{
		ray_render(md, x, ra[x]);
	}
	free(ra);
}

int	render_next_frame(t_main_data *md)
{
	if (!(md->pl_move.m_counter < 0))
	{
		if (!md->pl_move.m_counter)
			md->pl_move.rt_move = 0.0;
		md->pl_move.m_counter--;
	}
	if (md->scr.counter == CFRAME)
	{
		player_move(md);
		other_move(md);
		render_frame(md, make_arr_ray(md));
		draw_mini_map(md);
		mlx_put_image_to_window
			(md->scr.mlx, md->scr.win, md->scr.buf.src, 0, 0);
	}
	else
		md->scr.counter++;
	return (0);
}
