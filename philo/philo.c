/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:00:13 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/16 00:32:55 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo)
{
	free(philo->data);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if ((argc == 5 || argc == 6) && checkarg(argv, argc) != 0 \
	&& ft_atoi(argv[1]) != 0)
	{
		data = (t_data *)malloc(sizeof(t_data));
		data_init(data, argc, argv);
		philo = (t_philo *)malloc(data->count * sizeof(t_philo));
		philo_init(philo, data);
		philo->data->start = ft_time(0);
		pthread_create(&data->superviseur, NULL, superviseur, philo);
		thead_create(philo);
		pthread_detach(data->superviseur);
		pthread_mutex_lock(&(philo->data->finish));
		pthread_mutex_lock(&(philo->data->finish));
		free_all(philo);
	}
	else
		write(2, "Error!\n", 8);
	return (0);
}
