/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:00:13 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/15 23:00:41 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->count)
	{
		kill(philo->id, SIGKILL);
		i++;
	}
}

void	free_all(t_philo *philo)
{
	free(philo->data);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	int		status;
	int		res;

	res = 0;
	status = 0;
	if ((argc == 5 || argc == 6) && checkarg(argv, argc) != 0 \
	&& ft_atoi(argv[1]) != 0)
	{
		data = (t_data *)malloc(sizeof(t_data));
		data_init(data, argc, argv);
		philo = (t_philo *)malloc(data->count * sizeof(t_philo));
		philo_init(philo, data);
		prosses(philo);
		while (res != -1 && status == 0)
		{
			res = waitpid(-1, &status, 0);
		}
		kill_process(philo);
		free_all(philo);
	}
	else
		write(2, "Error!\n", 8);
	return (0);
}
