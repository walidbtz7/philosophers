/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:00:13 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/15 22:37:21 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->fork[philo->left]));
	display(philo, "has taken a fork", ft_time(philo->data->start));
	pthread_mutex_lock(&(philo->data->fork[philo->right]));
	display(philo, "has taken a fork", ft_time(philo->data->start));
	display(philo, "is eating", ft_time(philo->data->start));
	ft_usleep(philo->data->eat);
	pthread_mutex_unlock(&(philo->data->fork[philo->left]));
	pthread_mutex_unlock(&(philo->data->fork[philo->right]));
	pthread_mutex_lock(&(philo->data->last_meal));
	philo->last_eat = ft_time(philo->data->start);
	philo->meal++;
	pthread_mutex_unlock(&(philo->data->last_meal));
}

void	sleeping(t_philo *philo)
{
	display(philo, "is sleeping", ft_time(philo->data->start));
	ft_usleep(philo->data->sleep);
}

void	thinking(t_philo *philo)
{
	display(philo, "is thinking", ft_time(philo->data->start));
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}
