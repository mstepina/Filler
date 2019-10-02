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
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

void	heat_map(t_map *map)
{
	
	int	i;
	int	j;
	int val;
	int max;

	max = MAX(map->coordinate_x, map->coordinate_y);
	val = 0;
	while (val < max)
	{
		i = 0;
		while (i < map->coordinate_y)
		{
			j = 0;
			while (j < map-> coordinate_x)
			{
				if(map->field[i][j] == val)
					fill_heat_map(map, i, j);
				j++;
			}
			i++;
		}
		val++;
	}
}

void	fill_heat_map(t_map *map, int i, int j)
{

	int col;
	int val;
	int start_row;
	int end_row;
	int start_col;
	int end_col;

	val = map->field[i][j] + 1;
	start_row = (i > 0) ? (i - 1) : i;
	end_row = (i < map->coordinate_y - 1) ? (i + 1) : i;
	start_col = (j > 0) ? (j - 1) : j;
	end_col = (j < map->coordinate_x) ? (j + 1) : j;	
	while (start_row <= end_row)
	{
		col = start_col;
		while (col <= end_col)
		{
			if (map->field[start_row][col] == DOT)
				map->field[start_row][col] = val;
			col++;
		}
		start_row++;
	}
}