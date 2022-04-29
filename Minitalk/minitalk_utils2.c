/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:29:43 by ehazir            #+#    #+#             */
/*   Updated: 2022/04/28 12:29:45 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				j;
	unsigned int	res;

	i = 0;
	j = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -j;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * j);
}

static char	*set_str(int n, int *bas)
{
	char	*str;

	*bas = 1;
	if (n < 0)
	{
		n *= -1;
		(*bas)++;
	}
	while (n >= 10)
	{
		n /= 10;
		(*bas)++;
	}
	str = (char *)malloc(sizeof(char) * (*bas + 1));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[(*bas)] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		bas;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = set_str(n, &bas);
	if (n < 0)
		n *= -1;
	if (!str)
		return (NULL);
	while (n >= 10)
	{
		str[--bas] = n % 10 + '0';
		n = n / 10;
	}
	str[--bas] = n % 10 + '0';
	return (str);
}

char	*ft_strjoin(char *s1, char const s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 2));
	if (!s3)
		return (NULL);
	while (s1[i] != 0)
	{
		s3[j++] = s1[i];
		i++;
	}
	s3[j++] = s2;
	s3[j] = 0;
	return (s3);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
