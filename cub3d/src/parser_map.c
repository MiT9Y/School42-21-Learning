/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:35:45 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 06:50:14 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	parser_bg_f(t_main_data *md, char *w, char *str, int pos)
{
	if (!ft_strncmp("F", w, 2))
	{
		if (md->bg.flg_init & 2)
			prt_error(ERR_SET_COL, 0);
		parser_bg(&(md->bg.floor), str, pos);
		md->bg.flg_init |= 2;
	}
	else
	{
		if (md->bg.flg_init & 1)
			prt_error(ERR_SET_COL, 0);
		parser_bg(&(md->bg.ceil), str, pos);
		md->bg.flg_init |= 1;
	}
}

static void	parser_cmd(t_main_data *md, char *str)
{
	char	*w;
	int		pos;

	pos = get_next_word(str, &w, 0);
	if (!ft_strncmp("NO", w, 3))
		parser_wall(md, &(md->wall.n), str, pos);
	else if (!ft_strncmp("SO", w, 3))
		parser_wall(md, &(md->wall.s), str, pos);
	else if (!ft_strncmp("WE", w, 3))
		parser_wall(md, &(md->wall.w), str, pos);
	else if (!ft_strncmp("EA", w, 3))
		parser_wall(md, &(md->wall.e), str, pos);
	else if (!ft_strncmp("F", w, 2) || !ft_strncmp("C", w, 2))
		parser_bg_f(md, w, str, pos);
	else if (!ft_strncmp("DO", w, 3))
		parser_texs(md, &(md->door_tex_arr), str, pos);
	else if (!ft_strncmp("SP", w, 3))
		parser_texs(md, &(md->sp_tex_arr), str, pos);
	free(w);
}

static char	chk_cmd(char *str)
{
	char	*cmd;

	get_next_word(str, &cmd, 0);
	if (!ft_strncmp("NO", cmd, 3) || !ft_strncmp("SO", cmd, 3)
		|| !ft_strncmp("WE", cmd, 3) || !ft_strncmp("EA", cmd, 3)
		|| !ft_strncmp("F", cmd, 2) || !ft_strncmp("C", cmd, 2))
	{
		free(cmd);
		return (1);
	}
	free(cmd);
	return (0);
}

static void	parser_str(t_main_data *md, char *str, char *map_flg, char ***map)
{
	int	i;

	if (ft_strlen(str))
	{
		if (chk_cmd(str))
		{
			parser_cmd(md, str);
			if (*map_flg)
				*map_flg = 2;
		}
		else if (*map_flg != 2)
		{
			i = add_arr_el((void ***)map, ft_strlen(str) + 1);
			ft_memcpy((*map)[i], str, ft_strlen(str) + 1);
			*map_flg = 1;
		}
		else
			prt_error(ERR_CMD_F, 0);
	}
	else
		if (*map_flg)
			*map_flg = 2;
	free(str);
}

void	parsing_map(t_main_data *md, char *fn)
{
	int		fd;
	int		res_gnl;
	char	*line;
	char	map_flg;
	char	**map;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		prt_error(ERR_OPEN_F, 1);
	map_flg = 0;
	map = NULL;
	res_gnl = get_next_line(fd, &line);
	while (res_gnl > 0)
	{
		parser_str(md, line, &map_flg, &map);
		res_gnl = get_next_line(fd, &line);
	}
	if (res_gnl == 0)
		parser_str(md, line, &map_flg, &map);
	else
		prt_error(ERR_READ_F, 1);
	close(fd);
	set_map(md, map);
}
