/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:39:22 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/22 12:42:18 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Gönderdiğimiz stringi üreterek aynısını döndürür.
*/

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *) malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

/*
#include <string.h>
#include <stdio.h>
int main()
{
	char *str;

	str = "Ferdi TAYFUR";
	printf("%s\n", ft_strdup(str));
	printf("%s", strdup(str));
}
*/