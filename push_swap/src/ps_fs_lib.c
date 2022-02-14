/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fs_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:05:39 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 17:06:02 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_max_mean(int *max, long int *mean, t_list *f_el)
{
	*max = ((t_lst_data *)f_el->content)->max;
	*mean = ((long int)*max
			+ (long int)((t_lst_data *)f_el->content)->min - 1) / 2;
}
