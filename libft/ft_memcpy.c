/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:32:37 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/03 12:00:17 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
memcpy, bir bellek bloğunu bir konumdan diğerine kopyalamak için kullanılır
dest − içeriğin kopyalanacağı hedef dizinin işaretçisidir,
void* türünde bir işaretçiye tipleme yapılır.
src − kopyalanacak veri kaynağına yönelik işaretçidir,
void* türünde bir işaretçiye tip dökümü yapılır.
n - kopyalanacak bayt sayısıdır.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "eglendiremediklerimizdenmisiniz";
    char dest[40];

    ft_memcpy(dest, str, 8);
    printf("O: %s\n", dest);
	printf("O: %s", memcpy(dest,str,8));
}
*/
/*
n sıfır olana kadar döner ve
dest'e src de ki karakterleri atar.
*/
