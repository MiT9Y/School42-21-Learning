/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_sp_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:55:55 by msimon            #+#    #+#             */
/*   Updated: 2021/07/30 20:41:06 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_base.h"

void	render_wall(t_scr scr, t_map map, t_wall wl)
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
				>= INFO_SIZE && y <= HEIGHT && map.data[i][j] == '1')
				mlx_put_image_to_window(scr.mlx, scr.win, wl.sprite, x, y);
		}
	}
}

void	render_space(t_scr scr, t_map map, t_space sp)
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
				>= INFO_SIZE && y <= HEIGHT)
				mlx_put_image_to_window(scr.mlx, scr.win, sp.sprite, x, y);
		}
	}
}

void	init_space_wall(t_scr scr, t_space *sp, t_wall *wl)
{
	int	tmp;

	sp->sprite = mlx_xpm_file_to_image(scr.mlx, "./sprites/space.xpm",
			&tmp, &tmp);
	wl->sprite = mlx_xpm_file_to_image(scr.mlx, "./sprites/wall.xpm",
			&tmp, &tmp);
	if (!sp->sprite || !wl->sprite)
		pr_error(ERR_SPRITES_LOAD, 0);
}
