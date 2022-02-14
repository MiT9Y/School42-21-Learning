/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_player_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:47:03 by msimon            #+#    #+#             */
/*   Updated: 2021/08/03 19:35:13 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_base.h"

static void	init_local_var(int p_key, char *d_vc, int *d_x, int *d_y)
{
	*d_vc = -1;
	*d_x = 0;
	*d_y = 0;
	if (p_key == 124)//2
	{
		*d_x = MOVE_SIZE;
		*d_vc = 0;
	}
	else if (p_key == 125)//1
	{
		*d_y = MOVE_SIZE;
		*d_vc = 1;
	}
	else if (p_key == 123)//0
	{
		*d_x = -MOVE_SIZE;
		*d_vc = 2;
	}
	else if (p_key == 126)//13
	{
		*d_y = -MOVE_SIZE;
		*d_vc = 3;
	}
}

static char	ch_new_pos(t_map *map, int x, int y)
{	
	if (map->data[y / BLOCK_SIZE][x / BLOCK_SIZE] == 'C')
	{
		if (x % BLOCK_SIZE == 0 && y % BLOCK_SIZE == 0)
		{
			map->count_coll--;
			map->data[y / BLOCK_SIZE][x / BLOCK_SIZE] = '0';
			if (!map->count_coll)
				map->flag_exit = 1;
		}
	}
	if (map->data[y / BLOCK_SIZE][x / BLOCK_SIZE] == '1'
		|| (map->data[y / BLOCK_SIZE][x / BLOCK_SIZE] == 'E'
		&& !map->flag_exit))
		return (1);
	return (0);
}

static void	set_move(t_map *map, t_player *pl, int d_x, int d_y)
{
	int	x;
	int	y;

	x = pl->x + d_x;
	y = pl->y + d_y;
	if (map->data[y / BLOCK_SIZE][x / BLOCK_SIZE] == 'E'
		&& x % BLOCK_SIZE == 0 && y % BLOCK_SIZE == 0)
		map->end_game = 1;
	if (!ch_new_pos(map, x, y) && !ch_new_pos(map, x + BLOCK_SIZE - 1, y)
		&& !ch_new_pos(map, x, y + BLOCK_SIZE - 1)
		&& !ch_new_pos(map, x + BLOCK_SIZE - 1, y + BLOCK_SIZE - 1))
	{
		pl->count_move++;
		if (pl->count_move < 0)
			pr_error(ERR_INT_OVERFLOW, 0);
		printf("Movements: %d\n", pl->count_move);
		pl->x += d_x;
		pl->y += d_y;
	}
}

void	move_player(t_scr src, t_map *map, t_player *pl)
{
	char	d_vc;
	int		d_x;
	int		d_y;

	init_local_var(src.p_key, &d_vc, &d_x, &d_y);
	if (d_x || d_y)
		set_move(map, pl, d_x, d_y);
	if (d_vc > -1)
	{
		if (d_vc != pl->vector)
		{
			pl->vector = d_vc;
			pl->pos = 0;
		}
		else
		{
			pl->pos++;
			if (pl->pos == 4)
				pl->pos = 0;
		}
	}
}
