/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_coll_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:48:22 by msimon            #+#    #+#             */
/*   Updated: 2021/08/01 09:45:34 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_base.h"

void	init_collectibles(t_scr	scr, t_collect *coll)
{
	int	tmp;

	coll->pos = 0;
	coll->sprites = malloc(sizeof(void *) * 4);
	if (!coll->sprites)
		pr_error(ERR_MEM, 0);
	coll->sprites[0] = mlx_xpm_file_to_image(scr.mlx,
			"./sprites/money0.xpm", &tmp, &tmp);
	coll->sprites[1] = mlx_xpm_file_to_image(scr.mlx,
			"./sprites/money1.xpm", &tmp, &tmp);
	coll->sprites[2] = mlx_xpm_file_to_image(scr.mlx,
			"./sprites/money2.xpm", &tmp, &tmp);
	coll->sprites[3] = mlx_xpm_file_to_image(scr.mlx,
			"./sprites/money3.xpm", &tmp, &tmp);
	if (!coll->sprites[0] || !coll->sprites[1]
		|| !coll->sprites[2] || !coll->sprites[3])
		pr_error(ERR_SPRITES_LOAD, 0);
}

void	init_exit(t_scr	scr, t_exit *ex)
{
	int	tmp;

	ex->pos = 0;
	ex->sprites = malloc(sizeof(void *) * 4);
	if (!ex->sprites)
		pr_error(ERR_MEM, 0);
	ex->sprites[0] = mlx_xpm_file_to_image(scr.mlx,
			"./sprites/exit0.xpm", &tmp, &tmp);
	ex->sprites[1] = mlx_xpm_file_to_image(scr.mlx,
			"./sprites/exit1.xpm", &tmp, &tmp);
	ex->sprites[2] = mlx_xpm_file_to_image(scr.mlx,
			"./sprites/exit2.xpm", &tmp, &tmp);
	ex->sprites[3] = mlx_xpm_file_to_image(scr.mlx,
			"./sprites/exit3.xpm", &tmp, &tmp);
	if (!ex->sprites[0] || !ex->sprites[1]
		|| !ex->sprites[2] || !ex->sprites[3])
		pr_error(ERR_SPRITES_LOAD, 0);
}

void	render_collectibles(t_scr scr, t_map map, t_collect *coll)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (++i < map.y_max)
	{
		j = -1;
		while (++j < map.x_max)
		{
			x = (j * BLOCK_SIZE) - map.d_x;
			y = (i * BLOCK_SIZE) - map.d_y;
			if (x + BLOCK_SIZE >= 0 && x <= WIDTH && y + BLOCK_SIZE
				>= INFO_SIZE && y <= HEIGHT && map.data[i][j] == 'C')
				mlx_put_image_to_window(scr.mlx, scr.win,
					coll->sprites[(int)coll->pos], x, y);
		}
	}
	coll->pos++;
	if (coll->pos == 4)
		coll->pos = 0;
}

void	render_exit(t_scr scr, t_map map, t_exit *ex)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (++i < map.y_max)
	{
		j = -1;
		while (++j < map.x_max)
		{
			x = (j * BLOCK_SIZE) - map.d_x;
			y = (i * BLOCK_SIZE) - map.d_y;
			if (x + BLOCK_SIZE >= 0 && x <= WIDTH && y + BLOCK_SIZE
				>= INFO_SIZE && y <= HEIGHT && map.data[i][j] == 'E')
				mlx_put_image_to_window(scr.mlx, scr.win,
					ex->sprites[(int)ex->pos], x, y);
		}
	}
	if (map.flag_exit && ex->pos < 3)
		ex->pos++;
}
