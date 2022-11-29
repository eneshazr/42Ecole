/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:54:12 by ehazir            #+#    #+#             */
/*   Updated: 2022/10/24 16:49:45 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	total_eating(t_data *data, t_philos *philo)
{
	sem_wait(philo->data->sem_eat);
	if (philo->total_eating == data->one_philo_eat && data->one_philo_eat > 0)
	{
		data->all_eat++;
		if (data->all_eat == data->philo)
		{
			philo->data->all_eaters = 1;
			sem_post(philo->data->sem_eat);
			return (1);
		}
		sem_post(philo->data->sem_eat);
		return (0);
	}
	sem_post(philo->data->sem_eat);
	return (0);
}

void	my_sleep(long long time)
{
	long long	now;

	now = get_time();
	while (get_time() - now < time)
		usleep(60);
}

void	messages(long long time, char *str, t_philos *philo)
{
	sem_wait(philo->data->sem_msg);
	if (philo->data->died == 0)
		printf("%lld %d %s\n", \
				time - philo->data->start_time, philo->id, str);
	sem_post(philo->data->sem_msg);
}

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}
