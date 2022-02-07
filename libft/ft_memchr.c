/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:59 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/07 14:39:33 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ilk geçtiği yeri arar ve bu bellek adresini gösteren bir
işaretçi geri döndürür.
Eğer str parametresi NULL bir işaretçi ise anlamsız
bir sonuç elde edilir.

str: Aramanın yapılacağı bellek bölgesini işaretçidir.
c: Aranacak olan değeri gösterir. Değer int olarak verilir
ancak fonksiyon değeri unsigned char bir değere çevirerek arama işlemi yapar.
n: Ptr parametresi ile gösterilen bellek bölgesinde
aranacak byte sayısını gösterir.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/*
Program memchr() fonksiyonu ile bir karakter dizisi içinde
'm' karakterini arar.
*/
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
