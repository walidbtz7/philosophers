/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:00:13 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/15 22:38:19 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print(philo, "has taken a fork", ft_time(philo->data->start));
	sem_wait(philo->data->forks);
	print(philo, "has taken a fork", ft_time(philo->data->start));
	print(philo, "is eating", ft_time(philo->data->start));
	usleep(philo->data->eat * 1000);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	philo->last_eat = ft_time(philo->data->start);
	philo->meal++;
}

void	sleeping(t_philo *philo)
{
	print(philo, "is sleeping", ft_time(philo->data->start));
	usleep(philo->data->sleep * 1000);
}

void	thinking(t_philo *philo)
{
	print(philo, "is thinking", ft_time(philo->data->start));
}

void	*routine(t_philo *philo)
{
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}
