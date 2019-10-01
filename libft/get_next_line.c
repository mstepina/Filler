/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:26:46 by mstepina          #+#    #+#             */
/*   Updated: 2019/09/25 17:13:02 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Finds a new line character. Gets the pointer to the line
** (up to a new line character) with ft_strsub function from libft library. 
** Stores a pointer to the first character after new line character
** in a static array.
*/

void	n_check(int fd, char **line, char **str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		temp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
}

/*
** Gets the pointer to the last line in the file.
*/

void	end_check(int fd, char **line, char **str)
{
	*line = ft_strdup(str[fd]);
	ft_strdel(&str[fd]);
}


/*
** Function checks the line for a new line character or the end of the file  
*/

void	checker(int fd, char **line, char **str)
{
	int i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
		n_check(fd, line, str);
	else if (str[fd][i] == '\0')
		end_check(fd, line, str);
}

/* 
** Reads the file of BUFF_SIZE characters. If str array for this file descriptor is empty,
** it copies the content of the buffer into it. Otherwise, with the help of ft_strjoin function
** it adds the content of the buffer to the end of the fd element of str array. 
** The reading stops if there is a new line character
*/

int		read_func(int fd, char **str, int res)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			ft_strdel(&str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (res);
}

/*
** First, the function checks for errors (invalid file descriptor, empty line or buffer size less than 1).
** If there are any, returns -1. 
** Then it calls read_func, that reads BUFF_SIZE from the file. If reading fails, returns -1. 
** If there are no new line characters in the file, returns 0. 
** If there is at least one new line in the file, but the file does not end with a new line character,
** the function should return this line too (see recursive call of get_next_line function).
*/

int		get_next_line(const int fd, char **line)
{
	static char	*fd_str[4864];
	int			res;

	res = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	res = read_func(fd, fd_str, res);
	if (res < 0)
		return (-1);
	if (res == 0 && (!fd_str[fd] || fd_str[fd][0] == '\0'))
		return (0);
	if (!(ft_strchr(fd_str[fd], '\n')) && fd_str[fd] && res > 0)
		get_next_line(fd, line);
	checker(fd, line, fd_str);
	return (1);
}
