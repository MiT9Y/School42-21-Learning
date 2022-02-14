/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:25:31 by msimon            #+#    #+#             */
/*   Updated: 2021/11/23 08:12:58 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	arr_len(void **arr)
{
	int	res;

	res = -1;
	if (!arr)
		return (res);
	while (arr[++res])
		;
	return (res);
}

void	init_arr(void ***arr)
{
	*arr = malloc(sizeof(void *));
	if (!*arr)
		prt_error(ERR_MEM, 0);
	(*arr)[0] = NULL;
}

int	add_arr_el(void ***arr, size_t size)
{
	void	**buf;
	int		len;
	int		i;

	if (!*arr)
		init_arr(arr);
	buf = *arr;
	len = arr_len(buf);
	*arr = malloc(sizeof(void *) * (len + 2));
	if (!*arr)
		prt_error(ERR_MEM, 0);
	(*arr)[len + 1] = NULL;
	(*arr)[len] = malloc(size);
	if (!(*arr)[len])
		prt_error(ERR_MEM, 0);
	i = -1;
	while (++i < len)
		(*arr)[i] = buf[i];
	free(buf);
	return (len);
}

void	drop_arr(void **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
