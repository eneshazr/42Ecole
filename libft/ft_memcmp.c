/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:03:23 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/07 16:00:26 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/*
N kadar değerleri karşılaştır farkını al
*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "eglendiremediklerimizdenmisiniz";
    char str1[] = "aglendiremediklerinizdenim";

	printf("%d\n", ft_memcmp(str, str1, 1));
	printf("%d", memcmp(str, str1, 1));
}
*/
