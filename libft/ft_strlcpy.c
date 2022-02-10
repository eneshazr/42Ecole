/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:21:05 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/09 14:30:43 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 strLcpy hedefe her zaman tek bir NUL baytı yazar (boyut sıfır değilse)
 Ortaya çıkan dize kesilse bile NUL ile sonlandırılacağı garanti edilir
 Ayrıca, strNcpy'den farklı olarak, arabelleğin geri kalanını
 doldurmak için birden fazla NUL baytı yazmakla zaman kaybetmez.
 
 NUL ile sonlandırılan src dizesinden dst'ye -1 karaktere kadar kopyalar
 sonucu NUL ile sonlandırır.

 eglendiremediklerimizdenmisini1231312z
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_l;

	i = 0;
	src_l = ft_strlen(src);
	if (!dstsize)
		return (src_l);
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize < src_l)
		dst[dstsize - 1] = '\0';
	else if (dstsize != 0)
		dst[i] = '\0';
	return (src_l);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char src[] = "eglendiremediklerimizdenmisini1231312z";
    char dst[] = " ";
    
    printf("%zu\n", ft_strlcpy(dst, src, 5));
	printf("%zu", strlcpy(dst, src, 1));
}
*/