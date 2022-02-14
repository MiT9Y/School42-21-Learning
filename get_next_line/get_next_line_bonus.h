/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 09:00:27 by msimon            #+#    #+#             */
/*   Updated: 2021/05/27 21:19:36 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define BS_DEF 64
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BS_DEF
# elif BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE BS_DEF
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	int				fd;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	ft_strjoin(t_list *th, char *buf);
void	*ft_memmove(void *dest, const void *src, size_t n);
t_list	*get_fd_lst(t_list **f, int fd);

#endif