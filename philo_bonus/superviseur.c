/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superviseur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:00:13 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/14 21:01:09 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	died_of_hunger(t_philo	*philo, int die)
{
	if (ft_time(philo->data->start) - \
		philo->last_eat > philo->data->die)
	{
		print_die(philo, ft_time(philo->data->start));
		die = 1;
		exit(1);
	}
}

void	*superviseur(void *p)
{
	t_philo	*philo;
	int		i;
	int		die;

	die = 0;
	i = 0;
	philo = (t_philo *)p;
	while (1)
	{
		died_of_hunger(philo, die);
		if (philo->data->meal != -1)
		{
			if (philo->meal == philo->data->meal)
				exit(0);
		}
	}
	return (0);
}
