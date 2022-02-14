/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:38:14 by msimon            #+#    #+#             */
/*   Updated: 2021/08/20 17:23:56 by msimon           ###   ########.fr       */
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
	struct timeval	start;
	pthread_mutex_t	stop_mut;
	char			error;
	t_time			etalon;
	t_time			correc;
}	t_main_data;

typedef struct s_philo
{
	pthread_t		thd;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				num;
	t_main_data		*md;
	struct timeval	ts_eat;
	int				eat_count;
	t_time			synch;
	t_time			etalon;
}	t_philo;

int		ft_atoi(const char *str);
char	pr_error(char *str);
char	init(int argc, char **argv, t_main_data *md);
char	init_philos(t_main_data *md, pthread_mutex_t **forks, t_philo **philos);
t_time	get_ts(struct timeval b_ts);
char	run_philos(t_main_data *md, t_philo *ph);
void	*life_cycle_philo(void *arg);
char	chk_mutex_lock(t_philo *ph, pthread_mutex_t *mut);
char	chk_mutex_unlock(t_philo *ph, pthread_mutex_t *mut);
char	write_ps_st(t_philo *ph, char *str);
void	synch_ts(t_philo *ph, int pause_val);

#endif