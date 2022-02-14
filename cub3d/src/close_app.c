/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_app.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:24:13 by msimon            #+#    #+#             */
/*   Updated: 2021/12/03 14:32:33 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	drop_texs(t_texs **texs)
{
	int	i;

	i = -1;
	if (!texs)
		return ;
	while (texs[++i])
		drop_arr((void **)texs[i]->texs);
	drop_arr((void **)texs);
}

int	close_app(t_main_data *md)
{
	free(md->map.el);
	drop_texs(md->door_tex_arr);
	drop_texs(md->sp_tex_arr);
	drop_arr((void **)md->sprs);
	mlx_destroy_window(md->scr.mlx, md->scr.win);
	printf("THE END!\n");
	exit(0);
	return (0);
}
