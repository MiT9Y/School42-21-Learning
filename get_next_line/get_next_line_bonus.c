/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 08:58:35 by msimon            #+#    #+#             */
/*   Updated: 2021/05/27 22:11:56 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	clean_this(t_list **f, t_list *th, char *b, int res)
{
	if (res == -1 && th)
	{
		if (!th->prev && !th->next)
			*f = 0;
		else if (!th->prev)
		{
			*f = th->next;
			(*f)->prev = 0;
		}
		else if (!th->next)
			th->prev->next = 0;
		else
		{
			th->prev->next = th->next;
			th->next->prev = th->prev;
		}
		th->prev = 0;
		th->next = 0;
		free(th->str);
		th->str = 0;
		free(th);
	}
	free(b);
	return (res);
}

static char	found_nl(t_list *el, char **ln, int *err)
{
	size_t	i;

	i = -1;
	while (el->str[++i])
	{
		if (el->str[i] == '\n')
		{
			*ln = malloc(i + 1);
			if (!ln)
			{
				*err = -1;
				return (1);
			}
			*err = 1;
			ft_memmove(*ln, el->str, i);
			(*ln)[i] = 0;
			ft_memmove(el->str, el->str + i + 1,
				ft_strlen(el->str + i + 1) + 1);
			return (1);
		}
	}
	return (0);
}

static char	ft_eof(t_list **f, t_list *el, char **ln, char *b)
{
	size_t	i;

	i = ft_strlen(el->str);
	*ln = malloc(i + 1);
	if (!ln)
		return (clean_this(f, el, b, -1));
	(*ln)[i] = 0;
	ft_memmove(*ln, el->str, i);
	clean_this(f, el, b, -1);
	return (0);
}

static ssize_t	read_block(int fd, char *buf, ssize_t *rlen)
{
	*rlen = read(fd, buf, BUFFER_SIZE);
	return (*rlen);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*first = 0;
	t_list			*this;
	char			*buf;
	ssize_t			rlen;
	int				err;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	this = get_fd_lst(&first, fd);
	if (!buf || ! this || !line)
		return (clean_this(&first, this, buf, -1));
	if (found_nl(this, line, &err))
		return (clean_this(&first, this, buf, err));
	if (read_block(fd, buf, &rlen) < 0)
		return (clean_this(&first, this, buf, -1));
	while (rlen)
	{
		buf[rlen] = 0;
		if (ft_strjoin(this, buf))
			return (clean_this(&first, this, buf, -1));
		if (found_nl(this, line, &err))
			return (clean_this(&first, this, buf, err));
		if (read_block(fd, buf, &rlen) < 0)
			return (clean_this(&first, this, buf, -1));
	}
	return (ft_eof(&first, this, line, buf));
}
