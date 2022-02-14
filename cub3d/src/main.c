/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:01:44 by msimon            #+#    #+#             */
/*   Updated: 2021/12/03 14:44:47 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	ch_type_f(char *fn)
{
	size_t	len;

	len = ft_strlen(fn);
	if (len > 3)
	{
		if (!ft_memcmp(&(fn[len - 4]), ".cub", 4))
			return (0);
	}
	return (1);
}

/*init_md инициализация исходных данных*/
/*parsing_map разбор файла с картой*/
/*ch_map проверка на заполненность всех необходимых данных и замкнутости карты*/
int	main(int argc, char **argv)
{
	t_main_data	md;

	if (argc != 2)
		prt_error(ERR_USAGE, 0);
	if (ch_type_f(argv[1]))
		prt_error(ERR_TYPE_F, 0);
	init_md(&md);
	parsing_map(&md, argv[1]);
	ch_map(&md);
	init_hook(&md);
	mlx_loop_hook(md.scr.mlx, render_next_frame, &md);
	mlx_loop(md.scr.mlx);
	return (0);
}
