/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:54:00 by ehazir            #+#    #+#             */
/*   Updated: 2022/10/24 16:11:30 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 5 || ac == 6)
	{
		if (!args_check(ac, av))
		{
			write(2, "Error! Invalid Arg\n", 18);
			return (0);
		}
		data = malloc(sizeof(t_data));
		assigment(ac, av, data);
		s_fork(data);
	}
	else
		write(2, "Arg Error!\n", 11);
	return (0);
}
