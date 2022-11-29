/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:05:12 by ehazir            #+#    #+#             */
/*   Updated: 2022/10/24 16:53:42 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (!init_args_check(ac, av))
		{
			write(2, "Error!\nArgumanlar hatali!\n", 26);
			return (0);
		}
		init_args(ac, av, &data);
		creat_threads(&data);
		ft_free(&data);
	}
	else
		write(2, "Error!\nArgumanlar hatali!\n", 26);
	return (0);
}
