/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauvez <nfauvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 07:44:25 by nfauvez           #+#    #+#             */
/*   Updated: 2023/09/13 10:34:25 by nfauvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_can_eat(t_data *data, unsigned int i)
{	
	pthread_mutex_lock(&(data->philo[i].fork_m));
	data->philo[i].fork = data->philo[i].nb;
	pthread_mutex_unlock(&(data->philo[i].fork_m));
	pthread_mutex_lock(data->philo[i].fork1_m);
	*(data->philo[i].fork1) = data->philo[i].nb;
	pthread_mutex_unlock(data->philo[i].fork1_m);
}

void	check_fork(t_data *data, unsigned int i, unsigned int *ret)
{
	pthread_mutex_lock(&(data->philo[i].fork_m));
	*ret = data->philo[i].fork;
	pthread_mutex_unlock(&(data->philo[i].fork_m));
	if (*ret != 0)
		return ;
	pthread_mutex_lock(data->philo[i].fork1_m);
	*ret = *(data->philo[i].fork1);
	pthread_mutex_unlock(data->philo[i].fork1_m);
}

void	check_nte(t_data *data, unsigned int i, unsigned int *check_meal)
{
	unsigned int	temp;

	pthread_mutex_lock(&(data->philo[i].nb_eat_m));
	temp = data->philo[i].nb_eat;
	pthread_mutex_unlock(&(data->philo[i].nb_eat_m));
	if (temp >= data->n_t_e)
		*check_meal = *check_meal + 1;
	else
		*check_meal = 0;
}
