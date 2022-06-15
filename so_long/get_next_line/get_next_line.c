/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:15:15 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:15:16 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/get_next_line.h"

char	*get_line(char *src, int fd)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	size = 1;
	while (!ft_strchr1(src, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		src = ft_strjoin1(src, buffer);
	}
	free(buffer);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line = get_line(next_line, fd);
	if (next_line == NULL)
		return (NULL);
	line = ft_read_line(next_line);
	next_line = ft_save(next_line);
	if (line[0] == '\0')
	{
		free(next_line);
		free(line);
		return (NULL);
	}
	return (line);
}
