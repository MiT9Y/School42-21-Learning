/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:51:36 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 18:41:48 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	run_cycle(t_main_data *md, t_philo *ph, char key)
{
	int	i;

	i = -1;
	while (++i < md->ph_count)
	{
		ph[i].ts_eat.tv_sec = ph[i].md->start.tv_sec;
		ph[i].ts_eat.tv_usec = ph[i].md->start.tv_usec;
		if (i % 2 == key)
			if (pthread_create(&(ph[i].thd), NULL, life_cycle_philo, &(ph[i])))
				return (pr_error(ERR_PTHREAD));
	}
	return (1);
}

char	run_philos(t_main_data *md, t_philo *ph)
{
	int	i;

	gettimeofday(&(md->start), NULL);
	if (!run_cycle(md, ph, 0))
		return (0);
	i = -1;
	while (++i < md->ph_count)
	{
		if (i % 2 == 0)
			pthread_join(ph[i].thd, NULL);
	}
	if (!run_cycle(md, ph, 1))
		return (0);
	i = -1;
	while (++i < md->ph_count)
	{
		if (i % 2 == 1)
			pthread_join(ph[i].thd, NULL);
	}
	return (1);
}
