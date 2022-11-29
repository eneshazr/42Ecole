/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:05:38 by ehazir            #+#    #+#             */
/*   Updated: 2022/10/24 14:29:11 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo)
	{
		pthread_detach(data->threads[i]);
		i++;
	}
	return (1);
}

int	death_lock(t_philo *p)
{
	pthread_mutex_lock(&p->data->death);
	if ((p->data->one_died != 0) || \
		p->data->all_eat == p->data->philo)
	{
		pthread_mutex_unlock(&p->data->death);
		return (0);
	}
	pthread_mutex_unlock(&p->data->death);
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	unsigned int	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * n);
}

int	init_args_check(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}
