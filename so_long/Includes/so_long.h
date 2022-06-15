/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:14:50 by ehazir            #+#    #+#             */
/*   Updated: 2022/06/15 12:14:50 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*exit;
	void	*coin;
}				t_img;

typedef struct s_map
{
	int		fd;
	char	**map;
	char	*path;
	int		line_count;
	int		line_len;
	int		count_p;
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
# ifndef SO_LONG_BONUS_H
#  define IMG_SIZE 32
#  define IMG_WALL "img/wall.xpm"
#  define IMG_GROUND "img/ground.xpm"
#  define IMG_PLAYER "img/player.xpm"
#  define IMG_EXIT "img/exit.xpm"
#  define IMG_COIN "img/coin.xpm"
# endif
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
void	error_msg(char *str, t_data *data);
void	error_msg2(char *str);
int		name_check(char *str);
int		check_chars(t_data *data);
int		check_map(t_data *data);
int		check_rectangle(t_data *data);
int		check_edges(int line_count, char **map);
int		check_top_bot(int row, char **map);
/*
**
**  INIT
**
*/
void	create_map(char *mappath, t_data *data);
int		line_count(char *mappath);
void	put_input_in_map(int row, int column, int i, t_data *data);
void	ft_free(t_data *data);
void	init_map(t_data *data);
void	f_init_player(t_data *data);
/*
**
**  GRAPHICS
**
*/
int		init_window(t_data *data);
void	init_images(t_data *data);
void	loop_images(t_data data);
void	destroy_images(t_data *data);
int		render(t_data *data);
void	map_char(t_data *data, int i, int j);
/*
**
**  EVENTS
**
*/
int		handle_btnx(t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	move_player(t_data *data, char direction);
void	move(char direction, t_data *data);
void	move_msg(t_data *data);
int		check_next_tile(t_data *data, char direction, char tile);
void	collect_coins(t_data *data, char direction);
void	win_game(t_data *data);

#endif
