/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_compress_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:19:29 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 21:02:00 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ss_chage(char *str, size_t *len)
{
	char	*p;

	p = ft_strnstr(str, "\nsa\nsb\n", *len);
	while (p)
	{
		ft_memcpy(p, "\nss\n", 4);
		ft_memcpy(p + 4, p + 7, *len + (p - str) - 6);
		*len -= 3;
		p = ft_strnstr(str, "\nsa\nsb\n", *len);
	}
	p = ft_strnstr(str, "\nsb\nsa\n", *len);
	while (p)
	{
		ft_memcpy(p, "\nss\n", 4);
		ft_memcpy(p + 4, p + 7, *len + (p - str) - 6);
		*len -= 3;
		p = ft_strnstr(str, "\nsb\nsa\n", *len);
	}
}

static void	rr_chage(char *str, size_t *len)
{
	char	*p;

	p = ft_strnstr(str, "\nra\nrb\n", *len);
	while (p)
	{
		ft_memcpy(p, "\nrr\n", 4);
		ft_memcpy(p + 4, p + 7, *len + (p - str) - 6);
		*len -= 3;
		p = ft_strnstr(str, "\nra\nrb\n", *len);
	}
	p = ft_strnstr(str, "\nrb\nra\n", *len);
	while (p)
	{
		ft_memcpy(p, "\nrr\n", 4);
		ft_memcpy(p + 4, p + 7, *len + (p - str) - 6);
		*len -= 3;
		p = ft_strnstr(str, "\nrb\nra\n", *len);
	}
}

static void	rrr_chage(char *str, size_t *len)
{
	char	*p;

	p = ft_strnstr(str, "rra\nrrb", *len);
	while (p)
	{
		ft_memcpy(p, "rrr", 3);
		ft_memcpy(p + 3, p + 7, *len + (p - str) - 6);
		*len -= 4;
		p = ft_strnstr(str, "rra\nrrb", *len);
	}
	p = ft_strnstr(str, "rrb\nrra", *len);
	while (p)
	{
		ft_memcpy(p, "rrr", 3);
		ft_memcpy(p + 3, p + 7, *len + (p - str) - 6);
		*len -= 4;
		p = ft_strnstr(str, "rrb\nrra", *len);
	}
}

void	compress_str(char *str)
{
	size_t	len;

	if (str)
	{
		len = ft_strlen(str);
		ss_chage(str, &len);
		rr_chage(str, &len);
		rrr_chage(str, &len);
	}
}
