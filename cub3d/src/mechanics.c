/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:46:17 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/12/04 15:03:22 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	count_param(t_src_render *res, t_dist dist, t_points points,
		float now_angle)
{
	float	scale;

	scale = (float)WIDTH / (2 * tan(PI / 6));
	if (res->type == 'v')
	{
		res->dist = dist.ver_dist;
		res->size = scale / (dist.ver_dist);
		choose_img(points.ver, res, now_angle);
		res->data = points.hor.data;
	}
	else
	{
		res->dist = dist.hor_dist;
		res->size = scale / (dist.hor_dist);
		choose_img(points.hor, res, now_angle);
		res->data = points.ver.data;
	}
	res->pos = count_pos(res, points, now_angle);
}

t_src_render	*get_raycasting_params(t_main_data *md, float now_angle)
{
	t_points		points;
	t_dist			dist;
	t_src_render	*res;

	res = malloc(sizeof(t_src_render));
	points.ver = get_vertical_point(md->player, now_angle, md->map);
	points.hor = get_horizontal_point(md->player, now_angle, md->map);
	dist.ver_dist = get_distance(points.ver, md->player,
			now_angle - md->player.posa);
	dist.hor_dist = get_distance(points.hor, md->player,
			now_angle - md->player.posa);
	check_type(res, dist);
	count_param(res, dist, points, now_angle);
	return (res);
}

static void	add_sprites(t_main_data *md, t_src_render ***arr, int x)
{
	int		i;
	int		j;
	t_image	*pic;

	i = -1;
	while (md->sprs[++i])
	{
		if (x >= md->sprs[i]->xb && x < md->sprs[i]->xe
			&& (*arr)[0]->dist > md->sprs[i]->r)
		{
			pic = md->sprs[i]->texs[md->sprs[i]->n_sp];
			j = add_arr_el((void ***)arr, sizeof(t_src_render));
			(*arr)[j]->img = pic;
			(*arr)[j]->pos = ((float)x - md->sprs[i]->xb)
				/ (md->sprs[i]->xe - md->sprs[i]->xb);
			(*arr)[j]->size = md->sprs[i]->size;
			(*arr)[j]->dist = md->sprs[i]->r;
		}
	}
}

t_src_render	***make_arr_ray(t_main_data *md)
{
	t_src_render	***res;
	int				x;
	float			now_angle;
	float			fov;

	x = 0;
	res = malloc(sizeof(void *) * WIDTH);
	if (!res)
		prt_error(ERR_MEM, 0);
	fov = FOV * PI / 180.0;
	now_angle = angle_math(md->player.posa + fov / 2);
	while (x < WIDTH)
	{
		res[x] = malloc(sizeof(void *) * 2);
		if (!res[x])
			prt_error(ERR_MEM, 0);
		res[x][0] = get_raycasting_params(md, now_angle);
		res[x][1] = NULL;
		add_sprites(md, &(res[x]), x);
		now_angle = angle_math(now_angle - fov / (float)WIDTH);
		x++;
	}
	return (res);
}
