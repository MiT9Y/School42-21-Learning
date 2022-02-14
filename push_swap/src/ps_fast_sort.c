/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fast_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:34:18 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 17:17:45 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fa_sort(t_list **arr_a, t_list **arr_b, char **str, t_list *f_el)
{
	int			max;
	long int	mean;
	t_list		*next_el;
	t_list		*l_el;

	l_el = found_last(*arr_a);
	set_max_mean(&max, &mean, f_el);
	while (((t_lst_data *)f_el->content)->max == max)
	{
		next_el = f_el->next;
		if (((t_lst_data *)f_el->content)->nmb > (int)mean)
		{
			((t_lst_data *)f_el->content)->min = (int)(mean + 1);
			ps_r_ab(arr_a, str, "ra\n");
		}
		else
		{
			((t_lst_data *)f_el->content)->max = (int)mean;
			ps_p_ab(arr_a, arr_b, str, "pb\n");
		}
		if (f_el == l_el)
			break ;
		f_el = next_el;
	}
}

static void	la_sort(t_list **arr_a, t_list **arr_b, char **str, t_list *f_el)
{
	int			max;
	long int	mean;
	t_list		*next_el;
	t_list		*l_el;

	l_el = *arr_a;
	set_max_mean(&max, &mean, f_el);
	while (((t_lst_data *)f_el->content)->max == max)
	{
		next_el = found_pre(*arr_a, f_el);
		if (((t_lst_data *)f_el->content)->nmb > (int)mean)
		{
			((t_lst_data *)f_el->content)->min = (int)(mean + 1);
			ps_rr_ab(arr_a, str, "rra\n");
		}
		else
		{
			((t_lst_data *)f_el->content)->max = (int)mean;
			ps_rr_ab(arr_a, str, "rra\n");
			ps_p_ab(arr_a, arr_b, str, "pb\n");
		}
		if (f_el == l_el)
			break ;
		f_el = next_el;
	}
}

static void	fb_sort(t_list **arr_a, t_list **arr_b, char **str, t_list *f_el)
{
	int			max;
	long int	mean;
	t_list		*next_el;
	t_list		*l_el;

	l_el = found_last(*arr_b);
	set_max_mean(&max, &mean, f_el);
	while (((t_lst_data *)f_el->content)->max == max)
	{
		next_el = f_el->next;
		if (((t_lst_data *)f_el->content)->nmb > (int)mean)
		{
			((t_lst_data *)f_el->content)->min = (int)(mean + 1);
			ps_p_ab(arr_b, arr_a, str, "pa\n");
		}
		else
		{
			((t_lst_data *)f_el->content)->max = (int)mean;
			ps_r_ab(arr_b, str, "rb\n");
		}
		if (f_el == l_el)
			break ;
		f_el = next_el;
	}
}

static void	lb_sort(t_list **arr_a, t_list **arr_b, char **str, t_list *f_el)
{
	int			max;
	long int	mean;
	t_list		*next_el;
	t_list		*l_el;

	l_el = *arr_b;
	set_max_mean(&max, &mean, f_el);
	while (((t_lst_data *)f_el->content)->max == max)
	{
		next_el = found_pre(*arr_b, f_el);
		if (((t_lst_data *)f_el->content)->nmb > (int)mean)
		{
			((t_lst_data *)f_el->content)->min = (int)(mean + 1);
			ps_rr_ab(arr_b, str, "rrb\n");
			ps_p_ab(arr_b, arr_a, str, "pa\n");
		}
		else
		{
			((t_lst_data *)f_el->content)->max = (int)mean;
			ps_rr_ab(arr_b, str, "rrb\n");
		}
		if (f_el == l_el)
			break ;
		f_el = next_el;
	}
}

void	fast_sort(t_list **arr_a, t_list **arr_b,
		char **str, char block_pos)
{
	if (block_pos == 0)
		fa_sort(arr_a, arr_b, str, *arr_a);
	else if (block_pos == 1)
		la_sort(arr_a, arr_b, str, found_last(*arr_a));
	else if (block_pos == 2)
		fb_sort(arr_a, arr_b, str, *arr_b);
	else if (block_pos == 3)
		lb_sort(arr_a, arr_b, str, found_last(*arr_b));
}
