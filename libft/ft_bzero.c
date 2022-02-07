/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:01:30 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/07 14:35:12 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
/*
Bellekte n kadar s baytındaki verileri siler. '\0' (null) alana kadar.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*byt;

	i = 0;
	byt = (unsigned char *)s;
	while (i < n)
	{
		byt[i] = 0;
		i++;
	}
	s = byt;
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "eglendiremediklerimizdenmisiniz";

    ft_bzero(str, 15);
    printf(": %s", str);
    printf("\n: %s", bzero(str, 18));
}
*/
