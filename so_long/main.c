/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:08:22 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:08:22 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (name_check(argv[1]) == FAILURE)
			error_msg(ERRBER, &data);
		create_map(argv[1], &data);
		init_map(&data);
		check_map(&data);
		f_init_player(&data);
		init_window(&data);
		init_images(&data);
		loop_images(data);
		destroy_images(&data);
		ft_free(&data);
	}
	else
		error_msg2(ARGERR);
}
