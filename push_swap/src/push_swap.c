/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 06:27:13 by msimon            #+#    #+#             */
/*   Updated: 2021/07/14 21:04:27 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	set_min(t_list *arr_, long int *min, char flag)
{
	*min = ((t_lst_data *)arr_->content)->min;
	return (flag);
}

static char	found_b_pos(t_list *arr_a, t_list *arr_b
	, long int *min, long int max)
{
	if (arr_a)
	{
		if (((t_lst_data *)arr_a->content)->max == max)
			return (set_min(arr_a, min, 0));
		while (arr_a->next)
			arr_a = arr_a->next;
		if (((t_lst_data *)arr_a->content)->max == max)
			return (set_min(arr_a, min, 1));
	}
	if (arr_b)
	{
		if (((t_lst_data *)arr_b->content)->max == max)
			return (set_min(arr_b, min, 2));
		while (arr_b->next)
			arr_b = arr_b->next;
		if (((t_lst_data *)arr_b->content)->max == max)
			return (set_min(arr_b, min, 3));
	}
	pr_error("Error\n");
	return (-1);
}

static void	ft_sort(t_list **arr_a, t_list **arr_b, char **str)
{
	long int	max;
	long int	min;
	char		block_pos;

	max = INT_MIN + (unsigned int)ft_lstsize(*arr_a) - 1;
	while ((max - INT_MIN + 1) > BF_LEN)
	{
		block_pos = found_b_pos(*arr_a, *arr_b, &min, max);
		if ((max - min + 1) > BF_LEN)
			fast_sort(arr_a, arr_b, str, block_pos);
		else
		{
			bf_sort(arr_a, arr_b, str, block_pos);
			max = min - 1;
		}
	}
	block_pos = found_b_pos(*arr_a, *arr_b, &min, max);
	bf_sort(arr_a, arr_b, str, block_pos);
}

int	main(int argc, char **argv)
{
	t_list	*arr_a;
	t_list	*arr_b;
	char	*str;

	arr_a = 0;
	arr_b = 0;
	str = 0;
	init_arr_a(&arr_a, argc, argv);
	if (is_sort(arr_a, INT_MIN, (unsigned int)ft_lstsize(arr_a)))
		pr_message("");
	if ((unsigned int)ft_lstsize(arr_a) < 6)
		bf_sort(&arr_a, &arr_b, &str, 0);
	else
		ft_sort(&arr_a, &arr_b, &str);
	compress_str(str);
	pr_message(str);
	return (0);
}
