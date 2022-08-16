/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:08:29 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/15 23:01:47 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	sem_unlink("forks");
	sem_unlink("display");
	sem_unlink("finish");
	data->forks = sem_open("forks", O_CREAT, 0664, data->count);
	data->display = sem_open("display", O_CREAT, 0664, 1);
	data->finish = sem_open("display", O_CREAT, 0664, 1);
	if (pthread_mutex_init(&data->out, NULL) == -1)
		write(2, "\nMutex initialization failed\n", 30);
}

void	philo_init(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		philo[i].id = i + 1;
		philo[i].last_eat = 0;
		philo[i].meal = 0;
		philo[i].data = data;
		i++;
	}
}
