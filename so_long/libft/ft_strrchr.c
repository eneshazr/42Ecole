/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:01:14 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/22 13:13:23 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Stringe tersten bakar, gönderdiğimiz karakterden sonrasını yazar.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
    const char str[] = "eglendiremediklerimizdenmisiniz";
    char *s;
    
    s = ft_strrchr(str, 'i');
    printf("%s", s);
}
*/