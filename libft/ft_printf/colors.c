/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:57:56 by mstepina          #+#    #+#             */
/*   Updated: 2019/08/08 14:58:00 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

int	put_color(char *color)
{
	int i;

	i = 0;
	if (ft_strcmp("red", color) == 0)
		i = ft_putstr_all(RED);
	else if (ft_strcmp("green", color) == 0)
		i = ft_putstr_all(GREEN);
	else if (ft_strcmp("yellow", color) == 0)
		i = ft_putstr_all(YELLOW);
	else if (ft_strcmp("blue", color) == 0)
		i = ft_putstr_all(BLUE);
	else if (ft_strcmp("magenta", color) == 0)
		i = ft_putstr_all(MAGENTA);
	else if (ft_strcmp("cyan", color) == 0)
		i = ft_putstr_all(CYAN);
	else if (ft_strcmp("white", color) == 0)
		i = ft_putstr_all(WHITE);
	else if (ft_strcmp("eoc", color) == 0)
		i = ft_putstr_all(RESET);
	return (i);
}

int	colors(char *format)
{
	char	*color;
	char	*close_bracket;

	close_bracket = ft_strchr(format++, '}');
	if (!close_bracket)
		return (0);
	color = ft_strsub(format, 0, close_bracket - format);
	if (put_color(color))
		return (ft_strlen(color) + 2);
	else
		return (0);
}
