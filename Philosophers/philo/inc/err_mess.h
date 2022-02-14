/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_mess.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:38:43 by msimon            #+#    #+#             */
/*   Updated: 2021/08/14 20:41:52 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MESS_H
# define ERR_MESS_H

# define ERR_USAGE		"Error usage: ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"
# define ERR_COUNT		"Error number_of_philosophers and time_to_die \
and time_to_eat and time_to_sleep and \
[number_of_times_each_philosopher_must_eat] must be more than 0"
# define ERR_MEM		"Error memory was allocated incorrectly"
# define ERR_MUTEX		"Error mutex was created incorrectly"
# define ERR_PTHREAD	"Error pthread was created incorrectly"
# define ERR_INT		"Overflow for integer"
# define ERR_MTEX_LOCK	"Error mutex was lock incorrectly"
# define ERR_MTEX_ULOCK	"Error mutex was unlock incorrectly"
# define EAT_MSG		"%-16lld all the philosopher has \
eaten at least %d times each\n"

#endif