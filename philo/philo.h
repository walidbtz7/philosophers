/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:05:52 by wboutzou          #+#    #+#             */
/*   Updated: 2022/08/14 21:33:24 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

struct s_data
{
	int				count;
	int				meal;
	int				eat;
	int				die;
	int				check;
	int				sleep;
	int				stop;
	long			start;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	finish;
	pthread_mutex_t	display;
	pthread_t		superviseur;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mcheck;
};
typedef struct s_data	t_data;

struct s_philo
{
	int			id;
	int			left;
	int			right;
	long		last_eat;
	int			meal;
	pthread_t	philo;
	t_data		*data;
};
typedef struct s_philo	t_philo;

int		checkarg(char **argv, int argc);
int		ft_atoi(char *str);
void	data_init(t_data *data, int argc, char **argv);
void	philo_init(t_philo *philo, t_data *data);
void	thead_create(t_philo *philo);
long	ft_time(long start);
void	ft_usleep(long sleep);
void	display(t_philo *philo, char *str, long time);
void	display_die(t_philo *philo, long time);
void	*routine(void *p);
void	*superviseur(void *p);
#endif