/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:00:07 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 07:48:48 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	chk_smb_in_texs(t_texs **arr, char ch)
{
	int	i;

	if (!arr)
		return (-1);
	i = -1;
	while (arr[++i])
	{
		if (arr[i]->smb == ch)
			return (i);
	}
	return (-1);
}

static void	add_texture(t_main_data *md, t_image ***arr, char *w)
{
	int		i;
	t_image	*pic;

	i = add_arr_el((void ***)arr, sizeof(t_image));
	pic = (*arr)[i];
	pic->src = mlx_xpm_file_to_image
		(md->scr.mlx, w, &(pic->w), &(pic->h));
	if (!(*arr)[i]->src)
	{
		free(w);
		prt_error(ERR_TEX_F, 0);
	}
	pic->pimg = (int *)mlx_get_data_addr
		(pic->src, &(pic->bpp), &(pic->sl), &(pic->end));
	free(w);
}

static void	chk_use_smb(t_main_data *md, char ch)
{
	int	d;
	int	s;

	d = chk_smb_in_texs(md->door_tex_arr, ch);
	s = chk_smb_in_texs(md->sp_tex_arr, ch);
	if (d > -1 || s > -1 || ft_strchr("01NSEW", ch))
		prt_error(ERR_UNI_SMB, 0);
}

static void	set_move_texs(t_texs *el, char *w)
{
	if (!ft_strncmp("move", w, 5))
		el->fix = 1;
	else
		el->fix = 0;
	free(w);
}

void	parser_texs(t_main_data *md, t_texs ***arr, char *str, int pos)
{
	char	*w;
	int		i;

	i = add_arr_el((void ***)arr, sizeof(t_texs));
	(*arr)[i]->texs = NULL;
	pos = get_next_word(str, &w, pos);
	if (!ft_strlen(w))
		prt_error(ERR_CMD_F, 0);
	chk_use_smb(md, w[0]);
	(*arr)[i]->smb = w[0];
	free(w);
	pos = get_next_word(str, &w, pos);
	set_move_texs((*arr)[i], w);
	pos = get_next_word(str, &w, pos);
	(*arr)[i]->cframe = ft_atoi(w);
	free(w);
	pos = get_next_word(str, &w, pos);
	while (pos > 0)
	{
		add_texture(md, &((*arr)[i]->texs), w);
		pos = get_next_word(str, &w, pos);
	}
	add_texture(md, &((*arr)[i]->texs), w);
}
