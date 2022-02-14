/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_philo_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 20:31:33 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 18:41:31 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_etalon(t_philo *ph, t_time ts)
{
	t_time	ts_cor;

	ph->etalon += ts;
	if (ph->etalon > ph->md->etalon)
		ph->md->etalon = ph->etalon;
	ts_cor = get_ts(ph->md->start);
	if (ph->md->correc < ts_cor - ph->md->etalon)
		ph->md->correc = ts_cor - ph->md->etalon;
}

char	chk_mutex_lock(t_philo *ph, pthread_mutex_t *mut)
{
	struct timeval	b_ts;

	if (ph->md->error)
		return (1);
	gettimeofday(&b_ts, NULL);
	if (pthread_mutex_lock(mut))
	{
		ph->md->error = 1;
		pr_error(ERR_MTEX_LOCK);
		return (1);
	}
	set_etalon(ph, get_ts(b_ts));
	return (0);
}

char	chk_mutex_unlock(t_philo *ph, pthread_mutex_t *mut)
{
	if (ph->md->error)
		return (1);
	if (pthread_mutex_unlock(mut))
	{
		ph->md->error = 1;
		pr_error(ERR_MTEX_LOCK);
		return (1);
	}
	return (0);
}

char	write_ps_st(t_philo *ph, char *str)
{
	if (ph->md->error)
		return (1);
	if (pthread_mutex_lock(&(ph->md->stop_mut)))
	{
		ph->md->error = 1;
		pr_error(ERR_MTEX_LOCK);
		return (1);
	}
	printf(str, ph->md->etalon, ph->num);
	if (pthread_mutex_unlock(&(ph->md->stop_mut)))
	{
		ph->md->error = 1;
		pr_error(ERR_MTEX_LOCK);
		return (1);
	}
	return (0);
}

void	synch_ts(t_philo *ph, int pause_val)
{
	struct timeval	b_ts;

	ph->synch = pause_val - ph->synch;
	if (ph->synch > 0)
	{
		gettimeofday(&b_ts, NULL);
		usleep(ph->synch * 1000);
		ph->synch = get_ts(b_ts) - pause_val;
		if (ph->synch < 0)
			ph->synch = 0;
	}
	set_etalon(ph, pause_val);
}
