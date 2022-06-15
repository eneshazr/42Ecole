/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:11:59 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/21 15:49:12 by ehazir           ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*b;
	size_t	c;
	size_t	d;

	d = 0;
	c = ((size_t)start);
	if (!s)
		return (0);
	while (d < len && s[d + start] != '\0')
		d++;
	b = malloc((d + 1) * sizeof(char));
	if (!b)
		return (0);
	a = 0;
	while (a < len && c < ft_strlen(s))
	{
		b[a] = s[c];
		a++;
		c++;
	}
	b[a] = '\0';
	return (b);
}

/*
int main()
{
	char *str;

	str = ft_substr("Ferdi TAYFUR", 6, 6);
	printf("%s\n", str);
}
*/
