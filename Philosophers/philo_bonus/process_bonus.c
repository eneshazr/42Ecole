/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:53:56 by ehazir            #+#    #+#             */
/*   Updated: 2022/10/24 16:57:09 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thinking(t_philos *philo)
{
	messages(get_time(), "thinking", philo);
}

void	sleeping(t_philos *philo)
{
	messages(get_time(), "sleeping", philo);
	my_sleep(philo->data->sleep_time);
}

void	eating(t_philos *philo)
{
	sem_wait(philo->data->sem_forks);
	messages(get_time(), "has taken a fork", philo);
	sem_wait(philo->data->sem_forks);
	messages(get_time(), "has taken a fork", philo);
	messages(get_time(), "eating", philo);
	sem_wait(philo->data->sem_eat);
	philo->last_eat = get_time();
	philo->total_eating++;
	sem_post(philo->data->sem_eat);
	my_sleep(philo->data->eat_time);
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
}

void	one_philo(t_philos *philo)
{
	sem_wait(philo->data->sem_forks);
	messages(get_time(), "has taken a fork", philo);
	my_sleep(philo->data->die_time);
	messages(get_time(), "died", philo);
	exit(1);
}

void	worker(void *pth)
{
	t_philos	*process;

	process = (t_philos *)pth;
	process->data->start_time = get_time();
	if (process->data->philo == 1)
		one_philo(process);
	pthread_create(&(process->dead_check), NULL, &dead_check, process);
	if (process->id % 2 == 0)
		my_sleep(process->data->eat_time);
	while (process->data->philo > 1)
	{
		if (lock_check(process) != 1)
			break ;
		eating(process);
		if (lock_check(process) != 1)
			break ;
		sleeping(process);
		if (lock_check(process) != 1)
			break ;
		thinking(process);
	}
	exit(0);
}
