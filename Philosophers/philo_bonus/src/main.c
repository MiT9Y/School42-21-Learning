/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:39:48 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 20:51:00 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*chk_eat_all(void *arg)
{
	t_main_data	*md;
	int			i;
	pthread_t	th;

	md = (t_main_data *)arg;
	i = -1;
	while (++i < md->ph_count)
		sem_wait(md->sem_eat);
	if (pthread_create(&th, NULL, stop_run, md))
		pr_error(ERR_PTHREAD, 0);
	printf(EAT_MSG, get_ts(md->start), md->l_eat);
	md->stop = 1;
	return (0);
}

static void	clear_all(t_main_data md, t_philo *ph)
{
	free(ph);
	(void)md;
	sem_unlink("forks");
	sem_unlink("sforks");
	sem_unlink("eforks");
	sem_close(md.sem);
	sem_close(md.sem_stop);
}

int	main(int argc, char **argv)
{
	t_main_data	md;
	t_philo		*ph;
	int			i;
	pthread_t	th;

	init(argc, argv, &md);
	init_philos(&md, &ph);
	i = -1;
	if (md.l_eat)
		if (pthread_create(&(th), NULL, chk_eat_all, &md))
			pr_error(ERR_PTHREAD, ph + i);
	while (++i < md.ph_count)
		if (pthread_create(&(ph[i].thd), NULL, life_cycle_philo, ph + i))
			pr_error(ERR_PTHREAD, ph + i);
	while (!md.stop)
	{
		usleep(1000);
	}
	i = -1;
	while (++i < md.ph_count)
		if (ph[i].pid)
			kill(ph[i].pid, SIGSTOP);
	clear_all(md, ph);
	return (0);
}
