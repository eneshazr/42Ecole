/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_foe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:16:11 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:16:12 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

void	foe_move(t_data *data, int i, int j)
{
	if (data->map.map[i][j + 1] == 'P')
	{
		ft_putstr_fd(RED"-GAME OVER-\n", 1);
		ft_free_bonus(data);
		exit(0);
	}
	if (data->map.map[i][j + 1] != '1')
	{
		data->map.map[i][j + 1] = 'F';
		data->map.map[i][j] = '0';
	}
}

void	foe_move2(t_data *data, int i, int j)
{
	while (data->map.map[i][j - 1] != '1')
	{
		if (data->map.map[i][j - 1] == 'E')
			break ;
		j--;
	}
	if (data->map.map[i][j] == 'P')
	{
		ft_putstr_fd(RED"-GAME OVER-\n", 1);
		ft_free_bonus(data);
		exit(0);
	}
	data->map.map[i][j] = 'F';
}

void	foe(t_data *data, int i, int j)
{
	data->d = 0;
	if (data->map.map[i][j + 1] != '1' &&
			data->map.map[i][j + 1] != 'C')
	{
		foe_move(data, i, j);
	}
	if (data->map.map[i][j + 1] == '1' ||
			data->map.map[i][j + 1] == 'C')
	{
		data->map.map[i][j] = '0';
		foe_move2(data, i, j);
	}
}
