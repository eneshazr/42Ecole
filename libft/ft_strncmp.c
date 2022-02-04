/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:38:14 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/04 16:02:26 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include "libft.h"

/*
str1: Karşılaştırma yapılacak ilk karakter dizisinin başlangıcını gösteren bir işaretçidir.

str2: Karşılaştırma yapılacak ikinci karakter dizisinin başlangıcını gösteren bir işaretçidir.

n: Karşılaştırma yapılacak karakter sayısını gösterir.

gönderdiğin 2 değeri N kadar karşılaştırır
*/
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char   *str1;
    unsigned char   *str2;
    size_t  i;

    i = 0;
    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    while (i < n && (str1[i] || str2[i]))
    {
        if (str1[i] > str2[i])
            return (1);
        else if (str2[i] > str1[i])
            return (-1);
        i++;
    }
    return (0);
}

/*
int main()
{
    const char *str = "B";
    const char *str2 = "A";
    
    printf("%d", ft_strncmp(str, str2, 35));
    printf("\n%d", strncmp(str, str2, 35));
}
*/