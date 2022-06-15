/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:15:10 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:15:11 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/get_next_line.h"

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen1(s1) + ft_strlen1(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen1(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr1(char *src, int c)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (c == '\0')
		return ((char *)&src[ft_strlen1(src)]);
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}

char	*ft_read_line(char *src)
{
	size_t	i;
	char	*str;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0' && src[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_save(char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (src[i] != '\0' && src[i] != '\n')
		i++;
	if (src[i] == '\0')
	{
		free(src);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen1(src) - i + 1));
	if (str == NULL)
		return (NULL);
	i = i + 1;
	j = 0;
	while (src[i] != '\0')
		str[j++] = src[i++];
	str[j] = '\0';
	free(src);
	return (str);
}
