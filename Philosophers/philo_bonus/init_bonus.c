/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:54:06 by ehazir            #+#    #+#             */
/*   Updated: 2022/10/24 16:27:45 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all(t_data *data)
{
	int	i;
	int	pid_value;

	waitpid(-1, &pid_value, 0);
	if (pid_value != 0)
	{
		i = 0;
		while (i < data->philo)
		{
			kill(data->philos[i].pid, 15);
			i++;
		}
		sem_close(data->sem_forks);
		sem_close(data->sem_msg);
		sem_close(data->sem_eat);
		sem_close(data->sem_death);
		sem_unlink("/Forks");
		sem_unlink("/Message");
		sem_unlink("/Eat");
		sem_unlink("/Death");
	}
}

int	s_fork(t_data *data)
{
	int			i;
	t_philos	*philos;

	philos = data->philos;
	i = 0;
	while (i < data->philo)
	{
		philos[i].pid = fork();
		if (philos[i].pid < 0)
			return (0);
		if (philos[i].pid == 0)
			worker(&(philos[i]));
		i++;
	}
	pthread_join(philos->dead_check, NULL);
	kill_all(data);
	return (1);
}

void	sem(t_data *data)
{
	sem_unlink("/Forks");
	sem_unlink("/Message");
	sem_unlink("/Eat");
	sem_unlink("/Death");
	data->sem_forks = sem_open("/Forks", O_CREAT, S_IRWXU, data->philo);
	data->sem_msg = sem_open("/Message", O_CREAT, S_IRWXU, 1);
	data->sem_eat = sem_open("/Eat", O_CREAT, S_IRWXU, 1);
	data->sem_death = sem_open("/Death", O_CREAT, S_IRWXU, 1);
}

void	assigment(int ac, char **av, t_data *data)
{
	int	i;

	data->philo = ft_atoi(av[1]);
	data->philos = malloc(sizeof(t_philos) * data->philo);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->one_philo_eat = ft_atoi(av[5]);
	else
		data->one_philo_eat = 0;
	data->died = 0;
	data->all_eat = 0;
	data->all_eaters = 0;
	sem(data);
	i = 0;
	while (i < data->philo && data->philo > 0)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].total_eating = 0;
		data->philos[i].last_eat = 0;
		i++;
	}
}
