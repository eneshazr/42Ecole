/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:09:40 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/10 16:34:59 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
dest: Src parametresindeki verilerin kopyalanacağı belleği göstererir.
src: dest parametresine kopyalanacak karakterleri gösterir.
n: Kopyalanacak maksimum karakter sayısıdır.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char src[] = "eglendiremediklerimizdenmisiniz";
    char dst[40];
    ft_memmove(dst, src, 3);
    memmove(dst, src, 3);
    printf("%s", dst);
    printf("\n%s", dst);
}
*/
