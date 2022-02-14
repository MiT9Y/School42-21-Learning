/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:30:20 by msimon            #+#    #+#             */
/*   Updated: 2021/06/15 15:40:26 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_lib.h"

t_pid_str	*found_el(t_list *lst, int pid)
{
	t_pid_str	*res;

	res = 0;
	while (lst)
	{
		if (((t_pid_str *) lst->content)->pid == pid)
			return (lst->content);
		lst = lst->next;
	}
	return (res);
}

t_pid_str	*add_el(int pid)
{
	t_pid_str	*res;

	res = malloc(sizeof(t_pid_str));
	if (!res)
		pr_error("Error malloc.\n");
	res->pid = pid;
	res->bit_count = 0;
	res->ch = 0;
	res->str = malloc(sizeof(char));
	if (!res->str)
		pr_error("Error malloc.\n");
	res->str[0] = 0;
	return (res);
}

t_pid_str	*get_el_lst(t_list **lst, int pid)
{
	t_pid_str	*res;

	res = found_el(*lst, pid);
	if (res)
		return (res);
	res = add_el(pid);
	ft_lstadd_back(lst, ft_lstnew(res));
	return (res);
}

void	del_el(t_list **lst, t_pid_str *el)
{
	t_list	*fd_el;
	t_list	*front_el;

	fd_el = *lst;
	front_el = 0;
	while (fd_el)
	{
		if (fd_el->content == el)
			break ;
		front_el = fd_el;
		fd_el = fd_el->next;
	}
	free(el->str);
	el->str = 0;
	free(el);
	if (fd_el)
	{
		if (!front_el)
			*lst = fd_el->next;
		else
			front_el->next = fd_el->next;
		fd_el->next = 0;
		free(fd_el);
	}
}
