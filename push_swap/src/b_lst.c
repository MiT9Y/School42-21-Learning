/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_lst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 21:05:18 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 15:46:10 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

t_list	*ft_lstfound_el(t_list *arr_, int nmb)
{
	t_list	*res;

	res = 0;
	while (arr_)
	{
		if (((t_lst_data *)arr_->content)->nmb == nmb)
			return (arr_);
		arr_ = arr_->next;
	}	
	return (res);
}

char	is_sort(t_list *arr_, int min, unsigned int len)
{
	if (arr_)
	{
		if (((t_lst_data *)arr_->content)->nmb != min)
			return (0);
		while (arr_->next && len-- > 1)
		{
			if (((t_lst_data *)arr_->content)->nmb
				!= ((t_lst_data *)arr_->next->content)->nmb - 1)
				return (0);
			arr_ = arr_->next;
		}
	}
	if (len > 1)
		return (0);
	return (1);
}

t_list	*found_last(t_list *arr_)
{
	if (arr_)
	{
		while (arr_->next)
			arr_ = arr_->next;
	}
	return (arr_);
}

t_list	*found_pre(t_list *arr_, t_list *el)
{
	if (arr_)
	{
		while (arr_->next)
		{
			if (arr_->next == el)
				return (arr_);
			arr_ = arr_->next;
		}
	}
	return (0);
}
