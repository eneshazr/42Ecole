/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:24:52 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/15 17:13:44 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
void	upper(unsigned int i, char* d)
{
	int	a;
	a = 0;
	i = 0;
	if (*d)
	{
		d[a] = d[a] - 32;
	}
}
int	main()
{
	char test[] = "onur";
	ft_striteri(test,upper);
	printf("%s",test);
}
*/