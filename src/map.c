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

	i = 0;
	map.char_field = (char **)malloc(sizeof(char *) * (map.coordinate_y + 1));
	while (get_next_line(map.fd, &line) > 0)
	{
		if (ft_strstr(line, "000")) // beginning of the actual field
		{
			while (i < map.coordinate_y)
			{
				map.char_field[i] = ft_strnew(map.coordinate_x) // malloc new string
				start_source = ft_strchr(line, ' ') + 1; // start of the source string to copy to array
				ft_strcpy(map.char_field[i], start_source);
				i++;
				ft_strdel(&line);			
			}
		}

	}
	map.char_field[i] = NULL;
	int_map_init(map);
}

void	fill_map_int(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map.coordinate_y)
	{
		j = 0;
		while (j < map.coordinate_x)
		{
			if(map.char_field[i][j] == '.')
				map.field[i][j] = DOT;
			else if (map.char_field[i][j] == map.player || 
				map.char_field[i][j] == (map.player + 32)) // uppercase/ lowercase check
				map.field[i][j] = PLAYER;
			else if (map.char_field[i][j] == map.enemy || 
				map.char_field[i][j] == (map.enemy + 32)) // uppercase/ lowercase check
				map.field[i][j] = ENEMY;
			j++;
		}
		i++;
	}
}

void	int_map_init(t_map *map)
{
	int	i;

	i = 0;
	map.field = (int **)malloc(sizeof(int *) * (map.coordinate_y));
	while (i < map.coordinate_y)
	{
		map.field[i] = (int *)malloc(sizeof(int) * (map.coordinate_x));
		i++;
	}
	fill_int_map(map);
}