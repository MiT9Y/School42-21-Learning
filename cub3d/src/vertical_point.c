/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:46:46 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/12/04 14:58:15 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_door_vertical(t_mappoint *res, int sign, t_map map)
{
	float	pos;
	t_door	*door;
	int		index;

	pos = res->y - (int)res->y;
	index = (int)res->y * map.w + (int)(res->x + 0.0001 * sign);
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

static t_mappoint	get_vertical_first_point(float angle, int *sign,
		t_player player)
{
	t_mappoint	res;

	if (angle < PI / 2 || angle > 3 * PI / 2)
	{
		*sign = 1;
		res.x = (int)player.posx + 1;
	}
	else
	{
		*sign = -1;
		res.x = (int)player.posx;
	}
	res.y = player.posy + (player.posx - res.x) * tan(angle);
	return (res);
}

static void	finding_vertical_point(t_mappoint *res, float angle,
		int sign, t_map map)
{
	float	x;
	float	y;

	while (res->x < map.w && res->x >= 0)
	{
		x = res->x + sign;
		y = res->y - sign * tan(angle);
		if (y >= map.h || y < -0.0001 || x >= map.w || x < -0.0001)
			return ;
		else
		{
			res->x = x;
			res->y = y;
		}
		if (map.el[(int)res->y * map.w
				+ (int)(res->x + 0.0001 * sign)].type != '0')
		{
			check_door_vertical(res, sign, map);
			if (res->ok == 1)
				return ;
		}
	}
}

t_mappoint	get_vertical_point(t_player player, float angle, t_map map)
{
	t_mappoint	res;
	int			sign;

	res = get_vertical_first_point(angle, &sign, player);
	if (res.y >= map.h || res.y < -0.0001 || res.x >= map.w || res.x < -0.0001)
	{
		res.ok = 0;
		return (res);
	}
	if (map.el[(int)res.y * map.w + (int)(res.x + 0.0001 * sign)].type != '0')
	{
		check_door_vertical(&res, sign, map);
		if (res.ok == 1)
			return (res);
	}
	res.ok = 0;
	finding_vertical_point(&res, angle, sign, map);
	return (res);
}
