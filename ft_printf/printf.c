/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:46:53 by ehazir            #+#    #+#             */
/*   Updated: 2022/03/05 14:46:53 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ekranayaz(char c)
{
	write(1, &c, 1);
	return (1);
}

int	stringyaz(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (stringyaz("(null)"));
	while (str[i])
		i += ekranayaz(str[i]);
	return (i);
}

int	kontrol(va_list arg, char c)
{
	char	*a;
	int		len;

	len = 0;
	if (c == 'c')
		len += ekranayaz(va_arg(arg, int));
	else if (c == 's')
		len += stringyaz(va_arg(arg, char *));
	else if (c == 'p')
		len += ptr_(va_arg(arg, unsigned long));
	else if (c == 'u')
		len += unsigneditooo(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		len += hex_system(va_arg(arg, unsigned int), c);
	else if (c == '%')
		len += ekranayaz('%');
	else if (c == 'd' || c == 'i')
	{
		a = ft_itoa(va_arg(arg, int));
		len += stringyaz(a);
		free(a);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += kontrol(arg, str[i]);
		}
		else
			len += ekranayaz(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

/*
int main()
{
	int i;
	char giris;
	char *s = "Ferdi TAYFUR";
	int d = 53;
	unsigned int u = 2071;
	int x = 15;
	int X = 123;
	char c = 'a';

	ft_printf("%c\n%s\n%d\n%x\n%X\n%p\n%%\n%u", c, NULL, d, x, X, d,-123);

	// giris += ft_printf("%s", s);
	// giris += ft_printf("\n%d", d);
	// giris += ft_printf("\n%x", x);
	// giris += ft_printf("\n%X", X);
	// // giris = ft_printf("\n%p", 32);
	// // printf("\n%d", giris);
	// giris += ft_printf("\n%u", u);
	// giris += ft_printf("\n%%");
	// printf("\nuzunluk: %d", giris);
}
*/