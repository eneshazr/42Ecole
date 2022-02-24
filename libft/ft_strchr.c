/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:38:14 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/24 13:00:19 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Gönderilen karakteri bulunca, bulduğu yerden itibaren döndürür.
*/

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	a;

	a = ft_strlen(s);
	i = 0;
	while (i <= a)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    const char str[] = "eglendiremediklerimizdenmisiniz";
    char *s;
    
    s = ft_strchr(str, 'z');
    printf("%s", s);
    printf("\n%s", strchr(str, 'z'));
}
*/