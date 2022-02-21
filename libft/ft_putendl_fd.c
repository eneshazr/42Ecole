/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:36:59 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/15 12:14:29 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Değerin strlen ile uzunluğu hesaplanır ve write'de 3. parametreye koyar.
Tüm değerler yazıldıktan sonra yeni satıra(\n) geçer.
*/
void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*
int main()
{
    ft_putendl_fd("Cengiz KURTOGLU", 1);
}
*/