/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:00:09 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/15 22:36:48 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(long start)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - start);
}

void	display(t_philo *philo, char *str, long time)
{
	pthread_mutex_lock(&(philo->data->display));
	printf("%ld Philosopher %d %s \n", time, philo->id, str);
	pthread_mutex_unlock(&(philo->data->display));
}

void	display_die(t_philo *philo, long time)
{
	pthread_mutex_lock(&(philo->data->display));
	printf("%ld Philosopher %d died \n", time, philo->id);
}

void	ft_usleep(long sleep)
{
	long	start;

	start = ft_time(0);
	while (ft_time(0) - start < sleep)
	{
		usleep(400);
	}
}
