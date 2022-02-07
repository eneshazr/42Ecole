/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:38:14 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/07 14:46:52 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/*
Gönderilen diziden karakter ile arama yapar.
str: Aramanın yapılacağı karakter dizisidir.
c: Aranacak olan değeri gösterir. Değer int olarak verilir ancak
 fonksiyon bu değeri unsigned char bir değere çevirerek arama işlemi yapar.
*/
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == c)
		return ((char *)str + i);
	return (0);
}

/*
Gönderilen dizi kadar dön
Dizide aranan karakteri bulunca koşulu sağla
karakter eşitlenince sadece diziden 1 karakter arttırılır.
*/

/*
#include <stdio.h>
#include <string.h>
int main()
{
    const char str[] = "eglendiremediklerimizdenmisiniz";
    char *s;
    
    s = ft_strchr(str, 'i');
    printf("%s", s);
    printf("\n%s", strchr(str, 'i'));
}
*/
