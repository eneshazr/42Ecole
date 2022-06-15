/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_msg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:16:15 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:16:15 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

void	move_msg_bonus(t_data *data)
{
	ft_putstr_fd("\e[1;1H\e[2J", 1);
	ft_putstr_fd("\033[38;5;217m", 1);
	printf("Hareket Sayaci : %d\n", data->steps_count);
}
