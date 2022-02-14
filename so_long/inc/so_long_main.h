/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:16:21 by msimon            #+#    #+#             */
/*   Updated: 2021/07/30 15:24:42 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MAIN_H
# define SO_LONG_MAIN_H

# include "so_long_base.h"

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
}	t_so_long;

void	init_map(t_so_long *sl, char *fn);
int		close_app(t_so_long *p);
int		key_press(int key, t_so_long *p);
int		key_release(int key, t_so_long *p);

#endif