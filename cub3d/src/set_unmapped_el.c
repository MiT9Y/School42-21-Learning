/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_unmapped_el.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:17:50 by msimon            #+#    #+#             */
/*   Updated: 2021/12/02 14:02:11 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*Для fix = 0 вектор направления можно задать через rand()*/
/*float x=(float)rand()/((float)RAND_MAX/a) range of [0,a]*/
void	set_sp_map(t_main_data *md, int s, int x, int y)
{
	int	i;

	i = add_arr_el((void ***)&(md->sprs), sizeof(t_sprite));
	md->sprs[i]->texs = md->sp_tex_arr[s]->texs;
	md->sprs[i]->n_sp = rand() % arr_len((void **)md->sprs[i]->texs);
	md->sprs[i]->x = x + 0.5;
	md->sprs[i]->y = y + 0.5;
	md->sprs[i]->fix = md->sp_tex_arr[s]->fix;
	if (md->sprs[i]->fix)
	{
		md->sprs[i]->dx = 0.0;
		md->sprs[i]->dy = 1.0;
	}
	else
	{
		md->sprs[i]->dx = 0.0;
		md->sprs[i]->dy = 0.0;
	}
	md->sprs[i]->count = 0;
	md->sprs[i]->cframe = md->sp_tex_arr[s]->cframe;
}

/* на восток - 0, на юг - 3/2 * Pi, на запад - Pi, на север - 1/2 *Pi */
void	set_plr_map(t_main_data *md, char ch, int x, int y)
{
	md->player.posx = x + 0.5;
	md->player.posy = y + 0.5;
	if (ch == 'N')
		md->player.posa = PI * 0.5;
	else if (ch == 'S')
		md->player.posa = PI * 1.5;
	else if (ch == 'E')
		md->player.posa = 0.0;
	else
		md->player.posa = PI;
}
