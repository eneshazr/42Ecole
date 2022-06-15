/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:01:30 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:43:29 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
/*
Bellekte n kadar s baytındaki verileri siler.
*/

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
