/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:47:08 by msimon            #+#    #+#             */
/*   Updated: 2021/08/01 09:45:59 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_base.h"

void	init_go_yw(t_scr scr, t_map *map)
{
	int	w;
	int	h;

	map->go.sprite = mlx_xpm_file_to_image(scr.mlx, "./sprites/go.xpm", &w, &h);
	if (!map->go.sprite)
		pr_error(ERR_SPRITES_LOAD, 0);
	map->go.x = (WIDTH - w) / 2;
	map->go.y = (HEIGHT - h + INFO_SIZE) / 2;
	map->yw.sprite = mlx_xpm_file_to_image(scr.mlx, "./sprites/yw.xpm", &w, &h);
	if (!map->yw.sprite)
		pr_error(ERR_SPRITES_LOAD, 0);
	map->yw.x = (WIDTH - w) / 2;
	map->yw.y = (HEIGHT - h + INFO_SIZE) / 2;
}

void	set_pos_map(t_map *map, t_player pl)
{
	if (map->x_max * BLOCK_SIZE > WIDTH)
	{
		map->d_x = pl.x - WIDTH / 2;
		if (map->d_x < 0)
			map->d_x = 0;
		if (map->d_x > (map->x_max * BLOCK_SIZE) - WIDTH)
			map->d_x = (map->x_max * BLOCK_SIZE) - WIDTH;
	}
	else
		map->d_x = -((WIDTH - (map->x_max * BLOCK_SIZE)) / 2);
	if (map->y_max * BLOCK_SIZE > (HEIGHT - INFO_SIZE))
	{
		map->d_y = pl.y - (HEIGHT - INFO_SIZE) / 2;
		if (map->d_y < 0)
			map->d_y = 0;
		if (map->d_y > (map->y_max * BLOCK_SIZE) - (HEIGHT - INFO_SIZE))
			map->d_y = (map->y_max * BLOCK_SIZE) - (HEIGHT - INFO_SIZE);
	}
	else
		map->d_y = -(((HEIGHT - INFO_SIZE) - (map->y_max * BLOCK_SIZE)) / 2);
	map->d_y -= INFO_SIZE;
}

void	join_line_to_map(t_map *map, char *line)
{
	char	**new_data;
	int		i;
	int		ln;

	new_data = malloc(sizeof(char *) * ++map->y_max);
	if (new_data)
	{
		ln = ft_strlen(line);
		if (map->x_max < ln)
			map->x_max = ln;
		if (ln < 0 || map->x_max * map->y_max < 0)
			pr_error(ERR_INT_OVERFLOW, 0);
		i = -1;
		while (++i < map->y_max - 1)
			new_data[i] = map->data[i];
		new_data[map->y_max - 1] = line;
		free(map->data);
		map->data = new_data;
		return ;
	}
	pr_error(ERR_MEM, 0);
}
