/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:15:33 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:15:34 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	check_next_tile(t_data *data, char direction, char tile)
{
	if ((direction == D && data->map.map[data->p_i][data->p_j + 1] == tile)
		|| (direction == A && data->map.map[data->p_i][data->p_j - 1] == tile)
		|| (direction == S && data->map.map[data->p_i + 1][data->p_j] == tile)
		|| (direction == W && data->map.map[data->p_i - 1][data->p_j] == tile)
		)
		return (SUCCESS);
	else
		return (FAILURE);
}

void	move(char direction, t_data *data)
{
	if (direction == D)
	{
		data->p_j++;
		data->steps_count++;
	}
	else if (direction == A)
	{
		data->p_j--;
		data->steps_count++;
	}
	else if (direction == S)
	{
		data->p_i++;
		data->steps_count++;
	}
	else if (direction == W)
	{
		data->p_i--;
		data->steps_count++;
	}
}

void	win_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	ft_putstr_fd(GREEN"-TEBRIKLER-\n", 1);
}

void	collect_coins(t_data *data, char direction)
{
	if ((direction == D && data->map.map[data->p_i][data->p_j + 1] == 'C')
		|| (direction == A && data->map.map[data->p_i][data->p_j - 1] == 'C')
		|| (direction == S && data->map.map[data->p_i + 1][data->p_j] == 'C')
		|| (direction == W && data->map.map[data->p_i - 1][data->p_j] == 'C'))
		data->map.collected++;
}

void	move_player(t_data *data, char direction)
{
	if (check_next_tile(data, direction, '1') == SUCCESS
		|| (data->map.can_exit == 0
			&& check_next_tile(data, direction, 'E') == SUCCESS))
		return ;
	collect_coins(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_i][data->p_j] = '0';
	move(direction, data);
	move_msg(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_i][data->p_j] == 'E')
	{
		win_game(data);
		exit(0);
	}
	data->map.map[data->p_i][data->p_j] = 'P';
}
