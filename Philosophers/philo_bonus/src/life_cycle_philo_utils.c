/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_philo_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:54:41 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 20:11:59 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_ph_st(t_philo *ph, char *str)
{
	sem_wait(ph->md->sem_stop);
	printf(str, get_ts(ph->md->start), ph->num);
	sem_post(ph->md->sem_stop);
}

void	synch_ts(t_philo *ph, int pause_val)
{
	struct timeval	ts_b;

	ph->etalon = pause_val - ph->etalon;
	if (ph->etalon > 0)
	{
		gettimeofday(&ts_b, NULL);
		usleep(ph->etalon * 1000);
		ph->etalon = get_ts(ts_b) - ph->etalon;
		if (ph->etalon < 0)
			ph->etalon = 0;
	}
}
