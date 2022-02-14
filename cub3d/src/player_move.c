/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:53:17 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 07:55:43 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_door(t_element_map cell)
{
	t_door	*door;

	if (cell.type == '1')
		return (1);
	if (cell.type == '0')
		return (0);
	door = (t_door *)(cell.data);
	if (door->open == 1 && door->pos == 1.0)
		return (0);
	else
		return (1);
}

int	point_check(float x, float y, t_main_data *md, float wall)
{
	if (y > md->map.h - wall || y < wall || x > md->map.w - wall || x < wall)
		return (0);
	if (check_door(md->map.el[((int)(y + wall)) * md->map.w + (int)(x + wall)]))
		return (0);
	if (check_door(md->map.el[((int)(y - wall)) * md->map.w + (int)(x + wall)]))
		return (0);
	if (check_door(md->map.el[((int)(y + wall)) * md->map.w + (int)(x - wall)]))
		return (0);
	if (check_door(md->map.el[((int)(y - wall)) * md->map.w + (int)(x - wall)]))
		return (0);
	return (1);
}

static void	open_door(t_main_data *md)
{
	int	i;

	if (md->pl_move.event_f)
	{
		i = -1;
		while (md->doors[++i])
		{
			if (check_door_near_player(md, md->doors[i]))
			{
				if (!md->doors[i]->open && md->doors[i]->pos == 0.0)
					md->doors[i]->open = 1;
				if (md->doors[i]->open && md->doors[i]->pos == 1.0)
					md->doors[i]->open = 0;
			}
		}
	}
}

void	player_move(t_main_data *md)
{
	float		dx;
	float		dy;
	t_pfpoint	pos;

	md->player.posa += md->pl_move.rt_move;
	if (md->player.posa < 0)
		md->player.posa += (2 * PI);
	else if (md->player.posa > 2 * PI)
		md->player.posa -= (2 * PI);
	dx = cosf(md->player.posa) * md->pl_move.ud_move
		+ cosf(md->player.posa + PI / 2) * md->pl_move.lr_move;
	dy = -1 * (sinf(md->player.posa) * md->pl_move.ud_move)
		- sinf(md->player.posa + PI / 2) * md->pl_move.lr_move;
	pos.x = &(md->player.posx);
	pos.y = &(md->player.posy);
	change_pos(md, pos, (t_fpoint){dx, dy}, 0);
	open_door(md);
}
