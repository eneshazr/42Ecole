/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:15:43 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/15 11:23:13 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
- Gönderilen değerlerin uzunluğunun toplamı kadar ve sizeof(char) karşılığı kadar
bellekte yer ayır. Yani bu betikte, '12' uzunluğunda yer ayırır.
- Gönderilen değerleri birleştirir ve döndürür.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dizi;
	size_t	len;
	size_t	i;
	int		a;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	dizi = malloc(sizeof(char) * len + 1);
	if (!dizi)
		return (NULL);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			dizi[i] = s1[i];
		else
			dizi[i] = s2[a++];
		i++;
	}
	dizi[i] = '\0';
	return (dizi);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "Ferdi";
    char str2[] = " TAYFUR";
    printf("%lu\n", sizeof(int) * 11 + 1);
    printf("%s\n", ft_strjoin(str, str2));
}
*/