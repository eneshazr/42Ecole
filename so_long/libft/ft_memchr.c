/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:59 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/22 12:13:01 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Bir karakter dizisi içinde verilen karakteri bulduğu yerden
itibaren geri döndürür.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	int				k;

	str = (unsigned char *)s;
	i = 0;
	k = 0;
	if (n == i)
		return (NULL);
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		else
			k = 1;
		i++;
	}
	if (k == 1)
		return (0);
	else
		return (&str[i]);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    const char *str = "armut";

    printf("%s", ft_memchr(str, 'm', 3));
    printf("\n%s", memchr(str, 'm', 3));
}
*/
