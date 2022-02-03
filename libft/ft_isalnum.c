/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:32:11 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/03 11:32:20 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_isalpha(int str)
{
    if (str < 'A' || str > 'Z' && str < 'a' || str > 'z' && str >= 48 || str <= 57)
        return (0);
    return (1);
}

int main()
{
    printf("%d", ft_isalpha('a'));
}

/* alfabetik ve sayısal değerler */
