/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:46:40 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 06:41:16 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int key, t_main_data *md)
{
	if (key == ESC)
		close_app(md);
	if (key == LEFT && md->pl_move.rt_move == 0.0)
		md->pl_move.rt_move = (ROT_SPEED * PI / 360.0);
	if (key == RIGHT && md->pl_move.rt_move == 0.0)
		md->pl_move.rt_move = -1.0 * (ROT_SPEED * PI / 360.0);
	if (key == BUTTON_E)
		md->pl_move.event_f = 1;
	if (key == BUTTON_W && md->pl_move.ud_move == 0.0)
		md->pl_move.ud_move = MOVE_SPEED;
	if (key == BUTTON_S && md->pl_move.ud_move == 0.0)
		md->pl_move.ud_move = -1.0 * MOVE_SPEED;
	if (key == BUTTON_A && md->pl_move.lr_move == 0.0)
		md->pl_move.lr_move = MOVE_SPEED;
	if (key == BUTTON_D && md->pl_move.lr_move == 0.0)
		md->pl_move.lr_move = -1.0 * MOVE_SPEED;
	return (0);
}

int	key_release(int key, t_main_data *md)
{
	if (key == LEFT && md->pl_move.rt_move != 0.0)
		md->pl_move.rt_move = 0.0;
	if (key == RIGHT && md->pl_move.rt_move != 0.0)
		md->pl_move.rt_move = 0.0;
	if (key == BUTTON_E)
		md->pl_move.event_f = 0;
	if (key == BUTTON_W && md->pl_move.ud_move != 0.0)
		md->pl_move.ud_move = 0.0;
	if (key == BUTTON_S && md->pl_move.ud_move != 0.0)
		md->pl_move.ud_move = 0.0;
	if (key == BUTTON_A && md->pl_move.lr_move != 0.0)
		md->pl_move.lr_move = 0.0;
	if (key == BUTTON_D && md->pl_move.lr_move != 0.0)
		md->pl_move.lr_move = 0.0;
	return (0);
}

int	mouse_move(int x, int y, t_main_data *md)
{
	(void)y;
	if (md->pl_move.x_mouse != -99999999)
	{
		md->pl_move.rt_move = ((ROT_MOUSE * PI / 360.0)
				* (md->pl_move.x_mouse - x));
		md->pl_move.m_counter = MOUSE_WAIT;
	}
	md->pl_move.x_mouse = x;
	return (0);
}
