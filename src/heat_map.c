/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:07:06 by mstepina          #+#    #+#             */
/*   Updated: 2019/10/01 00:07:09 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	heat_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->heat_number = 1;
	while(i < map->coordinate_y)
	{
		j = 0;
		while (j < map->coordinate_x)
		{
			if (map->field[i][j] != PLAYER)
			{
				if (map->field[i][j] == 0 && (i - 1) >= 0 && (i + 1) < map->coordinate_y
				&& (j - 1) >= 0 && (j + 1) < map->coordinate_x) // check the borders of the field
				check_heat_map(map, i, j);
			}
			j++;
		
		}
		i++;
	}
}

void	check_heat_map(t_map *map, int i, int j)
{
	if (map->field[i][j + 1] == DOT)
		map->field[i][j + 1] = map->heat_number;
	if (map->field[i][j - 1] == DOT)
		map->field[i][j - 1] = map->heat_number;
	if (map->field[i + 1][j] == DOT)
		map->field[i + 1][j] = map->heat_number;
	if (map->field[i - 1][j] == DOT)
		map->field[i - 1][j] = map->heat_number;
	if (map->field[i + 1][j + 1] == DOT)
		map->field[i + 1][j + 1] = map->heat_number;
	if (map->field[i - 1][j - 1] == DOT)
		map->field[i - 1][j - 1] = map->heat_number;
	if (map->field[i + 1][j - 1] == DOT)
		map->field[i + 1][j - 1] = map->heat_number ;
	if (map->field[i - 1][j + 1] == DOT)
		map->field[i - 1][j + 1] = map->heat_number;

	// int row;
	// int col;

	// row = i - 1;
	// while (row <= i + 1)
	// {
	// 	col = j - 1;
	// 	while (col <= j + 1)
	// 	{
	// 		map->field[row][col] = map->heat_number;
	// 		col++;
	// 	}
	// 	row++;
	// }
}