/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:07:47 by msimon            #+#    #+#             */
/*   Updated: 2021/08/01 11:00:04 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long_base.h"

typedef struct s_enemy
{
	int		x;
	int		y;
	char	pos;
	char	vector;
	char	dir_move;
}	t_enemy;

typedef struct s_enemys
{
	int		count;
	void	***sprites;
	t_enemy	*enemy;
}	t_enemys;

typedef struct s_so_long
{
	t_scr		scr;
	t_map		map;
	void		*info_bg;
	t_space		spase;
	t_wall		wall;
	t_exit		exit;
	t_collect	collect;
	t_player	player;
	t_enemys	enemys;
}	t_so_long;

void	init_map(t_so_long *sl, char *fn);
int		close_app(t_so_long *p);
int		key_press(int key, t_so_long *p);
int		key_release(int key, t_so_long *p);
void	init_enemy(t_so_long *sl);
void	render_enemys(t_so_long *sl);

#endif