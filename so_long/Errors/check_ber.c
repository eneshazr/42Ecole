/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:15:38 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:15:38 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	name_check(char *str)
{
	str = ft_strchr(str, '.');
	if (!str)
		return (FAILURE);
	if (ft_strnstr(str, ".ber", 4))
		return (SUCCESS);
	return (FAILURE);
}
