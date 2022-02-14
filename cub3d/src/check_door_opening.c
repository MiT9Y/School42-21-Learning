/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_opening.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:05:29 by msimon            #+#    #+#             */
/*   Updated: 2021/12/04 13:27:34 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static float	difference(float a, float b)
{
	if (b > a)
		return (b - a);
	else
		return (a - b);
}

static int	check_hor_door_near(t_door *door,
		float posa, float posx, float posy)
{
	if (difference(door->x + 0.5, posx) > 0.7)
		return (0);
	if (posa > PI / 3 && posa < 2 * PI / 3)
	{
		if (difference(posy, (float)(door->y + 1)) < WALL)
			return (0);
		if ((posy - (door->y + 1)) < 1.7 && (posy - (door->y + 1)) > 0)
			return (1);
	}
	else if (posa > 4 * PI / 3 && posa < 5 * PI / 3)
	{
		if (difference(posy, (float)door->y) < WALL)
			return (0);
		if ((door->y - posy) < 1.7 && (door->y - posy) > 0)
			return (1);
	}
	return (0);
}

static int	check_ver_door_near(t_door *door,
		float posa, float posx, float posy)
{
	if (difference(posy, door->y + 0.5) > 0.7)
		return (0);
	if (posa < PI / 3 || posa > 5 * PI / 3)
	{
		if (difference(posx, (float)door->x) < WALL)
			return (0);
		if ((door->x - posx) < 1.7 && (door->x - posx) > 0)
			return (1);
	}
	else if (posa > 2 * PI / 3 && posa < 4 * PI / 3)
	{
		if (difference(posx, (float)(door->x + 1)) < WALL)
			return (0);
		if ((posx - (door->x + 1)) < 1.7 && (posx - (door->x + 1)) > 0)
			return (1);
	}
	return (0);
}

int	check_door_near_player(t_main_data *md, t_door *door)
{
	if (door->dir == 0)
		return (check_hor_door_near(door, md->player.posa, md->player.posx,
				md->player.posy));
	else
		return (check_ver_door_near(door, md->player.posa, md->player.posx,
				md->player.posy));
}
