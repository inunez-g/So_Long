/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_drawmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:43:53 by inunez-g          #+#    #+#             */
/*   Updated: 2022/03/04 11:51:30 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_rectangles3(t_vars *vars, int j, int i, int move)
{
	if (move == 0)
		ft_put_image(vars, "so_long_objs/cochecito_arri.xpm", j, i);
	else if (move == 1)
		ft_put_image(vars, "so_long_objs/cochecito_dere.xpm", j, i);
	else if (move == 2)
		ft_put_image(vars, "so_long_objs/cochecito_aba.xpm", j, i);
	else if (move == 3)
		ft_put_image(vars, "so_long_objs/cochecito_izqu.xpm", j, i);
	vars->my_map.pos_x = i;
	vars->my_map.pos_y = j;
}

void	draw_rectangles2(t_vars *vars, int j, int i)
{
	if (i == 0 && j >= 1 && j < vars->my_map.cols - 1)
		ft_put_image(vars, "so_long_objs/pianitoarriba.xpm", j, i);
	else if (i > 0 && i < vars->my_map.rows - 1 && j == 0)
		ft_put_image(vars, "so_long_objs/pianitoizquierda.xpm", j, i);
	else if (i == vars->my_map.rows - 1 && j > 0 && j < vars->my_map.cols - 1)
		ft_put_image(vars, "so_long_objs/pianitoabajo.xpm", j, i);
	else if (j == vars->my_map.cols - 1 && i > 0 && i < vars->my_map.rows - 1)
		ft_put_image(vars, "so_long_objs/pianitoderecha.xpm", j, i);
	else if ((i == 0 && j == 0) || (i == 0 && j == vars->my_map.cols - 1)
		|| (i == vars->my_map.rows - 1 && j == 0)
		|| (i == vars->my_map.rows - 1 && j == vars->my_map.cols - 1))
		ft_put_image(vars, "so_long_objs/comisarios.xpm", j, i);
	else
	{
		if (vars->my_map.r % 2 == 0)
			ft_put_image(vars, "so_long_objs/ruedita.xpm", j, i);
		else
			ft_put_image(vars, "so_long_objs/aceitito.xpm", j, i);
		vars->my_map.r++;
	}
}

void	draw_rectangles4(t_vars *vars, int j, int i, int move)
{
	if (vars->my_map.map[i][j] == '1')
		draw_rectangles2(vars, j, i);
	else if (vars->my_map.map[i][j] != '1')
		ft_put_image(vars, "so_long_objs/carreterita.xpm", j, i);
	if (vars->my_map.map[i][j] == 'P')
		draw_rectangles3(vars, j, i, move);
	if (vars->my_map.map[i][j] == 'C')
	{
		ft_put_image(vars, "so_long_objs/trofeito.xpm", j, i);
		vars->my_map.colec_restantes += 1;
	}
	if (vars->my_map.map[i][j] == 'E')
	{
		ft_put_image(vars, "so_long_objs/semaforito_roj.xpm", j, i);
		vars->my_map.pos_x_exit = j;
		vars->my_map.pos_y_exit = i;
	}
}

void	draw_rectangles(t_vars *vars, int move)
{
	int	i;
	int	j;

	vars->my_map.r = 0;
	i = 0;
	vars->my_map.colec_restantes = 0;
	while (i < vars->my_map.rows)
	{
		j = 0;
		while (j < vars->my_map.cols)
		{
			draw_rectangles4(vars, j, i, move);
			j++;
		}
		i++;
	}
	if (vars->my_map.colec_restantes == 0)
	{
		ft_put_image(vars, "so_long_objs/semaforito_ver.xpm",
			vars->my_map.pos_x_exit, vars->my_map.pos_y_exit);
		vars->my_map.exit = 1;
	}
}

int	ft_put_image(t_vars *vars, char *path, int j, int i)
{
	vars->img.img = mlx_xpm_file_to_image(vars->mlx,
			path, &vars->img.width, &vars->img.height);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.img, j * TILE_SIZE, i * TILE_SIZE);
	return (0);
}
