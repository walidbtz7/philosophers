/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:08:29 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/16 00:34:28 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) == -1)
			write(2, "\nMutex initialization failed\n", 30);
		i++;
	}
	if (pthread_mutex_init(&data->display, NULL) == -1)
		write(2, "\nMutex initialization failed\n", 30);
	if (pthread_mutex_init(&data->last_meal, NULL) == -1)
		write(2, "\nMutex initialization failed\n", 30);
	if (pthread_mutex_init(&data->finish, NULL) == -1)
		write(2, "\nMutex initialization failed\n", 30);
	if (pthread_mutex_init(&data->mcheck, NULL) == -1)
		write(2, "\nMutex initialization failed\n", 30);
}

void	data_init(t_data *data, int argc, char **argv)
{
	data->count = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meal = ft_atoi(argv[5]);
	else
		data->meal = -1;
	data->check = 0;
	data->fork = (pthread_mutex_t *) \
	malloc(data->count * sizeof(pthread_mutex_t));
	mutex_init(data);
}

void	philo_init(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		philo[i].id = i + 1;
		philo[i].left = i;
		philo[i].right = i + 1;
		if (philo[i].right == data->count)
			philo[i].right = 0;
		philo[i].last_eat = 0;
		philo[i].meal = 0;
		philo[i].data = data;
		i++;
	}
}
