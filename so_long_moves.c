/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:41:47 by inunez-g          #+#    #+#             */
/*   Updated: 2022/03/04 10:50:56 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	key_hook(int keycode, t_vars *vars)
{
	int		helper;

	(void)vars;
	helper = 0;
	if (keycode == W)
		helper = move_w(vars);
	else if (keycode == S)
		helper = move_s(vars);
	else if (keycode == A)
		helper = move_a(vars);
	else if (keycode == D)
		helper = move_d(vars);
	else if (keycode == ESCAPE)
		exit(0);
	if (helper == 1)
		screen_moves(vars);
	return (0);
}

int	move_w(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->my_map.pos_x;
	y = vars->my_map.pos_y;
	if (vars->my_map.map[x - 1][y] == '0')
	{
		vars->my_map.map[x][y] = '0';
		vars->my_map.map[x - 1][y] = 'P';
		draw_rectangles(vars, 0);
		return (1);
	}
	else if (vars->my_map.map[x - 1][y] == 'C')
	{
		vars->my_map.map[x][y] = '0';
		vars->my_map.map[x - 1][y] = 'P';
		draw_rectangles(vars, 0);
		return (1);
	}
	else if (vars->my_map.map[x - 1][y] == 'E' && vars->my_map.exit == 1)
		exit (0);
	else
		draw_rectangles(vars, 0);
	return (0);
}

int	move_s(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->my_map.pos_x;
	y = vars->my_map.pos_y;
	if (vars->my_map.map[x + 1][y] == '0')
	{
		vars->my_map.map[x][y] = '0';
		vars->my_map.map[x + 1][y] = 'P';
		draw_rectangles(vars, 2);
		return (1);
	}
	else if (vars->my_map.map[x + 1][y] == 'C')
	{
		vars->my_map.map[x][y] = '0';
		vars->my_map.map[x + 1][y] = 'P';
		draw_rectangles(vars, 2);
		return (1);
	}
	else if (vars->my_map.map[x + 1][y] == 'E' && vars->my_map.exit == 1)
		exit (0);
	else
		draw_rectangles(vars, 2);
	return (0);
}

int	move_a(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->my_map.pos_x;
	y = vars->my_map.pos_y;
	if (vars->my_map.map[x][y - 1] == '0')
	{
		vars->my_map.map[x][y] = '0';
		vars->my_map.map[x][y - 1] = 'P';
		draw_rectangles(vars, 3);
		return (1);
	}
	else if (vars->my_map.map[x][y - 1] == 'C')
	{
		vars->my_map.map[x][y] = '0';
		vars->my_map.map[x][y - 1] = 'P';
		draw_rectangles(vars, 3);
		return (1);
	}
	else if (vars->my_map.map[x][y - 1] == 'E' && vars->my_map.exit == 1)
		exit (0);
	else
		draw_rectangles(vars, 3);
	return (0);
}

int	move_d(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->my_map.pos_x;
	y = vars->my_map.pos_y;
	if (vars->my_map.map[x][y + 1] == '0')
	{
		vars->my_map.map[x][y] = '0';
		vars->my_map.map[x][y + 1] = 'P';
		draw_rectangles(vars, 1);
		return (1);
	}
	else if (vars->my_map.map[x][y + 1] == 'C')
	{
		vars->my_map.map[x][y] = '0';
		vars->my_map.map[x][y + 1] = 'P';
		draw_rectangles(vars, 1);
		return (1);
	}
	else if (vars->my_map.map[x][y + 1] == 'E' && vars->my_map.exit == 1)
		exit (0);
	else
		draw_rectangles(vars, 1);
	return (0);
}
