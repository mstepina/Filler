/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:41:29 by mstepina          #+#    #+#             */
/*   Updated: 2019/09/27 16:41:32 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void get_map_char(t_map *map)
{
	char	*line;
	int		i;
	char	*start_source;

	i = 0;
	map->char_field = (char **)malloc(sizeof(char *) * (map->coordinate_y + 1));
	while (get_next_line(map->fd, &line) > 0)
	{
		if (ft_strstr(line, "000")) // beginning of the actual field
		{
			while (i < map->coordinate_y)
			{
				if (i > 0)
					get_next_line(map->fd, &line);
				map->char_field[i] = ft_strnew(map->coordinate_x); // malloc new string
				start_source = ft_strchr(line, ' ') + 1; // start of the source string to copy to array
				ft_strcpy(map->char_field[i], start_source);
				i++;
				ft_strdel(&line);			
			}
		}
		if (i == map->coordinate_y)
				break;
	}
	map->char_field[i] = NULL;
	int_map_init(map);
}

void	fill_map_int(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->coordinate_y)
	{
		j = 0;
		while (j < map->coordinate_x)
		{
			if(map->char_field[i][j] == '.')
				map->field[i][j] = DOT;
			else if (map->char_field[i][j] == map->player || 
				map->char_field[i][j] == (map->player + 32)) // uppercase/ lowercase check
				map->field[i][j] = PLAYER;
			else if (map->char_field[i][j] == map->enemy || 
				map->char_field[i][j] == (map->enemy + 32)) // uppercase/ lowercase check
				map->field[i][j] = ENEMY;
			j++;
		}
		i++;
	}
}

void	int_map_init(t_map *map)
{
	int	i;

	i = 0;
	map->field = (int **)malloc(sizeof(int *) * (map->coordinate_y));
	while (i < map->coordinate_y)
	{
		map->field[i] = (int *)malloc(sizeof(int) * (map->coordinate_x));
		i++;
	}
	fill_map_int(map);
}

void get_piece_params(t_map *map)
{
	char *line;

	while (get_next_line(map->fd, &line))
	{
		if (ft_strstr(line, "Piece"))
			break;
		ft_strdel(&line);
	}
	map->piece_x = ft_atoi(ft_strrchr(line, ' '));
	map->piece_y = ft_atoi(ft_strchr(line, ' '));
	ft_printf("piece_x: %d\n", map->piece_x);
    ft_printf("piece_y: %d\n", map->piece_y);
	ft_strdel(&line);
}



void	get_figure_repr(t_map *map)
{
	char	*line;
	int		i;

	map->figure_repr = (char **)malloc(sizeof(char *) * (map->piece_y + 1));
	i = 0;
	while (get_next_line(map->fd, &line) && (i < map->piece_y))
	{
		// while (i < map->piece_y)
		// {
			map->figure_repr[i] = ft_strnew(map->piece_x);
			ft_strcpy(map->figure_repr[i], line);
			i++;
			ft_strdel(&line);
		// }
		
	}
	map->figure_repr[i] = NULL;
}