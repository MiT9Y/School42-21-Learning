/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bf_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:00:01 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 16:09:45 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_operation(char i)
{
	if (i == 0)
		return ("sa\n");
	else if (i == 1)
		return ("ra\n");
	else if (i == 2)
		return ("pb\n");
	else if (i == 3)
		return ("rra\n");
	else if (i == 4)
		return ("sb\n");
	else if (i == 5)
		return ("rb\n");
	else if (i == 6)
		return ("pa\n");
	else
		return ("rrb\n");
}

static char	*get_bf_str(unsigned int i)
{
	char	*res;

	res = 0;
	while (i / 8 > 0)
	{
		join_str(&res, get_operation(i % 8));
		i = (i / 8) - 1;
	}
	join_str(&res, get_operation(i % 8));
	return (res);
}

static void	init_val(int *min, unsigned int *len, t_list *el)
{
	*min = ((t_lst_data *)el->content)->min;
	*len = ((t_lst_data *)el->content)->max - *min + 1;
}

static char	*get_bf(t_list **arr_a, t_list **arr_b, int min, unsigned int len)
{
	char			*res;
	unsigned int	i;
	t_lst_copy		arrs;

	i = 0;
	while (1)
	{
		res = get_bf_str(i);
		arrs = copy_arrs(*arr_a, *arr_b);
		exec_str(arr_a, arr_b, res);
		if (is_sort(*arr_a, min, len))
			break ;
		restore_arrs(arr_a, arr_b, arrs);
		free(res);
		i++;
	}
	free(arrs.arr_a);
	free(arrs.arr_b);
	return (res);
}

void	bf_sort(t_list **arr_a, t_list **arr_b, char **str, char block_pos)
{
	int				min;
	unsigned int	len;
	char			*str_l;

	if (block_pos == 0)
		init_val(&min, &len, *arr_a);
	else if (block_pos == 1)
		init_val(&min, &len, found_last(*arr_a));
	else if (block_pos == 2)
		init_val(&min, &len, *arr_b);
	else
		init_val(&min, &len, found_last(*arr_b));
	if (!is_sort(*arr_a, min, len))
	{
		str_l = get_bf(arr_a, arr_b, min, len);
		join_str(str, str_l);
		free(str_l);
	}
}
