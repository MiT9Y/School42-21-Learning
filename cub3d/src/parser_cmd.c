/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:33:32 by msimon            #+#    #+#             */
/*   Updated: 2021/11/19 10:42:26 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parser_wall(t_main_data *md, t_image *wall, char *str, int pos)
{
	char	*w;

	get_next_word(str, &w, pos);
	if (wall->src)
		prt_error(ERR_WALL_T, 0);
	wall->src = mlx_xpm_file_to_image(md->scr.mlx, w, &(wall->w), &(wall->h));
	if (!wall->src)
		prt_error(ERR_TEX_F, 0);
	wall->pimg = (int *)mlx_get_data_addr
		(wall->src, &(wall->bpp), &(wall->sl), &(wall->end));
	free(w);
}

static void	init_rgb_str(char **str)
{
	*str = malloc(sizeof(char));
	if (!*str)
		prt_error(ERR_MEM, 0);
	(*str)[0] = 0;
}

static void	set_color_var(int *col, char **rgb, char *rgb_f)
{
	int	buf;

	if (!*rgb)
		prt_error(ERR_COL_VAL, 0);
	buf = ft_atoi(*rgb);
	if (*rgb_f > 2)
		prt_error(ERR_COL_VAL, 0);
	if (buf < 0 || buf > 255)
		prt_error(ERR_RGB_VAL, 0);
	*col = *col | (buf << ((2 - *rgb_f) * 8));
	*rgb_f += 1;
	free(*rgb);
	*rgb = NULL;
}

void	parser_bg(int *col, char *str, int pos)
{
	char	*w;
	char	*rgb;
	int		i;
	char	rgb_f;

	get_next_word(str, &w, pos);
	i = -1;
	rgb_f = 0;
	rgb = NULL;
	while (w[++i])
	{
		if (w[i] == ',')
			set_color_var(col, &rgb, &rgb_f);
		else
		{
			if (!rgb)
				init_rgb_str(&rgb);
			str_join_char(&rgb, w[i]);
		}
	}
	set_color_var(col, &rgb, &rgb_f);
	if (rgb_f != 3)
		prt_error(ERR_COL_VAL, 0);
	free(w);
}
