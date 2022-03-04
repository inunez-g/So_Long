/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_getmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:46:34 by inunez-g          #+#    #+#             */
/*   Updated: 2022/03/04 10:50:48 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(char *file, t_vars *vars)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(file, O_RDONLY);
	vars->lst_map = NULL;
	while (1)
	{
		line = NULL;
		line = get_next_line(fd);
		if (line != NULL && ft_strlen(line) > 0)
		{
			len = ft_strlen(line) - 1;
			if (len != vars->my_map.cols && vars->my_map.cols != 0)
				mapa_invalido();
			vars->my_map.cols = len;
			ft_lstadd_back(&vars->lst_map, ft_lstnew(ft_strdup(line)));
			free(line);
			vars->my_map.rows += 1;
		}
		else
			break ;
	}
	close(fd);
	lst_to_array(vars);
}

void	lst_to_array(t_vars *vars)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = vars->lst_map;
	vars->my_map.map = (char **)malloc(sizeof(char *)
			* (vars->my_map.rows + 1));
	if (!vars->my_map.map)
		return ;
	while (i < vars->my_map.rows)
	{
		vars->my_map.map[i] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	vars->my_map.map[vars->my_map.rows] = NULL;
	is_map_correct(vars, i);
}

void	is_map_correct(t_vars *vars, int i)
{
	vars->my_map.inicio = 0;
	vars->my_map.fin = 0;
	vars->my_map.coleccionables = 0;
	vars->my_map.moves = 0;
	is_map_correct2(vars, i);
	if ((vars->my_map.coleccionables > 0) && (vars->my_map.inicio == 1)
		&& (vars->my_map.fin == 1))
		return ;
	else
		mapa_invalido();
}

void	is_map_correct2(t_vars *vars, int i)
{
	int	j;

	i = 0;
	bordes_validos(vars, i);
	while (i < vars->my_map.rows)
	{
		j = 0;
		while (j < vars->my_map.cols)
		{
			if (vars->my_map.map[i][j] == 'C')
				vars->my_map.coleccionables += 1;
			else if (vars->my_map.map[i][j] == 'P')
				vars->my_map.inicio += 1;
			else if (vars->my_map.map[i][j] == 'E')
				vars->my_map.fin += 1;
			else if (vars->my_map.map[i][j] != '0' &&
					vars->my_map.map[i][j] != '1')
				mapa_invalido();
			j++;
		}
		i++;
	}
}

void	bordes_validos(t_vars *vars, int i)
{
	int	j;

	j = vars->my_map.rows - 1;
	while (i < vars->my_map.cols)
	{
		if (vars->my_map.map[0][i] == '1' && vars->my_map.map[j][i] == '1')
			i++;
		else
			mapa_invalido();
	}
	j = vars->my_map.cols - 1;
	while (i < vars->my_map.rows)
	{
		if (vars->my_map.map[i][0] == '1' && vars->my_map.map[i][j] == '1')
			i++;
		else
			mapa_invalido();
	}
}
