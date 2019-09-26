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
	map = (t_map*)malloc(sizeof(t_map)); // malloc for structure
	map.fd = fd;
	get_player(map);
	get_field_params(map);
	return (map);
}

void get_player (t_map *map)
{
	char *line;

	while (get_next_line(map.fd, &line) > 0)
	{
		if (ft_strstr(line, "exec p"))
			break;
	}
	if (ft_strstr(line, "1"))
	{
		map.player = 'O';
		map.enemy = 'X';
	}
	else
	{
		map.player = 'X';
		map.enemy = 'O';
	}
	ft_strdel(&line);
}

void	get_field_params(t_map *map)
{
	char *line;

	while (get_next_line(map.fd, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			break;
		ft_strdel(&line);
	}
	map.coordinate_y = ft_atoi(ft_strchr(line, ' '));
	map.coordinate_x = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line); 
}

int main()
{
	int		fd;
	t_map 	*map;
	char	*line;


	//fd = open("maps/filler2.txt", O_RDONLY);
	fd = 0;
	map = initial_map(fd);
	while (get_next_line(map->fd, &str) > 0)
		filler(map);
	close(fd);
	//tmp_print(map);
	del_map(map);
}


int        main(void)
{
    int        fd;
    int        i;
    int        j;
    int i;
    int j;
    t_map    *map;
    char    *str;
    i = 0;
    // fd = 0;
    fd = open("src/filler.txt", O_RDONLY);
   
    map = initial_map(fd);
    while (get_next_line(map->fd, &str) > 0)
    {
        map->piece_x = ft_atoi(ft_strrchr(str, ' '));
        map->piece_y = ft_atoi(ft_strchr(str, ' '));
        filler(map);
    }
// //-----------------------------------------------------------------------
    i = 0;
    ft_printf("player: y = %d, x = %d, sum: %d\n", map->res_y, map->res_x, map->l_sum);
    ft_printf("player: %c\n", map->player);
    ft_printf("coordinate_x: %d\n", map->coordinate_x);
    close(fd);
    return (0);
}

// void	tmp_print(t_map *map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < map->coordinate_y)
// 	{
// 		j = 0;
// 		while (j < map->coordinate_x)
// 		{
// 			if (i == map->res_y && j == map->res_x)
// 				ft_printf("{yellow}%2c{eoc}", 'm');
// 			else if (map->map[i][j] == PLAYER)
// 				ft_printf("{green}%2c{eoc}", 'M');
// 			else if (map->map[i][j] == ENEMY)
// 				ft_printf("{red}%2c{eoc}", 'E');
// 			else
// 				ft_printf("%2d", map->map[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }