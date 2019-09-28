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
# define ENEMY -5
# define DOT 0

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
	int			round;
	char		**figure_map;
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
void	filler(t_map *map);
void	get_map_char(t_map *map);
void	int_map_init(t_map *map);

#endif