/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:38:17 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 21:03:15 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_main_data *md, t_philo **philos)
{
	int	i;

	i = -1;
	md->start.tv_sec = 0;
	*philos = malloc(sizeof(t_philo) * md->ph_count);
	if (!*philos)
		pr_error(ERR_MEM, 0);
	memset(*philos, 0, sizeof(t_philo) * md->ph_count);
	while (++i < md->ph_count)
	{
		(*philos)[i].num = i + 1;
		(*philos)[i].md = md;
	}
}

void	init(int argc, char **argv, t_main_data *md)
{
	if (argc != 5 && argc != 6)
		pr_error(ERR_USAGE, 0);
	md->ph_count = ft_atoi(argv[1]);
	md->t_die = ft_atoi(argv[2]);
	md->t_eat = ft_atoi(argv[3]);
	md->t_sleep = ft_atoi(argv[4]);
	md->stop = 0;
	if (argc == 6)
		md->l_eat = ft_atoi(argv[5]);
	else
		md->l_eat = 0;
	if (md->ph_count < 1 || md->t_die < 1 || md->t_eat < 1
		|| md->t_sleep < 1 || md->l_eat < 0)
		pr_error(ERR_COUNT, 0);
	md->ph_l_eat = 0;
	md->stop = 0;
	sem_unlink("forks");
	sem_unlink("sforks");
	sem_unlink("eforks");
	md->sem = sem_open("forks", O_CREAT | O_EXCL, 0644, md->ph_count);
	md->sem_stop = sem_open("sforks", O_CREAT | O_EXCL, 0644, 1);
	md->sem_eat = sem_open("eforks", O_CREAT | O_EXCL, 0644, 0);
	if (md->sem == SEM_FAILED || md->sem_stop == SEM_FAILED
		|| md->sem_eat == SEM_FAILED)
		pr_error(ERR_SEM, 0);
}
