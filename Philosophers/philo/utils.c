/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:05:44 by ehazir            #+#    #+#             */
/*   Updated: 2022/10/24 16:47:22 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	messages(int time, char *msg, t_philo *p)
{	
	pthread_mutex_lock(&p->data->msg);
	time = get_time() - p->start_time;
	printf("%d %d %s\n", time, p->id, msg);
	pthread_mutex_unlock(&p->data->msg);
}

int	death(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->death);
	while (i < data->philo)
	{
		eat_count(data, i);
		if (data->philos[i].ph_eat_time != 0 && data->die_time \
			< (get_time() - data->philos[i].ph_eat_time))
		{
			if (data->philos->dead == 0)
			{
				messages(get_time(), "died", &data->philos[0]);
				data->philos->dead = 1;
				data->one_died = 1;
			}
			pthread_mutex_unlock(&data->death);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&data->death);
	return (0);
}

void	philo_think(t_philo *p)
{
	if (!death_lock(p))
		return ;
	messages(get_time(), "is thinking", p);
}

void	philo_sleep(t_philo *p)
{
	if (!death_lock(p))
		return ;
	messages(get_time(), "is sleeping", p);
	go_sleep(p->data->sleep_time);
}

void	philo_eat(t_philo *p)
{
	if (!death_lock(p))
		return ;
	pthread_mutex_lock(&p->data->forks[p->l_fork]);
	pthread_mutex_lock(&p->data->forks[p->r_fork]);
	if (!death_lock(p))
		return ;
	messages(get_time(), "has taken a fork", p);
	messages(get_time(), "has taken a fork", p);
	pthread_mutex_lock(&p->data->death);
	p->eat_count++;
	p->ph_eat_time = get_time();
	pthread_mutex_unlock(&p->data->death);
	if (!death_lock(p))
		return ;
	messages(get_time(), "is eating", p);
	go_sleep(p->data->eat_time);
	pthread_mutex_unlock(&p->data->forks[p->l_fork]);
	pthread_mutex_unlock(&p->data->forks[p->r_fork]);
	return ;
}
