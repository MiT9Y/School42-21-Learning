/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:16:08 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 17:20:13 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_lst_data
{
	int	nmb;
	int	min;
	int	max;
}	t_lst_data;

void	pr_error(char *str);
void	pr_message(char *str);
t_list	*ft_lstfound_el(t_list *arr_, int nmb);
char	is_sort(t_list *arr_, int min, unsigned int len);
t_list	*found_last(t_list *arr_);
t_list	*found_pre(t_list *arr_, t_list *el);
char	ft_s_ab(t_list **arr_);
char	ft_p_ab(t_list **src, t_list **dst);
char	ft_r_ab(t_list **arr_);
char	ft_rr_ab(t_list **arr_);
void	init_arr_a(t_list **arr_a, int argc, char **argv);
void	join_str(char **str, char *buf);
void	exec_str(t_list **arr_a, t_list **arr_b, char *str);

#endif