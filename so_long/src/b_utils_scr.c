/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_scr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:59:20 by msimon            #+#    #+#             */
/*   Updated: 2021/08/01 09:46:47 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_base.h"

void	init_scr(t_scr *scr)
{
	scr->mlx = mlx_init();
	if (!scr->mlx)
		pr_error(ERR_MEM, 0);
	scr->win = mlx_new_window(scr->mlx, WIDTH, HEIGHT, "SoLong");
	if (!scr->win)
		pr_error(ERR_MEM, 0);
	scr->counter = CFRAME;
	scr->p_key = -1;
	scr->p_key_r = -1;
}
