/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:16:19 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:16:19 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

int	check_next_tile_bonus(t_data *data, char direction, char tile)
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

void	move_bonus(char direction, t_data *data)
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

void	collect_coins_bonus(t_data *data, char direction)
{
	if ((direction == D && data->map.map[data->p_i][data->p_j + 1] == 'C')
		|| (direction == A && data->map.map[data->p_i][data->p_j - 1] == 'C')
		|| (direction == S && data->map.map[data->p_i + 1][data->p_j] == 'C')
		|| (direction == W && data->map.map[data->p_i - 1][data->p_j] == 'C'))
		data->map.collected++;
}

int	win_game_bonus(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		ft_putstr_fd(GREEN"-TEBRIKLER-\n", 1);
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

void	move_player_bonus(t_data *data, char direction)
{
	if (check_next_tile_bonus(data, direction, '1') == SUCCESS
		|| (data->map.can_exit == 0
			&& check_next_tile_bonus(data, direction, 'E') == SUCCESS))
		return ;
	collect_coins_bonus(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_i][data->p_j] = '0';
	move_bonus(direction, data);
	move_msg_bonus(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_i][data->p_j] == 'E')
	{
		win_game_bonus(data);
		ft_free_bonus(data);
		exit(0);
	}
	if (data->map.map[data->p_i][data->p_j] == 'F')
	{
		ft_putstr_fd(RED"-GAME OVER-\n", 1);
		ft_free_bonus(data);
		exit(0);
	}
	data->map.map[data->p_i][data->p_j] = 'P';
}
