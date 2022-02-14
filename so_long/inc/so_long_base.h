/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_base.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:07:05 by msimon            #+#    #+#             */
/*   Updated: 2021/07/30 15:24:49 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BASE_H
# define SO_LONG_BASE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "err_mess.h"
# include "screen_setings.h"

typedef struct s_scr
{
	void	*mlx;
	void	*win;
	int		counter;
	int		p_key;
	int		p_key_r;
}	t_scr;

typedef struct s_game_over
{
	int		x;
	int		y;
	void	*sprite;
}	t_game_over;

typedef struct s_you_win
{
	int		x;
	int		y;
	void	*sprite;
}	t_you_win;

typedef struct s_map
{
	int			count_coll;
	char		flag_exit;
	char		end_game;
	int			x_max;
	int			y_max;
	char		**data;
	int			d_x;
	int			d_y;
	t_you_win	yw;
	t_game_over	go;
}	t_map;

typedef struct s_space
{
	void	*sprite;
}	t_space;

typedef struct s_wall
{
	void	*sprite;
}	t_wall;

typedef struct s_collect
{
	char	pos;
	void	**sprites;
}	t_collect;

typedef struct s_exit
{
	char	pos;
	void	**sprites;
}	t_exit;

typedef struct s_player
{
	int		count_move;
	int		x;
	int		y;
	char	vector;
	char	pos;
	void	***sprites;
}	t_player;

void	init_scr(t_scr *scr);
void	join_line_to_map(t_map *map, char *line);
void	set_pos_map(t_map *map, t_player pl);
void	init_info(t_scr scr, void **i_bg);
void	render_info(t_scr scr, void *i_bg, t_map map, t_player pl);
void	init_space_wall(t_scr scr, t_space *sp, t_wall *wl);
void	render_space(t_scr scr, t_map map, t_space sp);
void	render_wall(t_scr scr, t_map map, t_wall wl);
void	init_player(t_scr scr, t_map map, t_player *pl);
void	render_player(t_scr scr, t_map map, t_player player);
void	move_player(t_scr src, t_map *map, t_player *pl);
void	init_collectibles(t_scr	scr, t_collect *coll);
void	init_exit(t_scr	scr, t_exit *ex);
void	render_collectibles(t_scr scr, t_map map, t_collect *coll);
void	render_exit(t_scr scr, t_map map, t_exit *ex);
void	init_go_yw(t_scr scr, t_map *map);
void	pr_error(char *str, char fl);

#endif