/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:23:37 by mstepina          #+#    #+#             */
/*   Updated: 2019/09/25 20:23:40 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# define PLAYER -1
# define ENEMY 0
# define DOT -5

typedef struct	s_map
{
	int			fd;
	char		player;
	char		enemy;
	int			coordinate_x;
	int			coordinate_y;
	char		**char_field;
	int			**field;
	int			piece_x;
	int			piece_y;
	int			current_x;
	int			current_y;
	// int			round;
	char		**figure_repr;
	int			heat_number;
	int			l_sum;
	int			res_x;
	int			res_y;
	int			overlay_me;
	int			overlay_enemy;
	char		*piece_str;
}				t_map;


t_map	*initial_map(int fd);
void	get_player (t_map *map);
void	get_field_params(t_map *map);
void	    filler(t_map *map);
void	get_map_char(t_map *map);
void	int_map_init(t_map *map);
void	fill_map_int(t_map *map);
void	get_piece_params(t_map *map);
void	get_figure_repr(t_map *map);
void	heat_map(t_map *map);
void	fill_heat_map(t_map *map, int i, int j);
void		put_figure(t_map *map);
int		check_collision(t_map *map, int i, int j);
int		figure_sum(t_map *map, int i, int j);

void	lowest_summ_check(t_map *map, int sum, int x_return, int y_return);
void	lowest_summ(t_map *map, int current_x, int current_y);

#endif