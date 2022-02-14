/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:27:57 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 07:42:09 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	change_pos(t_main_data *md, t_pfpoint pos, t_fpoint d, char f)
{
	float	wall;

	if (f)
		wall = 0.5;
	else
		wall = WALL;
	if (point_check(*(pos.x) + d.x, *(pos.y) + d.y, md, wall))
	{
		*(pos.x) += d.x;
		*(pos.y) += d.y;
		return (1);
	}
	else if (point_check(*(pos.x) + d.x, *(pos.y), md, wall) && !f)
	{
		*(pos.x) += d.x;
		return (1);
	}
	else if (point_check(*(pos.x), *(pos.y) + d.y, md, wall) && !f)
	{
		*(pos.y) += d.y;
		return (1);
	}
	return (0);
}

static void	sp_move_pos(t_main_data *md, int i)
{
	if (md->sprs[i]->count > md->sprs[i]->cframe)
	{
		md->sprs[i]->n_sp++;
		if (md->sprs[i]->n_sp == arr_len((void **)md->sprs[i]->texs))
			md->sprs[i]->n_sp = 0;
		md->sprs[i]->count = 0;
	}
	else
		md->sprs[i]->count++;
}

static void	sp_move(t_main_data *md)
{
	int			i;
	t_pfpoint	pos;

	i = -1;
	while (md->sprs[++i])
	{
		sp_move_pos(md, i);
		if (md->sprs[i]->fix)
		{
			pos.x = &(md->sprs[i]->x);
			pos.y = &(md->sprs[i]->y);
			if (!change_pos(md, pos, (t_fpoint){md->sprs[i]->dx * SP_SPEED,
					md->sprs[i]->dy * SP_SPEED}, 1))
			{
				md->sprs[i]->dx *= -1;
				md->sprs[i]->dy *= -1;
			}
		}
	}
}

void	other_move(t_main_data *md)
{
	int	i;

	i = -1;
	while (md->doors[++i])
	{
		if (md->doors[i]->open == 1 && md->doors[i]->pos < 1.0)
		{
			md->doors[i]->pos += DO_SPEED;
			if (md->doors[i]->pos > 1.0)
				md->doors[i]->pos = 1.0;
		}
		if (md->doors[i]->open == 0 && md->doors[i]->pos > 0.0)
		{
			md->doors[i]->pos -= DO_SPEED;
			if (md->doors[i]->pos < 0.0)
				md->doors[i]->pos = 0.0;
		}
	}
	sp_move(md);
	init_sprites(md);
}
