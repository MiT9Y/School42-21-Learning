/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_player_render.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:26:17 by msimon            #+#    #+#             */
/*   Updated: 2021/07/30 20:26:45 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_base.h"

void	render_player(t_scr scr, t_map map, t_player player)
{
	mlx_put_image_to_window(scr.mlx, scr.win,
		player.sprites[(int)player.vector][(int)player.pos],
		player.x - map.d_x, player.y - map.d_y);
}
