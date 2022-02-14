/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 08:47:20 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 20:35:35 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_cmd2(char *ln, t_list **arr_a, t_list **arr_b)
{
	if (!ft_memcmp(ln, "sa", 2))
		ft_s_ab(arr_a);
	else if (!ft_memcmp(ln, "ra", 2))
		ft_r_ab(arr_a);
	else if (!ft_memcmp(ln, "sb", 2))
		ft_s_ab(arr_b);
	else if (!ft_memcmp(ln, "rb", 2))
		ft_r_ab(arr_b);
	else if (!ft_memcmp(ln, "pa", 2))
		ft_p_ab(arr_b, arr_a);
	else if (!ft_memcmp(ln, "pb", 2))
		ft_p_ab(arr_a, arr_b);
	else if (!ft_memcmp(ln, "ss", 2))
	{
		ft_s_ab(arr_a);
		ft_s_ab(arr_b);
	}
	else if (!ft_memcmp(ln, "rr", 2))
	{
		ft_r_ab(arr_a);
		ft_r_ab(arr_b);
	}
	else
		pr_error("Error\n");
}

static void	exec_cmd(char *ln, t_list **arr_a, t_list **arr_b)
{
	unsigned int	len;

	len = (unsigned int)ft_strlen(ln);
	if (len == 2)
		exec_cmd2(ln, arr_a, arr_b);
	else if (len == 3)
	{
		if (!ft_memcmp(ln, "rra", 3))
			ft_rr_ab(arr_a);
		else if (!ft_memcmp(ln, "rrb", 3))
			ft_rr_ab(arr_b);
		else if (!ft_memcmp(ln, "rrr", 3))
		{
			ft_rr_ab(arr_a);
			ft_rr_ab(arr_b);
		}
		else
			pr_error("Error\n");
	}
	else
		pr_error("Error\n");
}

static void	read_and_run(t_list **arr_a, t_list **arr_b)
{
	char	*line;
	int		res;

	line = 0;
	res = get_next_line(&line);
	while (res > 0)
	{
		exec_cmd(line, arr_a, arr_b);
		free(line);
		line = 0;
		res = get_next_line(&line);
	}
	if (ft_strlen(line) > 0 && res < 0)
		pr_error("Error\n");
	free(line);
}

int	main(int argc, char **argv)
{
	t_list	*arr_a;
	t_list	*arr_b;

	arr_a = 0;
	arr_b = 0;
	init_arr_a(&arr_a, argc, argv);
	read_and_run(&arr_a, &arr_b);
	if (is_sort(arr_a, INT_MIN, (unsigned int)ft_lstsize(arr_a))
		&& (unsigned int)ft_lstsize(arr_b) == 0)
		pr_message("OK\n");
	else
		pr_message("KO\n");
	return (0);
}
