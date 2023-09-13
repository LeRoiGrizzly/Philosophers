/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauvez <nfauvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 07:50:11 by nfauvez           #+#    #+#             */
/*   Updated: 2023/09/13 11:35:37 by nfauvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Allows to take a fork

void	take_fork_1(t_philo *philo, char v)
{
	if (v == 1)
		ft_print(philo, "has taken a fork");
	if (v == 0)
	{
		pthread_mutex_lock(philo->fork1_m);
		*(philo->fork1) = 0;
		pthread_mutex_unlock(philo->fork1_m);
	}
}

void	take_fork(t_philo *philo, char v)
{
	if (v == 1)
		ft_print(philo, "has taken a fork");
	if (v == 0)
	{
		pthread_mutex_lock(&(philo->fork_m));
		philo->fork = 0;
		pthread_mutex_unlock(&(philo->fork_m));
	}
}

void	f_eat(t_philo *philo, char *life)
{
	unsigned int	sleep;
	unsigned int	time;

	get_time(&time, &philo->b_time);
	sleep = philo->t_t_e + time;
	still_breathing(philo, life);
	while (*life && time < sleep)
	{
		usleep(750);
		get_time(&time, &philo->b_time);
		still_breathing(philo, life);
	}
}

void	eat_last(t_philo *philo, char *life)
{
	take_fork_1(philo, 1);
	take_fork(philo, 1);
	ft_print(philo, "is eating");
	pthread_mutex_lock(&(philo->time_m));
	get_time(&(philo->p_time), &(philo->b_time));
	pthread_mutex_unlock(&(philo->time_m));
	f_eat(philo, life);
	take_fork_1(philo, 0);
	take_fork(philo, 0);
	pthread_mutex_lock(&(philo->nb_eat_m));
	philo->nb_eat++;
	pthread_mutex_unlock(&(philo->nb_eat_m));
}

// Launch the "eating" action and print the message

void	eat(t_philo *philo, char *life)
{
	take_fork(philo, 1);
	take_fork_1(philo, 1);
	ft_print(philo, "is eating");
	pthread_mutex_lock(&(philo->time_m));
	get_time(&(philo->p_time), &(philo->b_time));
	pthread_mutex_unlock(&(philo->time_m));
	f_eat(philo, life);
	take_fork(philo, 0);
	take_fork_1(philo, 0);
	pthread_mutex_lock(&(philo->nb_eat_m));
	philo->nb_eat++;
	pthread_mutex_unlock(&(philo->nb_eat_m));
}
