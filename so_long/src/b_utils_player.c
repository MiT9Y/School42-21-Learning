/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:09:24 by msimon            #+#    #+#             */
/*   Updated: 2021/08/01 09:46:38 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_base.h"

static void	set_pos_pl(t_map map, t_player *pl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.y_max)
	{
		j = -1;
		while (++j < map.x_max)
		{
			if (map.data[i][j] == 'P')
			{
				pl->x = j * BLOCK_SIZE;
				pl->y = i * BLOCK_SIZE;
			}
		}
	}
}

static void	init_sprites(void ****sp)
{
	*sp = malloc(sizeof(void *) * 4);
	if (!*sp)
		pr_error(ERR_MEM, 0);
	(*sp)[0] = malloc(sizeof(void *) * 4);
	if (!(*sp)[0])
		pr_error(ERR_MEM, 0);
	(*sp)[1] = malloc(sizeof(void *) * 4);
	if (!(*sp)[1])
		pr_error(ERR_MEM, 0);
	(*sp)[2] = malloc(sizeof(void *) * 4);
	if (!(*sp)[2])
		pr_error(ERR_MEM, 0);
	(*sp)[3] = malloc(sizeof(void *) * 4);
	if (!(*sp)[3])
		pr_error(ERR_MEM, 0);
}

static void	ch_sprites_load(void ***sp)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (!sp[i][j])
				pr_error(ERR_SPRITES_LOAD, 0);
	}
}

static void	*set_img(void *mlx, char *str)
{
	int	tmp;

	return (mlx_xpm_file_to_image(mlx, str, &tmp, &tmp));
}

void	init_player(t_scr scr, t_map map, t_player *pl)
{
	pl->pos = 0;
	pl->vector = 0;
	set_pos_pl(map, pl);
	init_sprites(&(pl->sprites));
	pl->sprites[0][0] = set_img(scr.mlx, "./sprites/r0.xpm");
	pl->sprites[0][1] = set_img(scr.mlx, "./sprites/r1.xpm");
	pl->sprites[0][2] = set_img(scr.mlx, "./sprites/r0.xpm");
	pl->sprites[0][3] = set_img(scr.mlx, "./sprites/r2.xpm");
	pl->sprites[1][0] = set_img(scr.mlx, "./sprites/d0.xpm");
	pl->sprites[1][1] = set_img(scr.mlx, "./sprites/d1.xpm");
	pl->sprites[1][2] = set_img(scr.mlx, "./sprites/d0.xpm");
	pl->sprites[1][3] = set_img(scr.mlx, "./sprites/d2.xpm");
	pl->sprites[2][0] = set_img(scr.mlx, "./sprites/l0.xpm");
	pl->sprites[2][1] = set_img(scr.mlx, "./sprites/l1.xpm");
	pl->sprites[2][2] = set_img(scr.mlx, "./sprites/l0.xpm");
	pl->sprites[2][3] = set_img(scr.mlx, "./sprites/l2.xpm");
	pl->sprites[3][0] = set_img(scr.mlx, "./sprites/u0.xpm");
	pl->sprites[3][1] = set_img(scr.mlx, "./sprites/u1.xpm");
	pl->sprites[3][2] = set_img(scr.mlx, "./sprites/u0.xpm");
	pl->sprites[3][3] = set_img(scr.mlx, "./sprites/u2.xpm");
	ch_sprites_load(pl->sprites);
	pl->count_move = 0;
}
