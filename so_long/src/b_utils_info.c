/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:47:35 by msimon            #+#    #+#             */
/*   Updated: 2021/08/01 09:45:45 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_base.h"

void	render_info(t_scr scr, void *i_bg, t_map map, t_player pl)
{
	char	*str;

	mlx_put_image_to_window(scr.mlx, scr.win, i_bg, 0, 0);
	mlx_string_put(scr.mlx, scr.win, 10, 3, 0x0, "Collectible:");
	str = ft_itoa(map.count_coll);
	mlx_string_put(scr.mlx, scr.win, 135, 3, 0x0, str);
	free(str);
	mlx_string_put(scr.mlx, scr.win, 10, 24, 0x0, "Movements  :");
	str = ft_itoa(pl.count_move);
	mlx_string_put(scr.mlx, scr.win, 135, 24, 0x0, str);
	free(str);
	mlx_string_put(scr.mlx, scr.win, 250, 3,
		0x0, "Press ESC to exit the game");
	mlx_string_put(scr.mlx, scr.win, 250,
		24, 0x0, "Press W, S, A, D to move the player");
}

void	init_info(t_scr scr, void **i_bg)
{
	int	i;
	int	*p_img;
	int	tmp;

	*i_bg = mlx_new_image(scr.mlx, WIDTH, INFO_SIZE);
	if (!*i_bg)
		pr_error(ERR_MEM, 0);
	p_img = (int *)mlx_get_data_addr(*i_bg, &tmp, &tmp, &tmp);
	i = -1;
	while (++i < WIDTH * INFO_SIZE)
		p_img[i] = 0xFFFFFF;
}
