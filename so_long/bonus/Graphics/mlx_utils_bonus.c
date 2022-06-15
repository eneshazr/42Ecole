/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:17:01 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:17:02 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

int	init_window_bonus(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ERROR);
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "SO_LONG");
	if (data->win == NULL)
	{
		free(data->win);
		return (ERROR);
	}
	return (SUCCESS);
}

void	init_images_bonus(t_data *data)
{
	init_coin_bonus(data);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, IMG_WALL,
			&data->img.width, &data->img.height);
	data->img.ground = mlx_xpm_file_to_image(data->mlx, IMG_GROUND,
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, IMG_PLAYER,
			&data->img.width, &data->img.height);
	data->img.foe = mlx_xpm_file_to_image(data->mlx, IMG_FOE,
			&data->img.width, &data->img.height);
	data->img.exit_l = mlx_xpm_file_to_image(data->mlx, IMG_LOCKED,
			&data->img.width, &data->img.height);
	data->img.exit_u = mlx_xpm_file_to_image(data->mlx, IMG_UNLCKD,
			&data->img.width, &data->img.height);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, IMG_COIN,
			&data->img.width, &data->img.height);
}

void	loop_images_bonus(t_data data)
{
	mlx_loop_hook(data.mlx, &render_bonus, &data);
	mlx_hook(data.win, 2, 1L << 0, &handle_keypress_bonus, &data);
	mlx_hook(data.win, 17, 0L, &handle_btnx_bonus, &data);
	mlx_clear_window(data.mlx, data.win);
	mlx_loop(data.mlx);
}

void	destroy_images_bonus(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.ground);
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.exit_l);
	mlx_destroy_image(data->mlx, data->img.exit_u);
	mlx_destroy_image(data->mlx, data->img.coin1);
	mlx_destroy_image(data->mlx, data->img.coin2);
	mlx_destroy_image(data->mlx, data->img.coin3);
	mlx_destroy_image(data->mlx, data->img.coin4);
	mlx_destroy_image(data->mlx, data->img.coin5);
}
