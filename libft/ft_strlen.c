/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:10 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/01 13:36:11 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *str)
/* size_t eksi değer tutmaz. Bu yüzden döngü ile null olana kadar döndürmemize gerek kalmıyor. */
{
    size_t a;
    
    a = 0;
    while (str[i])
        a++;
    return (a);
}
