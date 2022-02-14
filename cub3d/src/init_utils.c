/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:50:35 by msimon            #+#    #+#             */
/*   Updated: 2021/12/02 13:14:11 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_hook(t_main_data *md)
{
	mlx_hook(md->scr.win, 2, 1L << 0, key_press, md);
	mlx_hook(md->scr.win, 3, 1L << 1, key_release, md);
	mlx_hook(md->scr.win, 6, 1L << 6, mouse_move, md);
	mlx_hook(md->scr.win, 17, 1L << 0, close_app, md);
}

static void	init_md_var(t_main_data *md)
{
	md->pl_move.ud_move = 0.0;
	md->pl_move.lr_move = 0.0;
	md->pl_move.rt_move = 0.0;
	md->pl_move.x_mouse = -99999999;
	md->pl_move.event_f = 0;
	md->bg.flg_init = 0;
	md->wall.n.src = NULL;
	md->wall.e.src = NULL;
	md->wall.w.src = NULL;
	md->wall.s.src = NULL;
	md->door_tex_arr = NULL;
	md->sp_tex_arr = NULL;
	init_arr((void ***)&(md->doors));
	init_arr((void ***)&(md->sprs));
	md->player.posa = -1.0;
	md->scr.counter = CFRAME;
	md->scale = ((float)WIDTH / (2 * tan(FOV * PI / 360)));
}

static void	init_mini_map(t_main_data *md)
{
	md->mini_map.src = mlx_new_image(md->scr.mlx, 210, 210);
	if (!md->mini_map.src)
		prt_error(ERR_MEM, 0);
	md->mini_map.w = 210;
	md->mini_map.h = 210;
	md->mini_map.pimg = (int *)mlx_get_data_addr(md->mini_map.src,
			&(md->mini_map.bpp), &(md->mini_map.sl), &(md->mini_map.end));
	if (!md->mini_map.pimg)
		prt_error(ERR_MEM, 0);
}

void	init_md(t_main_data *md)
{
	md->scr.mlx = mlx_init();
	if (!md->scr.mlx)
		prt_error(ERR_MEM, 0);
	md->scr.win = mlx_new_window(md->scr.mlx, WIDTH, HEIGHT, "Cub3D");
	if (!md->scr.win)
		prt_error(ERR_MEM, 0);
	md->scr.buf.src = mlx_new_image(md->scr.mlx, WIDTH, HEIGHT);
	if (!md->scr.buf.src)
		prt_error(ERR_MEM, 0);
	md->scr.buf.w = WIDTH;
	md->scr.buf.h = HEIGHT;
	md->scr.buf.pimg = (int *)mlx_get_data_addr(md->scr.buf.src,
			&(md->scr.buf.bpp), &(md->scr.buf.sl), &(md->scr.buf.end));
	if (!md->scr.buf.pimg)
		prt_error(ERR_MEM, 0);
	init_md_var(md);
	init_mini_map(md);
}
