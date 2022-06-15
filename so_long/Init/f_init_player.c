/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:13:04 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:13:04 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	f_init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->p_i = i;
				data->p_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
