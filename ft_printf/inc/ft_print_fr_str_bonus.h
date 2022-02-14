/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fr_str_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:57:47 by msimon            #+#    #+#             */
/*   Updated: 2021/05/21 13:43:03 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_FR_STR_BONUS_H
# define FT_PRINT_FR_STR_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"

# define FT_PRINTF_FLAGS	"-0.*# +lh"
# define FT_PRINTF_TYPE		"cspdiuxX%n"
# define FT_PRINTF_ALL		"-0.*123456789# +lh"

int		ft_print_fr_str(const char **str, va_list vl,
			unsigned long long int res_g);
void	ft_init_var(t_flags *flags, char *prt_ch);
int		ft_print_chr(t_flags flags, char chr);
int		ft_print_str(t_flags flags, char *str);
int		ft_print_pnt(t_flags flags, void *pnt);
int		ft_print_hex(t_flags flags, unsigned long long int val, char ch);
int		ft_print_nmb(t_flags flags, unsigned long long int val, char ch);

#endif