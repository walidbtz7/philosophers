/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:00:09 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/16 21:00:49 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(long start)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - start);
}

void	print(t_philo *philo, char *str, long time)
{
	sem_wait(philo->data->display);
	printf("%ld Philosopher %d %s \n", time, philo->id, str);
	sem_post(philo->data->display);
}

void	print_die(t_philo *philo, long time)
{
	sem_wait(philo->data->display);
	printf("%ld Philosopher %d died \n", time, philo->id);
}

void	ft_usleep(long sleep)
{
	long	start;

	start = ft_time(0);
	usleep(sleep * 900);
	while (ft_time(start) < sleep)
		usleep(400);
}
