/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:25:23 by ehazir            #+#    #+#             */
/*   Updated: 2022/03/05 15:25:23 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_system(unsigned int n, char c)
{
	int				i;
	int				len;
	char			*a;
	unsigned int	j;

	if (c == 'x')
		a = ft_strdup("0123456789abcdef");
	else
		a = ft_strdup("0123456789ABCDEF");
	j = n;
	i = 1;
	while (j >= 16 && i++)
		j = j / 16;
	len = i;
	if (n >= 16)
	{
		hex_system(n / 16, c);
		hex_system(n % 16, c);
	}
	else
		ekranayaz(a[n]);
	free(a);
	return (len);
}

int	ptr_(unsigned long n)
{
	int	i;

	i = 1;
	ekranayaz('0');
	ekranayaz('x');
	ptryaz(n);
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 2);
}

int	ptryaz(unsigned long n)
{
	char	*a;

	a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ptryaz(n / 16);
		ptryaz(n % 16);
	}
	else
		ekranayaz(a[n]);
	free(a);
	return (0);
}
