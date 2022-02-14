/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_lib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:27:54 by msimon            #+#    #+#             */
/*   Updated: 2021/06/16 17:49:40 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_LIB_H
# define MINITALK_LIB_H

# include "libft.h"

typedef struct s_pid_str
{
	int				pid;
	char			*str;
	char			bit_count;
	unsigned char	ch;
}	t_pid_str;

void		pr_error(char *str);
void		pr_message(char *str);
t_pid_str	*found_el(t_list *lst, int pid);
t_pid_str	*add_el(int pid);
t_pid_str	*get_el_lst(t_list **lst, int pid);
void		del_el(t_list **lst, t_pid_str *el);

#endif