/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_copy_restore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 05:35:11 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 06:01:46 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst_copy	copy_arrs(t_list *arr_a, t_list *arr_b)
{
	t_lst_copy		res;
	unsigned int	i;

	res.arr_a = malloc(sizeof(t_list *) * (ft_lstsize(arr_a) + 1));
	res.arr_b = malloc(sizeof(t_list *) * (ft_lstsize(arr_b) + 1));
	if (!res.arr_a || !res.arr_b)
		pr_error("Error\n");
	i = 0;
	while (arr_a)
	{
		res.arr_a[i] = arr_a;
		arr_a = arr_a->next;
		i++;
	}
	res.arr_a[i] = 0;
	i = 0;
	while (arr_b)
	{
		res.arr_b[i] = arr_b;
		arr_b = arr_b->next;
		i++;
	}
	res.arr_b[i] = 0;
	return (res);
}

void	restore_arrs(t_list **arr_a, t_list **arr_b, t_lst_copy arrs)
{
	unsigned int	i;
	t_list			*el;

	*arr_a = arrs.arr_a[0];
	el = *arr_a;
	i = 1;
	while (el)
	{
		el->next = arrs.arr_a[i];
		el = arrs.arr_a[i];
		i++;
	}
	*arr_b = arrs.arr_b[0];
	el = *arr_b;
	i = 1;
	while (el)
	{
		el->next = arrs.arr_b[i];
		el = arrs.arr_b[i];
		i++;
	}
	free(arrs.arr_a);
	free(arrs.arr_b);
}
