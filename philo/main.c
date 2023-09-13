/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauvez <nfauvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:56:47 by nfauvez           #+#    #+#             */
/*   Updated: 2023/09/13 10:36:48 by nfauvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_arg(t_data *data, char **av, int ac)
{
	data->nb_p = ft_atoi(av[1]);
	if (data->nb_p == 0)
		return (3);
	data->t_t_d = ft_atoi(av[2]) * 1000;
	data->t_t_e = ft_atoi(av[3]) * 1000;
	data->t_t_s = ft_atoi(av[4]) * 1000;
	if (ac == 6)
	{
		data->n_t_e = ft_atoi(av[5]);
		if (data->n_t_e == 0)
			return (4);
	}
	if (ac == 5)
		data->n_t_e = 0;
	if (data->t_t_d >= 429496000 || data->t_t_e == 429496000
		|| data->n_t_e == 429496 || data->t_t_s == 429496000
		|| data->nb_p == 429496)
		return (5);
	return (set_calloc(data));
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_digit(av[i]))
			return (2);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		ret;
	t_data	data;

	ret = check_args(av);
	if ((ac != 5 && ac != 6) || ret != 1)
		return (ft_return(ret, &data));
	ret = set_arg(&data, av, ac);
	if (ret)
		return (ft_return(ret, &data));
	ret = philosophers(&data);
	return (ft_return(ret, &data));
}
