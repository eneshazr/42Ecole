/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:17:19 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:17:20 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

void	init_map_bonus(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->d = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->map.count_f = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->steps_count = 0;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * IMG_SIZE;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}
