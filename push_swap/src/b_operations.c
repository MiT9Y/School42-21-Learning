/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:37:53 by msimon            #+#    #+#             */
/*   Updated: 2021/07/10 07:32:48 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

char	ft_s_ab(t_list **arr_)
{
	t_list	*buf;
	t_list	*buf_next;

	if (*arr_)
	{
		if ((*arr_)->next)
		{
			buf = *arr_;
			buf_next = (*arr_)->next->next;
			*arr_ = (*arr_)->next;
			(*arr_)->next = buf;
			(*arr_)->next->next = buf_next;
			return (1);
		}
	}
	return (0);
}

char	ft_p_ab(t_list **src, t_list **dst)
{
	t_list	*buf;

	if (*src)
	{
		buf = *src;
		*src = (*src)->next;
		ft_lstadd_front(dst, buf);
		return (1);
	}
	return (0);
}

char	ft_r_ab(t_list **arr_)
{
	t_list	*buf;

	if (*arr_)
	{
		if ((*arr_)->next)
		{
			buf = *arr_;
			*arr_ = buf->next;
			buf->next = 0;
			ft_lstadd_back(arr_, buf);
			return (1);
		}
	}
	return (0);
}

char	ft_rr_ab(t_list **arr_)
{
	t_list	*buf;
	t_list	*before_buf;

	if (*arr_)
	{
		buf = *arr_;
		before_buf = 0;
		while (buf->next)
		{
			before_buf = buf;
			buf = buf->next;
		}
		if (before_buf)
		{
			before_buf->next = 0;
			ft_lstadd_front(arr_, buf);
			return (1);
		}
	}
	return (0);
}
