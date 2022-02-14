/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:11:02 by msimon            #+#    #+#             */
/*   Updated: 2021/08/01 11:28:13 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	ch_end_game(t_so_long *sl)
{
	if (!sl->map.end_game)
		return (0);
	if (sl->map.end_game == 1)
	{
		mlx_put_image_to_window(sl->scr.mlx, sl->scr.win,
			sl->map.yw.sprite, sl->map.yw.x, sl->map.yw.y);
		sl->map.end_game = 100;
	}
	if (sl->map.end_game == 2)
	{
		mlx_put_image_to_window(sl->scr.mlx, sl->scr.win,
			sl->map.go.sprite, sl->map.go.x, sl->map.go.y);
		sl->map.end_game = 100;
	}
	return (1);
}

static int	render_next_frame(t_so_long *sl)
{
	if (ch_end_game(sl))
		return (0);
	if (sl->scr.counter == CFRAME)
	{
		sl->scr.counter = 0;
		move_player(sl->scr, &(sl->map), &(sl->player));
		set_pos_map(&(sl->map), sl->player);
		render_space(sl->scr, sl->map, sl->spase);
		render_wall(sl->scr, sl->map, sl->wall);
		render_collectibles(sl->scr, sl->map, &(sl->collect));
		render_exit(sl->scr, sl->map, &(sl->exit));
		render_player(sl->scr, sl->map, sl->player);
		render_enemys(sl);
		render_info(sl->scr, sl->info_bg, sl->map, sl->player);
		if (sl->scr.p_key_r > -1 && sl->scr.p_key == sl->scr.p_key_r)
		{
			sl->scr.p_key = -1;
			sl->scr.p_key_r = -1;
		}
	}
	else
		sl->scr.counter++;
	return (0);
}

static void	init(t_so_long	*sl, int argc, char **argv)
{
	if (argc == 2)
	{
		init_scr(&(sl->scr));
		init_map(sl, argv[1]);
		init_info(sl->scr, &(sl->info_bg));
		init_space_wall(sl->scr, &(sl->spase), &(sl->wall));
		init_collectibles(sl->scr, &(sl->collect));
		init_exit(sl->scr, &(sl->exit));
		init_player(sl->scr, sl->map, &(sl->player));
		init_go_yw(sl->scr, &(sl->map));
		init_enemy(sl);
	}
	else
		pr_error(ERR_USAGE, 0);
}

static void	init_hook(t_so_long	*sl)
{
	mlx_hook(sl->scr.win, 2, 0, key_press, sl);
	mlx_hook(sl->scr.win, 3, 0, key_release, sl);
	mlx_hook(sl->scr.win, 17, 0, close_app, sl);
}

int	main(int argc, char **argv)
{
	t_so_long	sl;

	init(&sl, argc, argv);
	init_hook(&sl);
	mlx_loop_hook(sl.scr.mlx, render_next_frame, &sl);
	mlx_loop(sl.scr.mlx);
	return (0);
}
