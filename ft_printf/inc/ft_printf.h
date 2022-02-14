/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:58:44 by msimon            #+#    #+#             */
/*   Updated: 2021/06/21 14:16:42 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define FT_PRINTF_NUMBER	"0123456789"

typedef struct s_flags
{
	unsigned char	f_neg;
	unsigned char	f_pos;
	unsigned char	f_zero;
	unsigned char	f_space;
	unsigned char	f_hash;
	unsigned char	f_l;
	unsigned char	f_ll;
	unsigned char	f_h;
	unsigned char	f_hh;
	int				f_size;
	int				f_prec;
}	t_flags;

int		ft_printf(const char *str, ...);
int		ft_print_fr_str(const char **str, va_list vl,
			unsigned long long int res_g);
void	ft_init_flag(t_flags *fl);
void	ft_set_flag(const char **str, t_flags *f, va_list vl);
int		ft_get_nmb(const char **str);
char	*ft_hex_str(unsigned long long int nmb,
			unsigned char up, t_flags *f);
char	*ft_nmb_str(t_flags flags, unsigned long long int u_val,
			char zn, size_t len);

#endif