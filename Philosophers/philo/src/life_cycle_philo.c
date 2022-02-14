/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:24:12 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 19:29:35 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	take_forks(t_philo *ph, pthread_t **thd)
{
	if (ph->num % 2 == 0 && *thd)
	{
		pthread_detach(**thd);
		*thd = 0;
	}
	if (chk_mutex_lock(ph, ph->l_fork))
		return (1);
	if (write_ps_st(ph, "%-16lld %d has taken a fork\n"))
		return (1);
	if (ph->num == ph->md->ph_count && ph->num % 2 && *thd)
	{
		pthread_detach(**thd);
		*thd = 0;
	}
	if (chk_mutex_lock(ph, ph->r_fork))
		return (1);
	if (write_ps_st(ph, "%-16lld %d has taken a fork\n"))
		return (1);
	if (*thd)
	{
		pthread_detach(**thd);
		*thd = 0;
	}
	return (0);
}

static char	ph_eat(t_philo *ph, char *f_eat)
{
	if (write_ps_st(ph, "%-16lld %d is eating\n"))
		return (1);
	gettimeofday(&(ph->ts_eat), NULL);
	synch_ts(ph, ph->md->t_eat);
	ph->eat_count++;
	if (ph->md->l_eat && ph->eat_count >= ph->md->l_eat)
	{
		if (!*f_eat)
		{
			ph->md->ph_l_eat++;
			*f_eat = 1;
		}
	}
	return (0);
}

static char	ph_sleep(t_philo *ph)
{
	if (chk_mutex_unlock(ph, ph->r_fork) || chk_mutex_unlock(ph, ph->l_fork))
		return (1);
	if (write_ps_st(ph, "%-16lld %d is sleeping\n"))
		return (1);
	synch_ts(ph, ph->md->t_sleep);
	return (0);
}

void	*life_cycle_philo(void *arg)
{
	t_philo		*ph;
	pthread_t	*thd;
	char		f_eat;

	ph = (t_philo *)arg;
	thd = &(ph->thd);
	ph->synch = 0;
	ph->etalon = 0;
	f_eat = 0;
	while (1)
	{
		if (write_ps_st(ph, "%-16lld %d is thinking\n"))
			return (0);
		if (take_forks(ph, &thd) || ph->md->error)
			return (0);
		if (ph_eat(ph, &f_eat) || ph->md->error)
			return (0);
		if (ph_sleep(ph) || ph->md->error)
			return (0);
	}
	return (0);
}
