/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:06:32 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/21 15:08:47 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Bir bellek bloğunu verilen bir değerle doldurmak için kullanılır.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*byt;

	i = 0;
	byt = (unsigned char *)b;
	while (i < len)
	{
		byt[i] = c;
		i++;
	}
	return (byt);
}

/*
int main()
{
    char src[] = "eglendiremediklerimizdenmisiniz";
    ft_memset(src, 'x', 3);
	printf("%s", src);
}
*/