/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:48:13 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 15:35:27 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void	exec_word2(char *w, t_list **arr_a, t_list **arr_b)
{
	if (!ft_memcmp(w, "sa", 2))
		ft_s_ab(arr_a);
	else if (!ft_memcmp(w, "ra", 2))
		ft_r_ab(arr_a);
	else if (!ft_memcmp(w, "sb", 2))
		ft_s_ab(arr_b);
	else if (!ft_memcmp(w, "rb", 2))
		ft_r_ab(arr_b);
	else if (!ft_memcmp(w, "pa", 2))
		ft_p_ab(arr_b, arr_a);
	else if (!ft_memcmp(w, "pb", 2))
		ft_p_ab(arr_a, arr_b);
	else if (!ft_memcmp(w, "ss", 2))
	{
		ft_s_ab(arr_a);
		ft_s_ab(arr_b);
	}
	else if (!ft_memcmp(w, "rr", 2))
	{
		ft_r_ab(arr_a);
		ft_r_ab(arr_b);
	}
	else
		pr_error("Error\n");
}

static void	exec_word3(char *w, t_list **arr_a, t_list **arr_b)
{
	if (!ft_memcmp(w, "rra", 3))
		ft_rr_ab(arr_a);
	else if (!ft_memcmp(w, "rrb", 3))
		ft_rr_ab(arr_b);
	else if (!ft_memcmp(w, "rrr", 3))
	{
		ft_rr_ab(arr_a);
		ft_rr_ab(arr_b);
	}
	else
		pr_error("Error\n");
}

void	exec_str(t_list **arr_a, t_list **arr_b, char *str)
{
	char	*w;

	w = str;
	while (*str)
	{
		if (*str == '\n')
		{
			if ((str - w) == 2)
				exec_word2(w, arr_a, arr_b);
			else if ((str - w) == 3)
				exec_word3(w, arr_a, arr_b);
			else
				pr_error("Error\n");
			w = str + 1;
		}
		str += 1;
	}
}
