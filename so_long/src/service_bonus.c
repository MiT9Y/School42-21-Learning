/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:28:52 by msimon            #+#    #+#             */
/*   Updated: 2021/07/31 08:27:31 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_arr_img(void *mlx, void ***p, int li, int lj)
{
	int	i;
	int	j;

	i = -1;
	while (++i < li)
	{
		j = -1;
		while (++j < lj)
			mlx_destroy_image(mlx, p[i][j]);
		free(p[i]);
	}
	if (li > 1)
		free(p);
}

int	close_app(t_so_long *sl)
{
	int	i;

	i = -1;
	while (++i < sl->map.y_max)
		free(sl->map.data[i]);
	free(sl->map.data);
	mlx_destroy_image(sl->scr.mlx, sl->info_bg);
	mlx_destroy_image(sl->scr.mlx, sl->map.yw.sprite);
	mlx_destroy_image(sl->scr.mlx, sl->map.go.sprite);
	free_arr_img(sl->scr.mlx, sl->player.sprites, 4, 4);
	free_arr_img(sl->scr.mlx, &(sl->collect.sprites), 1, 4);
	free_arr_img(sl->scr.mlx, &(sl->exit.sprites), 1, 4);
	free_arr_img(sl->scr.mlx, sl->enemys.sprites, 2, 4);
	free(sl->enemys.enemy);
	mlx_destroy_image(sl->scr.mlx, sl->spase.sprite);
	mlx_destroy_image(sl->scr.mlx, sl->wall.sprite);
	mlx_destroy_window(sl->scr.mlx, sl->scr.win);
	printf("THE END!\n");
	exit (0);
	return (0);
}

int	key_press(int key, t_so_long *sl)
{
	sl->scr.p_key_r = -1;
	sl->scr.p_key = key;
	if (key == 53)
		close_app(sl);
	return (0);
}

int	key_release(int key, t_so_long *sl)
{
	sl->scr.p_key_r = key;
	return (0);
}
