/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:39:48 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 19:30:29 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	ft_chk_to_die(t_main_data *md, t_time ts_eat, int num)
{	
	if (ts_eat - md->correc > (t_time)md->t_die
		|| md->ph_l_eat >= md->ph_count || md->error)
	{
		if (pthread_mutex_lock(&(md->stop_mut)))
		{
			md->error = 1;
			pr_error(ERR_MTEX_LOCK);
		}
		if (md->error)
			return (1);
		else if (md->ph_l_eat >= md->ph_count)
			printf(EAT_MSG, md->etalon, md->l_eat);
		else
			printf("%-16lld %d died\n", get_ts(md->start)
				- md->correc, num);
		return (1);
	}
	return (0);
}

static void	chk_to_die(t_main_data *md, t_philo *ph)
{
	int	i;

	while (1)
	{		
		i = -1;
		usleep(1000);
		while (++i < md->ph_count)
			if (ft_chk_to_die(md, get_ts(ph[i].ts_eat), ph[i].num))
				return ;
	}
}

static void	clear_all(t_main_data md, t_philo *philos
	, pthread_mutex_t *forks)
{
	int	i;

	memset(philos, 0, sizeof(t_philo) * md.ph_count);
	free(philos);
	i = -1;
	while (++i < md.ph_count)
		pthread_mutex_destroy(forks + i);
	memset(forks, 0, sizeof(pthread_mutex_t) * md.ph_count);
	free(forks);
}

int	main(int argc, char **argv)
{
	t_main_data		md;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (init(argc, argv, &md))
	{
		if (init_philos(&md, &forks, &philos))
		{			
			if (run_philos(&md, philos))
				chk_to_die(&md, philos);
			clear_all(md, philos, forks);
		}
	}
	return (0);
}
