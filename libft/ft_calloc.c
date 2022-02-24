/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:29 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/24 12:50:25 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Bellekte 'size' kadar alan oluşturur içine NULL atar.
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
#include <stdio.h>
int main()
{
    int *a;
    a = (int *) ft_calloc(5, sizeof(char));
    printf("%p - %d\n", a, *a);
}
*/