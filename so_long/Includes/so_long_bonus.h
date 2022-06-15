/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:14:38 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:14:39 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_img
{
	int		height;
	int		width;
	void	*wall;
	void	*ground;
	void	*player;
	void	*foe;
	void	*coin;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*exit_l;
	void	*exit_u;
}				t_img;

typedef struct s_map
{
	int		fd;
	char	**map;
	char	*path;
	int		line_count;
	int		line_len;
	int		count_p;
	int		count_f;
	int		count_e;
	int		count_c;
	int		collected;
	int		can_exit;
}				t_map;

typedef struct s_data
{
	t_map	map;
	t_img	img;
	int		i;
	int		j;
	int		p_i;
	int		p_j;
	int		steps_count;
	void	*win;
	void	*mlx;
	int		win_height;
	int		win_width;
	int		d;
}				t_data;

# define FAILURE	1
# define SUCCESS	0
# define ERROR 		-1
# define RED    	"\033[0;31m"
# define GREEN  	"\033[1;32m"
/*
**  KEYS
*/
# define ESC 53
# define W	 13
# define A	 0
# define S	 1
# define D	 2
/*
**  IMG PATH
*/
# define IMG_SIZE 32
# define IMG_WALL 	"img/wall.xpm"
# define IMG_GROUND "img/ground.xpm"
# define IMG_PLAYER "img/player.xpm"
# define IMG_EXIT   "img/exit.xpm"
# define IMG_COIN	"img/coin.xpm"
# define IMG_UNLCKD "img/exit_u.xpm"
# define IMG_LOCKED	"img/exit_l.xpm"
# define IMG_FOE	"img/foe.xpm"
# define COIN1		"img/coin1.xpm"
# define COIN2		"img/coin2.xpm"
# define COIN3		"img/coin3.xpm"
# define COIN4		"img/coin4.xpm"
# define COIN5		"img/coin5.xpm"
/*
**  MSGS
*/
# define ARGERR 	"Lutfen map dosyasini giriniz..."
# define ERRBER  	"Hatali .ber dosyasi\n"
# define ERROTHER 	"Haritada en az bir gecersiz karakter var.\n"
# define ERRCHARS 	"\"0, 1, P, C, E\" karakterlerinden biri eksik.\n"
# define ERRPLAYER 	"Bu tek kisilik bir mucadele...\n"
# define ERRREC 	"Harita Dikdortgen degil."
# define ERREDGES 	"Haritanın kenarları geçersiz (duvarlar -1- olmalı).\n"
/*
**
**  ERRORS
**
*/
void	error_msg_bonus(char *str, t_data *data);
void	error_msg2_bonus(char *str);
int		name_check_bonus(char *str);
int		check_chars_bonus(t_data *data);
int		check_map_bonus(t_data *data);
int		check_rectangle_bonus(t_data *data);
int		check_edges_bonus(int line_count, char **map);
int		check_top_bot_bonus(int row, char **map);
/*
**
**  INIT
**
*/
void	create_map_bonus(char *mappath, t_data *data);
int		line_count_bonus(char *mappath);
void	put_input_in_map(int row, int column, int i, t_data *data);
void	ft_free_bonus(t_data *data);
void	init_map_bonus(t_data *data);
void	f_init_players_bonus(t_data *data);
/*
**
**  GRAPHICS
**
*/
int		init_window_bonus(t_data *data);
void	init_images_bonus(t_data *data);
void	loop_images_bonus(t_data data);
void	destroy_images_bonus(t_data *data);
int		render_bonus(t_data *data);
void	map_char_bonus(t_data *data, int i, int j, int k);
void	init_sprites_bonus(t_data *data);
void	init_coin_bonus(t_data *data);
void	exit_sprite_bonus(t_data *data, int i, int j);
void	coin_sprite_bonus(t_data *data, int i, int j, int k);
/*
**
**  EVENTS
**
*/
int		handle_btnx_bonus(t_data *data);
int		handle_keypress_bonus(int keysym, t_data *data);
void	move_player_bonus(t_data *data, char direction);
void	move_bonus(char direction, t_data *data);
void	move_msg_bonus(t_data *data);
int		check_next_tile_bonus(t_data *data, char direction, char tile);
void	collect_coins_bonus(t_data *data, char direction);
int		win_game_bonus(t_data *data);
void	foe(t_data *data, int i, int j);
void	foe_move(t_data *data, int i, int j);
void	foe_move2(t_data *data, int i, int j);

#endif
