/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:01:14 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/07 14:56:11 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/*
Str parametre değeri ile gösterilen karakter dizisinde bulunan
 son c parametre değerinin bellek adresini gösteren
 bir işaretçi geri döndürülür.
Değer bulunmazsa, NULL bir işaretçi geri döndürülür.
 
strrchr() fonksiyonu ile bir karakter dizisi içinde
 'i' karakterinin bulunduğu son yeri arar.
Karakterin bulunduğu yerden itibaren dizi içeriğini ekrana yazar.
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	while (s[i])
	{
		if (s[i] == c)
			ptr = (char *)(s + i);
		i++;
	}
	if (s[i] == c)
		ptr = (char *)(s + i);
	return (ptr);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    const char str[] = "eglendiremediklerimizdenmisiniz";
    char *s;
    
    s = ft_strrchr(str, 'i');
    printf("%s", s);
    printf("\n%s", strrchr(str, 'i'));
}
*/
