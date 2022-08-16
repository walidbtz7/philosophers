/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:00:13 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/14 21:07:09 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prosses(t_philo *philo)
{
	int	i;
	int	id;

	i = 0;
	philo->data->start = ft_time(0);
	while (i < philo->data->count)
	{
		id = fork();
		if (id != 0)
			philo[i].id = id;
		else
		{
			pthread_create(&philo->data->superviseur, NULL, \
			superviseur, &philo[i]);
			routine(&philo[i]);
			exit(1);
		}
		i++;
	}
}
