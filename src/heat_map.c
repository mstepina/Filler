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

void	put_figure(t_map *map)
{
	int	i;
	int	j;
	int current_sum;
	int lowest_sum;

	i = 0;
	lowest_sum = 1000;
	while (i + map->piece_y < map->coordinate_y)
	{
		j = 0;
		while (j + map->piece_x < map-> coordinate_x)
		{
			if (check_collision(map, i, j))
			{
				current_sum = figure_sum(map, i, j);
				if (current_sum < lowest_sum)
				{
					lowest_sum = current_sum;
					map->res_x = j;
					map->res_y = i;
				}
			}
			j++;
		}
		i++;
	}
	//ft_printf("%d\n lowest sum", lowest_sum);
	ft_printf("%d %d\n", map->res_y, map->res_x);
	// if (lowest_sum == 1000)
	// {
	// 	//ft_printf("bad figure");
	// 	return (1);
	// }
	// else
	// 	return (0);
}

int		check_collision(t_map *map, int i, int j)
{
	int a;
	int b;
	int coll;

	coll = 0;
	a = 0;
	while (a < map->piece_y)
	{
		b = 0;
		while (b < map->piece_x)
		{
			if (map->field[i + a][j + b] == PLAYER && map->figure_repr[a][b] == '*')
			{	
				coll++;

			}
			// if (map->field[i + a][j + b] == PLAYER && map->figure_repr[a][b] == '.')
			// 	return (0);
			if (map->field[i + a][j + b] == ENEMY && map->figure_repr[a][b] == '*')
				return (0);
			b++;
		}
		if (coll > 1)
			return (0);
		a++;
	}
	return (coll);
}


int		figure_sum(t_map *map, int i, int j)
{
	int	a;
	int	b;
	int sum;

	sum = 0;
	a = 0;
	while (a < map->piece_y)
	{
		b = 0;
		while (b < map->piece_x)
		{
			if (map->figure_repr[a][b] == '*' && map->field[i + a][j + b] != PLAYER)
				sum += map->field[i + a][j + b];
			b++;
		}
		a++;
	}
	return (sum);
}


/**********************
**********************
**********************/

// void	small_move(t_map *map, int i, int j)
// {
// 	int x;
// 	int y;

// 	y = map->current_y;
// 	while (i < map->piece_y)
// 	{
// 		j = 0;
// 		x = map->current_x;
// 		while (j < map->piece_x)
// 		{
// 			if (map->figure_repr[i][j] == '*' && map->field[y][x] == ENEMY)
// 			{
// 				map->overlay_enemy++;
// 				break ;
// 			}
// 			if (map->figure_repr[i][j] == '*' && map->field[y][x] == PLAYER)
// 				map->overlay_me++;
// 			j++;
// 			x++;
// 		}
// 		i++;
// 		y++;
// 	}
// }




// void	put_figure(t_map *map)
// {
// 	map->res_x = 0;
// 	map->res_y = 0;
// 	map->current_y = 0;
// 	while (map->current_y <= (map->coordinate_y - map->piece_y))
// 	{
// 		map->current_x = 0;
// 		while (map->current_x <= (map->coordinate_x - map->piece_x))
// 		{
// 			map->overlay_me = 0;
// 			map->overlay_enemy = 0;
// 			small_move(map, 0, 0);
// 			if (map->overlay_me == 1 && map->overlay_enemy == 0)
// 				lowest_summ(map, map->current_x, map->current_y);
// 			map->current_x++;
// 		}
// 		map->current_y++;
// 	}
// }

// void	lowest_summ_check(t_map *map, int sum, int x_return, int y_return)
// {
// 	if (sum < map->l_sum)
// 	{
// 		map->l_sum = sum;
// 		map->res_x = x_return;
// 		map->res_y = y_return;
// 	}
// }

// void	lowest_summ(t_map *map, int current_x, int current_y)
// {
// 	int x;
// 	int y;
// 	int	sum;
// 	int x_return;
// 	int y_return;

// 	y = 0;
// 	sum = 0;
// 	x_return = current_x;
// 	y_return = current_y;
// 	while (current_y < (y_return + map->piece_y) && current_y < map->coordinate_y)
// 	{
// 		x = 0;
// 		current_x = x_return;
// 		while (current_x < (x_return + map->piece_x) & current_x < map->coordinate_x)
// 		{
// 			if (map->figure_repr[y][x] == '*')
// 				sum += map->field[current_y][current_x];
// 			current_x++;
// 			x++;
// 		}
// 		current_y++;
// 		y++;
// 	}
// 	lowest_summ_check(map, sum, x_return, y_return);
// }







