/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:04:17 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 08:31:20 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	angle_math(float angle)
{
	if (angle >= 0 && angle < 2 * PI)
		return (angle);
	else if (angle < 0)
		return ((float)(2 * PI) + angle);
	else
		return (angle - (float)(2 * PI));
}

float	get_distance(t_mappoint p, t_player player, double angle)
{
	float	res;

	if (p.ok == 1)
		res = sqrt((p.x - player.posx) * (p.x - player.posx)
				+ (p.y - player.posy) * (p.y - player.posy)) * cos(angle);
	else
		res = -1;
	return (res);
}

void	choose_img(t_mappoint p, t_src_render *res, float now_angle)
{
	t_wall	*wall;

	if (p.type == '1')
	{
		wall = (t_wall *)p.data;
		if (res->type == 'h')
		{
			if (now_angle < PI)
				res->img = &(wall->n);
			else
				res->img = &(wall->s);
		}
		else
		{
			if (now_angle < PI / 2 || now_angle > 3 * PI / 2)
				res->img = &(wall->e);
			else
				res->img = &(wall->w);
		}
	}
	else
		res->img = ((t_door *)p.data)->img;
}

float	count_pos(t_src_render *res, t_points points, float now_angle)
{
	if (res->type == 'h')
	{
		if (points.hor.type == '1')
		{
			if (now_angle < PI)
				return (points.hor.x - (int) points.hor.x);
			return (1 - (points.hor.x - (int) points.hor.x));
		}
		return (points.hor.x - (int) points.hor.x
			+ ((t_door *)points.hor.data)->pos);
	}
	else
	{
		if (points.ver.type == '1')
		{
			if (now_angle < PI / 2 || now_angle > 3 * PI / 2)
				return (points.ver.y - (int) points.ver.y);
			return (1 - (points.ver.y - (int) points.ver.y));
		}
		else
			return (points.ver.y - (int) points.ver.y
				+ ((t_door *)points.ver.data)->pos);
	}
}

void	check_type(t_src_render *res, t_dist dist)
{
	if (dist.hor_dist == -1)
		res->type = 'v';
	else if (dist.ver_dist == -1)
		res->type = 'h';
	else if (dist.hor_dist > dist.ver_dist)
		res->type = 'v';
	else
		res->type = 'h';
}
