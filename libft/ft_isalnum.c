/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:32:11 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/07 14:01:45 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int str)
{
	if ((str >= 65 && str <= 90)
		|| (str >= 97 && str <= 122)
		|| (str >= 48 && str <= 57))
		return (str);
	return (0);
}

/*
#include <stdio.h>
int main()
{
    printf("%d", ft_isalnum('a'));
}
*/
/* alfabetik ve sayısal değerler */
