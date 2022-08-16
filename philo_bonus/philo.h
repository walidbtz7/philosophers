/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:05:52 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/14 21:35:23 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

struct s_data
{
	sem_t			*forks;
	sem_t			*display;
	sem_t			*finish;
	int				count;
	int				meal;
	int				eat;
	int				die;
	int				check;
	int				sleep;
	pthread_t		superviseur;
	pthread_mutex_t	out;
	long			start;
};
typedef struct s_data	t_data;

struct s_philo
{
	int			id;
	long		last_eat;
	int			meal;
	t_data		*data;
};
typedef struct s_philo	t_philo;

int		checkarg(char **argv, int argc);
int		ft_atoi(char *str);
void	data_init(t_data *data, int argc, char **argv);
void	philo_init(t_philo *philo, t_data *data);
void	thead_create(t_philo *philo);
long	ft_time(long start);
void	print(t_philo *philo, char *str, long time);
void	print_die(t_philo *philo, long time);
void	*routine(t_philo *philo);
void	*superviseur(void *p);
void	ft_usleep(long sleep);
void	prosses(t_philo *philo);
#endif