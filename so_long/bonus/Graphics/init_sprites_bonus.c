/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:16:35 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:16:36 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

void	exit_sprite_bonus(t_data *data, int i, int j)
{
	if (data->map.can_exit == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit_l,
			j * IMG_SIZE, i * IMG_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit_u,
			j * IMG_SIZE, i * IMG_SIZE);
}

void	init_coin_bonus(t_data *data)
{
	data->img.coin1 = mlx_xpm_file_to_image(data->mlx, COIN1,
			&data->img.width, &data->img.height);
	data->img.coin2 = mlx_xpm_file_to_image(data->mlx, COIN2,
			&data->img.width, &data->img.height);
	data->img.coin3 = mlx_xpm_file_to_image(data->mlx, COIN3,
			&data->img.width, &data->img.height);
	data->img.coin4 = mlx_xpm_file_to_image(data->mlx, COIN4,
			&data->img.width, &data->img.height);
	data->img.coin5 = mlx_xpm_file_to_image(data->mlx, COIN5,
			&data->img.width, &data->img.height);
}
