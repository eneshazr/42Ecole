/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:05:03 by ehazir            #+#    #+#             */
/*   Updated: 2022/10/24 14:06:38 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_count(t_data *data, int i)
{
	if (data->philos[i].eat_count == data->ph_m_eat)
	{
		data->philos[i].eat_count = 0;
		data->all_eat++;
	}
}

int	philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->philo);
	if (!data->philos)
	{
		write(2, "Error!\nFailed to allocate memory for philosophers\n", 50);
		return (0);
	}
	while (++i < data->philo)
	{
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].dead = 0;
		data->philos[i].l_fork = i + 1;
		data->philos[i].r_fork = i;
	}
	data->philos[i].eat_count = 0;
	data->philos[i].data = data;
	data->philos[i].id = i + 1;
	data->philos[i].dead = 0;
	data->philos[i].l_fork = 0;
	data->philos[i].r_fork = i;
	return (1);
}

int	forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo);
	if (!data->forks)
	{
		write(2, "Error!\nFailed to allocate memory for forks\n", 43);
		return (0);
	}
	while (i < data->philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			write(2, "Error!\nFork problem\n", 18);
			return (0);
		}
		i++;
	}
	return (1);
}

void	init_args(int ac, char **av, t_data *data)
{
	data->philo = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->ph_m_eat = ft_atoi(av[5]);
	else
		data->ph_m_eat = -1;
	data->all_eat = 0;
	data->one_died = 0;
	pthread_mutex_init(&data->msg, NULL);
	pthread_mutex_init(&data->death, NULL);
	forks(data);
	philos(data);
}
