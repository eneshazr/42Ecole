/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:06:32 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/07 14:43:28 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Bir bellek bloğunu verilen bir değerle doldurmak için kullanılır.
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
	return (b = byt);
}
