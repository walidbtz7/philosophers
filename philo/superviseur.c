/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superviseur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:00:13 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/14 20:21:32 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_each_philosopher_must_eat(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->data->meal != -1)
	{
		pthread_mutex_lock(&(philo->data->mcheck));
		philo[i].data->check = 0;
		while (i < philo->data->count)
		{
			if (philo[i].meal >= philo[i].data->meal)
				philo[i].data->check++;
			i++;
		}
		pthread_mutex_unlock(&(philo->data->mcheck));
	}
}

void	died_of_hunger(t_philo	philo)
{
	if (ft_time(philo.data->start) - \
		philo.last_eat > philo.data->die)
	{
		display_die(&philo, ft_time(philo.data->start));
		philo.data->stop = 1;
		pthread_mutex_unlock(&(philo.data->finish));
	}
}

void	*superviseur(void *p)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)p;
	philo->data->stop = 0;
	while (i < philo->data->count && philo->data->stop == 0)
	{
		check_each_philosopher_must_eat(philo);
		pthread_mutex_lock(&(philo[i].data->last_meal));
		died_of_hunger(philo[i]);
		pthread_mutex_unlock(&(philo[i].data->last_meal));
		i++;
		if (philo->data->check == philo->data->count)
			pthread_mutex_unlock(&(philo->data->finish));
		else if (i == philo->data->count)
			i = 0;
	}
	return (0);
}
