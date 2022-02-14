/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:24:12 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 20:58:08 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_cycle_fork_philo(void *arg)
{
	t_philo			*ph;

	ph = (t_philo *)arg;
	ph->ts_eat.tv_sec = ph->md->start.tv_sec;
	ph->ts_eat.tv_usec = ph->md->start.tv_usec;
	ph->etalon = 0;
	while (1)
	{
		write_ph_st(ph, "%-16lld %d is thinking\n");
		sem_wait(ph->md->sem);
		write_ph_st(ph, "%-16lld %d has taken a fork\n");
		sem_wait(ph->md->sem);
		write_ph_st(ph, "%-16lld %d has taken a fork\n");
		write_ph_st(ph, "%-16lld %d is eating\n");
		gettimeofday(&(ph->ts_eat), NULL);
		synch_ts(ph, ph->md->t_eat);
		sem_post(ph->md->sem);
		sem_post(ph->md->sem);
		if (ph->md->l_eat)
			ph->md->ph_l_eat++;
		write_ph_st(ph, "%-16lld %d is sleeping\n");
		synch_ts(ph, ph->md->t_sleep);
	}
	return (0);
}

void	run_fork_philo(t_philo	*ph)
{
	pthread_t	th;
	char		f_eat;

	if (pthread_create(&(ph->thd), NULL, life_cycle_fork_philo, ph))
		pr_error(ERR_PTHREAD, 0);
	f_eat = 0;
	while (1)
	{
		usleep(1000);
		sem_wait(ph->md->sem_stop);
		if (get_ts(ph->ts_eat) > ph->md->t_die)
		{
			if (pthread_create(&th, NULL, stop_run, ph->md))
				pr_error(ERR_PTHREAD, 0);
			printf("%-16lld %d died\n", get_ts(ph->md->start), ph->num);
			exit(0);
		}
		if ((ph->md->ph_l_eat >= ph->md->l_eat || !ph->md->l_eat))
		{
			if (!f_eat)
				sem_post(ph->md->sem_eat);
			f_eat = 1;
		}
		sem_post(ph->md->sem_stop);
	}
}

void	*life_cycle_philo(void *arg)
{
	t_philo	*ph;
	int		status;

	ph = (t_philo *)arg;
	if (ph->md->start.tv_sec == 0)
		gettimeofday(&(ph->md->start), NULL);
	ph->pid = fork();
	if (ph->pid == 0)
		run_fork_philo(ph);
	else if (ph->pid > 0)
	{
		waitpid(ph->pid, &status, 0);
		ph->md->stop = 1;
		ph->pid = 0;
	}
	else
		pr_error(ERR_FORK, ph);
	return (0);
}
