/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 06:19:02 by msimon            #+#    #+#             */
/*   Updated: 2021/07/13 17:21:02 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "base.h"

# define BF_LEN 3

typedef struct s_lst_copy
{
	t_list	**arr_a;
	t_list	**arr_b;
}	t_lst_copy;

void		ps_s_ab(t_list **arr_, char **str, char *text);
void		ps_p_ab(t_list **src, t_list **dst, char **str, char *text);
void		ps_r_ab(t_list **arr_, char **str, char *text);
void		ps_rr_ab(t_list **arr_, char **str, char *text);
void		fast_sort(t_list **arr_a, t_list **arr_b,
				char **str, char block_pos);
void		bf_sort(t_list **arr_a, t_list **arr_b, char **str, char block_pos);
void		compress_str(char *str);
t_lst_copy	copy_arrs(t_list *arr_a, t_list *arr_b);
void		restore_arrs(t_list **arr_a, t_list **arr_b, t_lst_copy arrs);
void		set_max_mean(int *max, long int *mean, t_list *f_el);

#endif