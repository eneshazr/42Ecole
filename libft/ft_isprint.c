/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:38:22 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/07 16:38:24 by ehazir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int str)
{
	return (str >= 32 && str < 127);
}

/* yazdırılabilen tüm decimal karakterler */