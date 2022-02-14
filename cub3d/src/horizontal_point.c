/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:45:46 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/12/05 07:27:16 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_door_horizontal(t_mappoint *res, int sign, t_map map)
{
	float	pos;
	t_door	*door;
	int		index;

	pos = res->x - (int)res->x;
	index = (int)(res->y + 0.0001 * sign) * map.w + (int)res->x;
	if (map.el[index].type == '1')
	{
		res->ok = 1;
		res->type = map.el[index].type;
		res->data = map.el[index].data;
		return ;
	}
	door = (t_door *)(map.el[index].data);
	if (pos <= (1 - door->pos))
	{
		res->ok = 1;
		res->type = map.el[index].type;
		res->data = map.el[index].data;
		return ;
	}
	else
		res->ok = 0;
}

static t_mappoint	get_horizontal_first_point(float angle,
		int *sign, t_player player)
{
	t_mappoint	res;

	if (angle < PI)
	{
		*sign = -1;
		res.y = (int) player.posy;
	}
	else
	{
		*sign = 1;
		res.y = (int) player.posy + 1;
	}
	res.x = player.posx + (player.posy - res.y) / tan(angle);
	return (res);
}

static void	finding_horizontal_point(t_mappoint *res,
		float angle, int sign, t_map map)
{
	float	y;
	float	x;

	while (res->y < map.h && res->y > -0.0001)
	{
		y = res->y + sign;
		x = res->x - sign * 1 / tan(angle);
		if (x > map.w || x < -0.0001 || y >= map.h || y < -0.0001)
			return ;
		else
		{
			res->y = y;
			res->x = x;
		}
		if (map.el[(int)(res->y + 0.0001 * sign) * map.w
			+ (int)res->x].type != '0')
		{
			check_door_horizontal(res, sign, map);
			if (res->ok == 1)
				return ;
		}
	}
}

t_mappoint	get_horizontal_point(t_player player, float angle, t_map map)
{
	t_mappoint	res;
	int			sign;

	res = get_horizontal_first_point(angle, &sign, player);
	if (res.x >= map.w || res.x < -0.0001 || res.y >= map.h || res.y < -0.0001)
	{
		res.ok = 0;
		return (res);
	}
	if (map.el[(int)(res.y + 0.0001 * sign) *map.w
		+ (int)res.x].type != '0')
	{
		check_door_horizontal(&res, sign, map);
		if (res.ok == 1)
			return (res);
	}
	res.ok = 0;
	finding_horizontal_point(&res, angle, sign, map);
	return (res);
}
