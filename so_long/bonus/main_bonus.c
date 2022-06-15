/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:17:31 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:17:32 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (name_check_bonus(argv[1]) == FAILURE)
			error_msg_bonus(ERRBER, &data);
		create_map_bonus(argv[1], &data);
		init_map_bonus(&data);
		check_map_bonus(&data);
		f_init_players_bonus(&data);
		init_window_bonus(&data);
		init_images_bonus(&data);
		loop_images_bonus(data);
		destroy_images_bonus(&data);
		ft_free_bonus(&data);
	}
	else
		error_msg2_bonus(ARGERR);
}
