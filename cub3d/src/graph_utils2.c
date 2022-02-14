/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 07:10:14 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 07:26:21 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_rhomb_h(t_image dst, t_ipoint h, int y, int color)
{
	while (++h.x < h.y)
		draw_pixel(dst, h.x, y, color);
}

void	draw_rhomb(t_image dst, t_ipoint centre, int size, int color)
{
	int	y;
	int	half;
	int	pl;

	y = centre.y - (size / 2) - 1;
	half = y + (size / 2) + 1;
	pl = 0;
	while (++y <= half)
	{
		draw_rhomb_h(
			dst, (t_ipoint){centre.x - pl - 1, centre.x + pl + 1}, y, color);
		pl++;
	}
	pl -= 2;
	half = y + size + 1;
	while (y < half)
	{
		draw_rhomb_h(
			dst, (t_ipoint){centre.x - pl - 1, centre.x + pl + 1}, y, color);
		pl--;
		y++;
	}
}
