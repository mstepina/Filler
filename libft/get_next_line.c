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

t_array	*list_create(const int fd)
{
	t_array		*head;

	if ((head = (t_array*)malloc(sizeof(t_array))) == NULL)
		return (NULL);
	head->fd_counter = fd;
	head->left_over_str = ft_strnew(BUFF_SIZE);
	head->next = NULL;
	return (head);
}

int		ft_read(int fd, char *buff, char **str, char *left_over)
{
	int						fd_number;
	char					*cp;
	int						t;

	t = 0;
	fd_number = -42;
	if (!(cp = ft_strchr(left_over, '\n')))
	{
		while (fd_number != 0 && (cp = ft_strchr(*str, '\n')) == 0 && t != 1)
		{
			fd_number = read(fd, buff, BUFF_SIZE);
			if (fd_number == -1)
				return (-1);
			buff[fd_number] = '\0';
			*str = ft_check(*str, left_over, buff, &t);
		}
	}
	else
	{
		*str = ft_strsub(left_over, 0, (cp - left_over));
		ft_strcpy(left_over, ++cp);
	}
	if (fd_number == 0)
		ft_strclr(left_over);
	return (((ft_strlen(*str) > 0 || fd_number) ? 1 : 0));
}

char	*ft_check(char *str, char *left_over, char *buff, int *t)
{
	char			*cp;
	char			*tmp;

	tmp = NULL;
	if ((cp = ft_strchr(buff, '\n')))
	{
		ft_strcpy(left_over, ++cp);
		ft_strclr(--cp);
	}
	ft_strcat(str, buff);
	tmp = str;
	str = ft_strnew(ft_strlen(tmp) + (BUFF_SIZE + 1));
	ft_strcat(str, tmp);
	ft_strdel(&tmp);
	ft_strclr(buff);
	if (cp != NULL)
		*t = 1;
	return (str);
}

int		get_line(const int fd, char **line, char *left_over)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;

	*line = ft_strnew(ft_strlen(left_over) + BUFF_SIZE + 1);
	ft_strcat(*line, left_over);
	if (((ret = ft_read(fd, buff, line, left_over)) < 0) || fd < 0)
		return (-1);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static	t_array	*data_list;
	t_array			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (data_list == NULL)
		data_list = list_create(fd);
	tmp = data_list;
	while (tmp->fd_counter != fd)
	{
		if (tmp->next == NULL)
			tmp->next = list_create(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->left_over_str);
	return (ret);
}

// void	n_check(int fd, char **line, char **str)
// {
// 	int		i;
// 	char	*temp;

// 	i = 0;
// 	while (str[fd][i] != '\n')
// 		i++;
// 	if (str[fd][i] == '\n')
// 	{
// 		*line = ft_strsub(str[fd], 0, i);
// 		temp = ft_strdup(str[fd] + i + 1);
// 		free(str[fd]);
// 		str[fd] = temp;
// 		if (str[fd][0] == '\0')
// 			ft_strdel(&str[fd]);
// 	}
// }

// /*
// ** Gets the pointer to the last line in the file.
// */

// void	end_check(int fd, char **line, char **str)
// {
// 	*line = ft_strdup(str[fd]);
// 	ft_strdel(&str[fd]);
// }


// /*
// ** Function checks the line for a new line character or the end of the file  
// */

// void	checker(int fd, char **line, char **str)
// {
// 	int i;

// 	i = 0;
// 	while (str[fd][i] != '\n' && str[fd][i] != '\0')
// 		i++;
// 	if (str[fd][i] == '\n')
// 		n_check(fd, line, str);
// 	else if (str[fd][i] == '\0')
// 		end_check(fd, line, str);
// }

// /* 
// ** Reads the file of BUFF_SIZE characters. If str array for this file descriptor is empty,
// ** it copies the content of the buffer into it. Otherwise, with the help of ft_strjoin function
// ** it adds the content of the buffer to the end of the fd element of str array. 
// ** The reading stops if there is a new line character
// */

// int		read_func(int fd, char **str, int res)
// {
// 	char		buff[BUFF_SIZE + 1];
// 	char		*tmp;

// 	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
// 	{
// 		buff[res] = '\0';
// 		if (!str[fd])
// 			str[fd] = ft_strdup(buff);
// 		else
// 		{
// 			tmp = ft_strjoin(str[fd], buff);
// 			ft_strdel(&str[fd]);
// 			str[fd] = tmp;
// 		}
// 		if (ft_strchr(str[fd], '\n'))
// 			break ;
// 	}
// 	return (res);
// }

// /*
// ** First, the function checks for errors (invalid file descriptor, empty line or buffer size less than 1).
// ** If there are any, returns -1. 
// ** Then it calls read_func, that reads BUFF_SIZE from the file. If reading fails, returns -1. 
// ** If there are no new line characters in the file, returns 0. 
// ** If there is at least one new line in the file, but the file does not end with a new line character,
// ** the function should return this line too (see recursive call of get_next_line function).
// */

// int		get_next_line(const int fd, char **line)
// {
// 	static char	*fd_str[4864];
// 	int			res;

// 	res = 0;
// 	if (fd < 0 || !line || BUFF_SIZE <= 0)
// 		return (-1);
// 	res = read_func(fd, fd_str, res);
// 	if (res < 0)
// 		return (-1);
// 	if (res == 0 && (!fd_str[fd] || fd_str[fd][0] == '\0'))
// 		return (0);
// 	if (!(ft_strchr(fd_str[fd], '\n')) && fd_str[fd] && res > 0)
// 		get_next_line(fd, line);
// 	checker(fd, line, fd_str);
// 	return (1);
// }
