/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauvez <nfauvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 07:46:17 by nfauvez           #+#    #+#             */
/*   Updated: 2023/09/13 11:42:42 by nfauvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Allows to have real time

void	get_time(unsigned int *time, unsigned int *b_time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return ;
	if (b_time == NULL)
		*time = tv.tv_sec * 1000000 + tv.tv_usec;
	else
		*time = (tv.tv_sec * 1000000 + tv.tv_usec) - *b_time;
}

// If there is only one philo

int	philoloner(t_data *data)
{
	unsigned int	time;

	get_time(&time, &(data->b_time));
	printf("%u 1 is thinking\n", time / 1000);
	pthread_mutex_lock(data->printf);
	printf("%u 1 has taken a fork\n", time / 1000);
	pthread_mutex_unlock(data->printf);
	while (time < data->t_t_d)
	{
		usleep(500);
		get_time(&time, &(data->b_time));
	}
	printf("%u 1 died\n", time / 1000);
	return (0);
}

// Creation and routine function of philos.
// If the philos are correctly created, start their routine.

int	philosophers(t_data *data)
{
	unsigned int	i;

	get_time(&(data->b_time), NULL);
	if (data->nb_p == 1)
		return (philoloner(data));
	if (ft_init(data))
		return (-1);
	i = 0;
	check_alive(data, i);
	{
		while (i < data->nb_p)
		{
			if (pthread_join(data->philo[i].thread, NULL))
				return (-1);
			i++;
		}
	}
	return (0);
}
