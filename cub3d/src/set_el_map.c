/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_el_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 08:20:14 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 08:28:51 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_door	*get_door_p(t_main_data *md, t_image *img)
{
	int	i;

	i = add_arr_el((void ***)&(md->doors), sizeof(t_door));
	md->doors[i]->img = img;
	md->doors[i]->pos = 0.0;
	md->doors[i]->open = 0;
	return (md->doors[i]);
}

static void	set_spase(t_main_data *md, int p, char ch, int s)
{
	md->map.el[p].type = '0';
	md->map.el[p].data = NULL;
	if (s > -1)
		set_sp_map(md, s, p % md->map.w, p / md->map.w);
	else if (ft_strchr("NSEW", ch))
		set_plr_map(md, ch, p % md->map.w, p / md->map.w);
}

void	set_el_map(t_main_data *md, char ch, int p)
{
	int	d;
	int	s;

	d = chk_smb_in_texs(md->door_tex_arr, ch);
	s = chk_smb_in_texs(md->sp_tex_arr, ch);
	if (ch == '0' || s > -1 || ft_strchr("NSEW", ch))
		set_spase(md, p, ch, s);
	else if (ch == '1')
	{
		md->map.el[p].type = '1';
		md->map.el[p].data = (void *)&(md->wall);
	}
	else if (d > -1)
	{
		md->map.el[p].type = ch;
		md->map.el[p].data = (void *)
			get_door_p(md, md->door_tex_arr[d]->texs[0]);
	}
	else
		prt_error(ERR_NOT_SMB, 0);
}
