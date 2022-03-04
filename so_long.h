/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:34:44 by inunez-g          #+#    #+#             */
/*   Updated: 2022/03/04 10:42:31 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "constant.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	int		*data;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		cols;
	int		rows;
	int		pos_x;
	int		pos_y;
	int		colec_restantes;
	int		moves;
	int		pos_x_exit;
	int		pos_y_exit;
	int		exit;
	int		coleccionables;
	int		inicio;
	int		fin;
	int		r;
}	t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	my_map;
	t_list	*lst_map;
}				t_vars;

int		key_hook(int keycode, t_vars *vars);

int		closer(t_vars *vars);

void	get_map(char *file, t_vars *vars);

void	mapa_invalido(void);

void	img_init(t_vars	*vars);

int		ft_put_image(t_vars *vars, char *path, int j, int i);

void	lst_to_array(t_vars	*vars);

void	is_map_correct(t_vars *vars, int i);

void	is_map_correct2(t_vars *vars, int i);

void	bordes_validos(t_vars *vars, int i);

void	draw_rectangles2(t_vars *vars, int j, int i);

void	draw_rectangles3(t_vars *vars, int j, int i, int move);

void	draw_rectangles4(t_vars *vars, int j, int i, int move);

void	draw_rectangles(t_vars *vars, int move);

void	screen_moves(t_vars *vars);

int		move_w(t_vars *vars);
int		move_a(t_vars *vars);
int		move_s(t_vars *vars);
int		move_d(t_vars *vars);

#endif
