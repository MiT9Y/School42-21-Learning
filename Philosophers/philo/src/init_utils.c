/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:38:17 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 17:24:17 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	init_forks(t_main_data *md, pthread_mutex_t **forks)
{
	int	i;

	i = -1;
	*forks = malloc(sizeof(pthread_mutex_t) * md->ph_count);
	if (!*forks)
		return (pr_error(ERR_MEM));
	while (++i < md->ph_count)
		if (pthread_mutex_init(*forks + i, NULL))
			return (pr_error(ERR_MUTEX));
	return (1);
}

char	init_philos(t_main_data *md, pthread_mutex_t **forks, t_philo **philos)
{
	int	i;

	if (!init_forks(md, forks))
		return (0);
	i = -1;
	*philos = malloc(sizeof(t_philo) * md->ph_count);
	if (!*philos)
		return (pr_error(ERR_MEM));
	memset(*philos, 0, sizeof(t_philo) * md->ph_count);
	while (++i < md->ph_count)
	{
		(*philos)[i].num = i + 1;
		(*philos)[i].md = md;
		(*philos)[i].eat_count = 0;
		(*philos)[i].r_fork = *forks + i;
		if (i)
			(*philos)[i].l_fork = *forks + i - 1;
		else
			(*philos)[i].l_fork = *forks + md->ph_count - 1;
	}
	return (1);
}

char	init(int argc, char **argv, t_main_data *md)
{
	if (argc != 5 && argc != 6)
		return (pr_error(ERR_USAGE));
	md->ph_count = ft_atoi(argv[1]);
	md->t_die = ft_atoi(argv[2]);
	md->t_eat = ft_atoi(argv[3]);
	md->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		md->l_eat = ft_atoi(argv[5]);
	else
		md->l_eat = 0;
	md->ph_l_eat = 0;
	if (pthread_mutex_init(&(md->stop_mut), NULL))
		return (pr_error(ERR_MUTEX));
	if (md->ph_count < 1 || md->t_die < 1 || md->t_eat < 1
		|| md->t_sleep < 1 || md->l_eat < 0)
		return (pr_error(ERR_COUNT));
	md->etalon = 0;
	md->correc = 0;
	md->error = 0;
	return (1);
}
