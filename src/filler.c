/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:40:16 by mstepina          #+#    #+#             */
/*   Updated: 2019/09/25 20:40:25 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	*initial_map(int fd)
{
	t_map *map;

	map = (t_map*)malloc(sizeof(t_map));
	map->fd = fd;
	get_player(map);
	get_field_params(map);
	return (map);
}

void	get_player(t_map *map)
{
	char *line;

	while (get_next_line(map->fd, &line))
	{
		if (ft_strstr(line, "mstepina"))
			break ;
	}
	if (ft_strstr(line, "1"))
		map->player = 'O';
	else
		map->player = 'X';
	if (map->player == 'O')
		map->enemy = 'X';
	else
		map->enemy = 'O';
	ft_strdel(&line);
}

void	get_field_params(t_map *map)
{
	char *line;

	while (get_next_line(map->fd, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			break ;
		ft_strdel(&line);
	}
	map->coordinate_y = ft_atoi(ft_strchr(line, ' '));
	map->coordinate_x = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
}

void	filler(t_map *map)
{
	int i;

	i = 0;
	get_map_char(map);
	get_piece_params(map);
	get_figure_repr(map);
	heat_map(map);
	put_figure(map);
	ft_printf("%d %d\n", map->res_y, map->res_x);
}

int		main(void)
{
	int		fd;
	t_map	*map;
	char	*str;

	fd = 0;
	map = initial_map(fd);
	while (get_next_line(map->fd, &str) > 0)
		filler(map);
	close(fd);
	return (0);
}
