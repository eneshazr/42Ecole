/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:15:54 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:15:55 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

int	name_check_bonus(char *str)
{
	str = ft_strchr(str, '.');
	if (!str)
		return (FAILURE);
	if (ft_strnstr(str, ".ber", 4))
		return (SUCCESS);
	return (FAILURE);
}
