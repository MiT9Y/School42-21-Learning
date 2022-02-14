/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 08:03:10 by msimon            #+#    #+#             */
/*   Updated: 2021/07/31 10:57:24 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*set_img(t_so_long *sl, char *str)
{
	int	tmp;

	return (mlx_xpm_file_to_image(sl->scr.mlx, str, &tmp, &tmp));
}

static void	init_sprites(t_so_long *sl)
{
	if (sl->enemys.count)
	{
		sl->enemys.enemy = malloc(sizeof(t_enemy) * sl->enemys.count);
		if (!sl->enemys.enemy)
			pr_error(ERR_MEM, 0);
	}
	sl->enemys.sprites = malloc(sizeof(void *) * 2);
	if (!sl->enemys.sprites)
		pr_error(ERR_MEM, 0);
	sl->enemys.sprites[0] = malloc(sizeof(void *) * 4);
	if (!sl->enemys.sprites[0])
		pr_error(ERR_MEM, 0);
	sl->enemys.sprites[1] = malloc(sizeof(void *) * 4);
	if (!sl->enemys.sprites[1])
		pr_error(ERR_MEM, 0);
	sl->enemys.sprites[0][0] = set_img(sl, "./sprites/ed0.xpm");
	sl->enemys.sprites[0][1] = set_img(sl, "./sprites/ed1.xpm");
	sl->enemys.sprites[0][2] = set_img(sl, "./sprites/ed0.xpm");
	sl->enemys.sprites[0][3] = set_img(sl, "./sprites/ed2.xpm");
	sl->enemys.sprites[1][0] = set_img(sl, "./sprites/eu0.xpm");
	sl->enemys.sprites[1][1] = set_img(sl, "./sprites/eu1.xpm");
	sl->enemys.sprites[1][2] = set_img(sl, "./sprites/eu0.xpm");
	sl->enemys.sprites[1][3] = set_img(sl, "./sprites/eu2.xpm");
}

void	init_enemy(t_so_long *sl)
{
	int		i;
	int		j;
	int		c;
	t_enemy	*e;

	init_sprites(sl);
	c = 0;
	i = -1;
	while (++i < sl->map.y_max)
	{
		j = -1;
		while (++j < sl->map.x_max)
		{
			if (sl->map.data[i][j] == 'e')
			{
				e = &(sl->enemys.enemy[c]);
				e->dir_move = 1;
				e->pos = 0;
				e->vector = 0;
				e->x = j * BLOCK_SIZE;
				e->y = i * BLOCK_SIZE;
				c++;
			}
		}
	}	
}
