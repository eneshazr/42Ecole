/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:09:40 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/03 12:09:43 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
dest: Src parametresindeki verilerin kopyalanacağı belleği gösteren işaretçidir.
src: dest parametresine kopyalanacak karakterlerin bellek başlangıcını gösteren bir işaretçidir.
n: Kopyalanacak maksimum karakter sayısıdır.
*/
void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *d;
    unsigned char *s;
    
    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    if (d < s)
        while (len--)
            *d++ = *s++;
    else
    {
        d += len;
        s += len;
        while (len--)
            *--d = *--s;
    }
    return (dst);
}

int main()
{
    char src[] = "eglendiremediklerimizdenmisiniz";
    char dst[40];
    
    printf("%d", ft_memmove(dst, src, 3));
}
