/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   func_3.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ehazir <eneshazrr@gmail.com>			   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/05 16:01:39 by ehazir			#+#	#+#			 */
/*   Updated: 2022/03/05 16:01:39 by ehazir		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	basamaksay(unsigned int c)
{
	int	i;

	i = 0;
	while (c >= 10)
	{
		c = c / 10;
		i++;
	}
	return (i + 1);
}

int	unsigneditooo(unsigned int a)
{
	int		len;
	char	*str;

	len = basamaksay(a);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = a % 10 + '0';
		a = a / 10;
		len--;
	}
	len = stringyaz(str);
	free(str);
	return (len);
}

int	get_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;

	digit = get_len(n);
	str = (char *)calloc(sizeof(char), digit + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(str, "-2147483648\0", digit + 1);
			return (str);
		}
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		*(str + --digit) = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
