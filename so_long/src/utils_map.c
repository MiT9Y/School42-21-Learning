/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:25:36 by msimon            #+#    #+#             */
/*   Updated: 2021/11/16 11:31:07 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_main.h"

static void	block_ch(t_so_long *sl, char *fl, int i, int j)
{
	if (sl->map.data[i][j] != '1' && (i == 0 || i == sl->map.y_max - 1
		|| j == 0 || j == sl->map.x_max - 1))
		pr_error(ERR_MAP_BORDER, 0);
	else if (sl->map.data[i][j] == 'P')
	{
		if (!(*fl & 1))
			*fl |= 1;
		else
			pr_error(ERR_MAP_PLAYER, 0);
	}
	else if (sl->map.data[i][j] == 'E')
	{
		if (!(*fl & 2))
			*fl |= 2;
		else
			pr_error(ERR_MAP_EXIT, 0);
	}
	else if (sl->map.data[i][j] != '0' && sl->map.data[i][j] != '1'
		&& sl->map.data[i][j] != 'C')
		pr_error(ERR_MAP_UNKNOWN, 0);
}

static void	map_ch(t_so_long *sl)
{
	int		i;
	int		j;
	char	pl_ex_flag;

	pl_ex_flag = 0;
	sl->map.count_coll = 0;
	i = -1;
	while (++i < sl->map.y_max)
	{
		j = -1;
		if (sl->map.x_max != (int)ft_strlen(sl->map.data[i]))
			pr_error(ERR_MAP_SIZE, 0);
		while (++j < sl->map.x_max)
		{
			block_ch(sl, &pl_ex_flag, i, j);
			if (sl->map.data[i][j] == 'C')
				sl->map.count_coll++;
			if (sl->map.count_coll < 0)
				pr_error(ERR_INT_OVERFLOW, 0);
		}
	}
	if (!sl->map.count_coll || !(pl_ex_flag & 1) || !(pl_ex_flag & 2))
		pr_error(ERR_MAP_COUNT, 0);
}

static char	ch_type_f(char *fn)
{
	size_t	len;

	len = ft_strlen(fn);
	if (len > 3)
	{
		if (!ft_memcmp(&(fn[len - 4]), ".ber", 4))
			return (0);
	}
	return (1);
}

void	init_map(t_so_long *sl, char *fn)
{
	int		fd;
	int		res_gnl;
	char	*line;

	if (ch_type_f(fn))
		pr_error(ERR_TYPE_F, 0);
	fd = open(fn, O_RDONLY);
	if (fd < 0)
		pr_error(ERR_OPEN_F, 1);
	sl->map.data = 0;
	sl->map.x_max = 0;
	sl->map.y_max = 0;
	res_gnl = get_next_line(fd, &line);
	while (res_gnl > 0)
	{
		join_line_to_map(&(sl->map), line);
		res_gnl = get_next_line(fd, &line);
	}
	if (res_gnl == 0)
		join_line_to_map(&(sl->map), line);
	else
		pr_error(ERR_READ_F, 1);
	map_ch(sl);
	sl->map.flag_exit = 0;
	sl->map.end_game = 0;
}
