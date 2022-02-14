/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 07:53:54 by msimon            #+#    #+#             */
/*   Updated: 2021/07/11 07:54:10 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_s_ab(t_list **arr_, char **str, char *text)
{
	if (ft_s_ab(arr_))
		join_str(str, text);
}

void	ps_p_ab(t_list **src, t_list **dst, char **str, char *text)
{
	if (ft_p_ab(src, dst))
		join_str(str, text);
}

void	ps_r_ab(t_list **arr_, char **str, char *text)
{
	if (ft_r_ab(arr_))
		join_str(str, text);
}

void	ps_rr_ab(t_list **arr_, char **str, char *text)
{
	if (ft_rr_ab(arr_))
		join_str(str, text);
}
