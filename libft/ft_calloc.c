/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:29 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/21 12:31:08 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Boyutları byte olarak ifade edilen ve 'size' parametre kadar olan bellekten
count parametre değeri kadar sayıda bellek bloğunu tahsis eder. 
Tahsis edilen belleğin tamamı sıfır değer ile doldurur.
Bellek bloğunun başlangıç adresini gösteren bir işaretçi geri döndürür.

count, tahsis edilecek eleman sayısını gösterir.
size, her bir elemanın byte olarak boyutunu gösterir.

sizeof, makineye göre farklı çıktılar verebilir.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = size * count;
	dst = malloc(tot_size);
	if (!dst)
		return (0);
	ft_memset(dst, 0, tot_size);
	return (dst);
}
/*
Başarı durumunda tahsis edilen belleğin başlangıç adresini döndürür.
Hata durumunda NULL döndürür.
*/

/*
#include <stdio.h>
int main()
{
    int *a;
    a = (int *) ft_calloc(5, sizeof(char));
    printf("%p - %d\n", a, *a);
}
*/