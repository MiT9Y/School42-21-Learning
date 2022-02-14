/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_init_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:56:30 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 15:36:06 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static char	ft_atoi_plus(char **str, t_lst_data *el_d)
{
	long int	res;
	char		z;

	z = 1;
	res = 0;
	while ((**str > 8 && **str < 14) || **str == 32)
		*str += 1;
	if (!**str)
		return (1);
	if (**str == 45)
		z = -1;
	if (**str == 43 || **str == 45)
		*str += 1;
	if (!(**str > 47 && **str < 58))
		return (0);
	while (**str > 47 && **str < 58)
	{
		res = (res * 10) + **str - 48;
		if ((long int)(res * z) < INT_MIN || (long int)(res * z) > INT_MAX)
			return (0);
		*str += 1;
	}
	el_d->nmb = (int)(res * z);
	return (1);
}

static void	index_arr(t_list *arr_)
{
	unsigned int	len;
	int				min_nmb;
	int				nmb;
	t_list			*el;
	t_list			*f_el;

	len = (unsigned int)ft_lstsize(arr_);
	min_nmb = INT_MIN;
	while (len-- > 0)
	{
		el = arr_;
		nmb = INT_MAX;
		while (el)
		{
			if (((t_lst_data *)el->content)->nmb >= min_nmb
				&& ((t_lst_data *)el->content)->nmb <= nmb)
			{
				nmb = ((t_lst_data *)el->content)->nmb;
				f_el = el;
			}
			el = el->next;
		}
		((t_lst_data *)f_el->content)->nmb = min_nmb;
		min_nmb++;
	}
}

static int	init_el(char **arg, t_list **arr_a)
{
	int			res;
	t_lst_data	*el_d;
	t_list		*new_el;

	res = 0;
	el_d = malloc(sizeof(t_lst_data));
	if (!el_d)
		pr_error("Error\n");
	if (!ft_atoi_plus(arg, el_d))
		pr_error("Error\n");
	if (*(*arg -1) > 47 && *(*arg -1) < 58)
	{
		res = 1;
		if (ft_lstfound_el(*arr_a, el_d->nmb))
			pr_error("Error\n");
		new_el = ft_lstnew(el_d);
		if (!new_el)
			pr_error("Error\n");
		ft_lstadd_back(arr_a, new_el);
	}
	else
		free(el_d);
	return (res);
}

static void	set_range(t_list *arr_, int max)
{
	while (arr_)
	{
		((t_lst_data *)arr_->content)->min = INT_MIN;
		((t_lst_data *)arr_->content)->max = max;
		arr_ = arr_->next;
	}
}

void	init_arr_a(t_list **arr_a, int argc, char **argv)
{
	int				i;
	char			**arg;
	unsigned int	count;

	i = 0;
	if (argc == 1)
		pr_message("");
	while (++i < argc)
	{
		arg = &(argv[i]);
		count = 0;
		while (**arg)
			count += init_el(arg, arr_a);
		if (!count)
			pr_error("Error\n");
	}
	index_arr(*arr_a);
	set_range(*arr_a, INT_MIN + (unsigned int)ft_lstsize(*arr_a) - 1);
}
