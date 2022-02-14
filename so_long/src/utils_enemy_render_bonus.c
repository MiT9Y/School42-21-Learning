/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy_render_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 10:44:23 by msimon            #+#    #+#             */
/*   Updated: 2021/07/31 17:41:30 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ch_catch_player(t_so_long *sl, t_enemy *e)
{
	int	pl_c_x;
	int	pl_c_y;
	int	e_c_x;
	int	e_c_y;

	pl_c_x = sl->player.x + BLOCK_SIZE / 2;
	pl_c_y = sl->player.y + BLOCK_SIZE / 2;
	e_c_x = e->x + BLOCK_SIZE / 2;
	e_c_y = e->y + BLOCK_SIZE / 2;
	if (pl_c_x >= e_c_x - BLOCK_SIZE / 2 && pl_c_x <= e_c_x + BLOCK_SIZE / 2
		&& pl_c_y >= e_c_y - BLOCK_SIZE / 2 && pl_c_y <= e_c_y + BLOCK_SIZE / 2)
		sl->map.end_game = 2;
}

static char	ch_new_pos(t_so_long *sl, int x, int y)
{	
	if (sl->map.data[y / BLOCK_SIZE][x / BLOCK_SIZE] == '1')
		return (1);
	return (0);
}

static void	move_enemy(t_enemy *e, char fl_dir, int y)
{
	if (!fl_dir)
	{
		e->y = y;
		e->pos++;
		if (e->pos == 4)
			e->pos = 0;
	}
	else
	{
		e->dir_move *= -1;
		if (e->vector)
			e->vector = 0;
		else
			e->vector = 1;
		e->pos = 0;
	}
}

void	render_enemys(t_so_long *sl)
{
	int		c;
	int		y;
	t_enemy	*e;

	c = -1;
	while (++c < sl->enemys.count)
	{
		e = &(sl->enemys.enemy[c]);
		y = e->y + (e->dir_move * MOVE_SIZE);
		if (!ch_new_pos(sl, e->x, y)
			&& !ch_new_pos(sl, e->x + BLOCK_SIZE - 1, y)
			&& !ch_new_pos(sl, e->x, y + BLOCK_SIZE - 1)
			&& !ch_new_pos(sl, e->x + BLOCK_SIZE - 1, y + BLOCK_SIZE - 1))
			move_enemy(e, 0, y);
		else
			move_enemy(e, 1, y);
		mlx_put_image_to_window(sl->scr.mlx, sl->scr.win,
			sl->enemys.sprites[(int)e->vector][(int)e->pos],
			e->x - sl->map.d_x, e->y - sl->map.d_y);
		ch_catch_player(sl, e);
	}
}
