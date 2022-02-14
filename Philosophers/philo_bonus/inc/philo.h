/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:38:14 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 20:13:35 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>
# include <signal.h>
# include "err_mess.h"

typedef long long int	t_time;

typedef struct s_main_data
{
	int				ph_count;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				l_eat;
	int				ph_l_eat;
	char			stop;
	struct timeval	start;
	sem_t			*sem;
	sem_t			*sem_stop;
	sem_t			*sem_eat;
}	t_main_data;

typedef struct s_philo
{
	pthread_t		thd;
	int				num;
	t_main_data		*md;
	struct timeval	ts_eat;
	pid_t			pid;
	t_time			etalon;
}	t_philo;

void	init(int argc, char **argv, t_main_data *md);
void	init_philos(t_main_data *md, t_philo **philos);
int		ft_atoi(const char *str);
void	pr_error(char *str, t_philo *ph);
t_time	get_ts(struct timeval b_ts);
void	*life_cycle_philo(void *arg);
void	write_ph_st(t_philo *ph, char *str);
void	synch_ts(t_philo *ph, int pause_val);
void	*stop_run(void *arg);

#endif