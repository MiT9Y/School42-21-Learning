/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:47:55 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 20:14:57 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	long_nb(long int z)
{
	if (z > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long int	res;
	long int	i;
	long int	z;

	res = 0;
	i = 0;
	z = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 45)
	{
		z = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str > 47 && *str < 58)
	{
		res = (res * 10) + *str - 48;
		if (i > res)
			return (long_nb(z));
		i = res;
		str++;
	}
	return ((int)(res * z));
}

void	pr_error(char *str, t_philo *ph)
{
	printf("%s\n", str);
	if (ph)
	{
		sem_unlink("forks");
		sem_close(ph->md->sem);
		sem_unlink("sforks");
		sem_close(ph->md->sem_stop);
	}
	exit(1);
}

t_time	get_ts(struct timeval b_ts)
{
	t_time			res;
	struct timeval	e_ts;

	gettimeofday(&e_ts, NULL);
	res = (e_ts.tv_sec - b_ts.tv_sec) * 1000000 + e_ts.tv_usec - b_ts.tv_usec;
	return (res / 1000);
}

void	*stop_run(void *arg)
{
	t_main_data	*md;

	md = (t_main_data *)arg;
	sem_wait(md->sem_stop);
	return (0);
}
