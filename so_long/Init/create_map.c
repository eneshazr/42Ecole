/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:12:54 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:12:54 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	ft_free(t_data *data)
{
	free(data->map.map);
	free(data->mlx);
	free(data->win);
	return ;
}

int	line_count(char *mappath)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(mappath, O_RDONLY);
	if (fd < 0)
		printf("\e[31mHATA: DOSYA ACILAMADI!\e[0m\n");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	put_input_in_map(int row, int column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
			return (ft_free(data));
		while (line[i] != '\0')
			data->map.map[row][column++] = line[i++];
		data->map.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
}

void	create_map(char *mappath, t_data *data)
{
	int	column;
	int	row;
	int	i;

	column = 0;
	row = 0;
	i = 0;
	data->map.line_count = line_count(mappath);
	data->map.path = mappath;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map))
		return ;
	data->map.fd = open(mappath, O_RDONLY);
	if (data->map.fd < 0)
		printf("\e[31mHATA: MAP DOSYASI ACILAMADI!e[0m\n");
	else
	{
		put_input_in_map(row, column, i, data);
		close(data->map.fd);
	}
}
