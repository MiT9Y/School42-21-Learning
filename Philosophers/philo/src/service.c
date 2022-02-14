/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:47:55 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 15:40:16 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	pr_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

t_time	get_ts(struct timeval b_ts)
{
	t_time			res;
	struct timeval	e_ts;

	gettimeofday(&e_ts, NULL);
	res = (e_ts.tv_sec - b_ts.tv_sec) * 1000000 + e_ts.tv_usec - b_ts.tv_usec;
	return (res / 1000);
}
