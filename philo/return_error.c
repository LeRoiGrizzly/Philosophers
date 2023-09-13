/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauvez <nfauvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 07:50:39 by nfauvez           #+#    #+#             */
/*   Updated: 2023/09/13 11:36:54 by nfauvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_all(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (data->nb_p != 1 && i < data->nb_p)
	{
		if (pthread_mutex_destroy(&(data->philo[i].fork_m)))
			return (-1);
		if (pthread_mutex_destroy(&(data->philo[i].is_alive_m)))
			return (-1);
		if (pthread_mutex_destroy(&(data->philo[i].time_m)))
			return (-1);
		if (pthread_mutex_destroy(&(data->philo[i].nb_eat_m)))
			return (-1);
		i++;
	}
	if (pthread_mutex_destroy(data->printf))
		return (-1);
	if (pthread_mutex_destroy(data->l_data))
		return (-1);
	free(data->printf);
	free(data->l_data);
	free(data->philo);
	return (0);
}

// Display errors message

int	ft_return(int mark, t_data *data)
{
	if (mark == 0 || mark == -1)
	{
		if (mark == -1)
			write(1, "An error has occured.\n", 22);
		if (free_all(data))
			return (-1);
	}
	if (mark == 1)
	{
		printf("Arg requireds : [number_of_philosophers] ");
		printf("[time_to_die] [time_to_eat] [time_to_sleep] ");
		printf("(opt.)[number_of_time_each_philosopher_must_eat]\n");
	}
	if (mark == 2)
		printf("Please use digits only.\n");
	if (mark == 3)
		printf("You throw a big party, but no one was invited.\n");
	if (mark == 4)
		printf("You throw a fancy diner, but nobody was hungry.\n");
	if (mark == 5)
		printf("The place is crowded! Please use 429496 as max value\n");
	return (0);
}
