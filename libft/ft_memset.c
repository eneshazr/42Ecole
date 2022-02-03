/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <ehazir@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:43 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/01 13:36:46 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

 /* memset, bir bellek bloğunu verilen/belirli bir değerle doldurmak için kullanılır. Belleğin bloklarının tamamını veya bir kısmını belirli bir değerle doldurulabilir */

void *ft_memset(void *b, int c, size_t len)
{
    size_t i;
    unsigned char *byt;
    
    i = 0;
    byt = (unsigned char *)b;
    while (i < len)
    {
        byt[i] = c;
        i++;
    }
    return (b = byt);
}
