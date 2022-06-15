/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:15:58 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:15:59 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

int	check_chars_bonus(t_data *data)
{
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == 'P')
				data->map.count_p++;
			else if (data->map.map[data->i][data->j] == 'F')
				data->map.count_f++;
			else if (data->map.map[data->i][data->j] == 'E')
				data->map.count_e++;
			else if (data->map.map[data->i][data->j] == 'C')
				data->map.count_c++;
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	if (!data->map.count_c || !data->map.count_e || !data->map.count_p)
		return (FAILURE);
	else
		return (SUCCESS);
}

int	check_top_bot_bonus(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_edges_bonus(int line_count, char **map)
{
	int	i;

	i = 1;
	if (check_top_bot_bonus(0, map) == FAILURE
		|| check_top_bot_bonus(line_count, map) == FAILURE)
		return (FAILURE);
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_rectangle_bonus(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	data->map.line_len = ft_strlen(data->map.map[i]) - 1;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
			j++;
		if (j != data->map.line_len)
			return (FAILURE);
		j = 0;
		i++;
	}
	return (SUCCESS);
}

int	check_map_bonus(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{	
		while (j < ft_strlen(data->map.map[i]) - 1)
		{
			if (ft_strchr("01CEPF", data->map.map[i][j]) == NULL)
				error_msg_bonus(ERROTHER, data);
			j++;
		}
		j = 0;
		i++;
	}
	if (check_chars_bonus(data) == FAILURE)
		error_msg_bonus(ERRCHARS, data);
	if (data->map.count_p > 1)
		error_msg_bonus(ERRPLAYER, data);
	if (check_rectangle_bonus(data) == FAILURE)
		error_msg_bonus(ERRREC, data);
	if (check_edges_bonus(data->map.line_count - 1, data->map.map) == FAILURE)
		error_msg_bonus(ERREDGES, data);
	return (SUCCESS);
}
