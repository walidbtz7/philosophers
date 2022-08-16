/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:00:13 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/16 00:31:39 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_detach(t_philo *philo, int i)
{
	if (pthread_create(&philo[i].philo, NULL, routine, &philo[i]) != 0)
	{
		write(2, "\nThread creation error\n", 24);
		pthread_mutex_unlock(&(philo[i].data->finish));
	}
	pthread_detach(philo[i].philo);
}

void	thead_create(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->count)
	{
		create_detach(philo, i);
		i += 2;
	}
	usleep(250);
	i = 1;
	while (i < philo->data->count)
	{
		create_detach(philo, i);
		i += 2;
	}
}
