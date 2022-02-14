/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 08:59:57 by msimon            #+#    #+#             */
/*   Updated: 2021/05/27 22:15:02 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = -1;
	if (src < dest)
		while (n-- > 0)
			*(((char *)dest) + n) = *(((char *)src) + n);
	else
		while (++i < n)
			*(((char *)dest) + i) = *(((char *)src) + i);
	return (dest);
}

char	ft_strjoin(t_list *th, char *buf)
{
	char	*newstr;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(th->str);
	l2 = ft_strlen(buf);
	newstr = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!newstr)
		return (1);
	ft_memmove(newstr, th->str, l1);
	ft_memmove(newstr + l1, buf, l2);
	newstr[l1 + l2] = 0;
	free(th->str);
	th->str = newstr;
	return (0);
}

static void	get_fd_lst_init_el(t_list *el, int fd, t_list *last)
{
	el->str[0] = 0;
	el->fd = fd;
	el->prev = last;
	el->next = 0;
}

t_list	*get_fd_lst(t_list **f, int fd)
{
	t_list	*el;
	t_list	*last;

	el = *f;
	last = *f;
	while (el)
	{
		if (el->fd == fd)
			return (el);
		if (!el->next)
			last = el;
		el = el->next;
	}
	el = malloc(sizeof(t_list));
	if (!el)
		return (0);
	el->str = malloc(sizeof(char));
	if (!el->str)
		return (0);
	get_fd_lst_init_el(el, fd, last);
	if (last)
		last->next = el;
	else
		*f = el;
	return (el);
}
