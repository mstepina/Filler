/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:17:48 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/24 15:01:01 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		flags_handler(char **format)
{
	t_flags flags;

	flags.hash = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.space = 0;
	flags.zero = 0;
	while (**format)
	{
		if (**format == '#')
			flags.hash = 1;
		else if (**format == '+')
			flags.plus = 1;
		else if (**format == '-')
			flags.minus = 1;
		else if (**format == ' ')
			flags.space = 1;
		else if (**format == '0')
			flags.zero = 1;
		else
			break ;
		(*format)++;
	}
	return (flags);
}

int			width_handler(char **format, va_list ap)
{
	int	width;

	width = 0;
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		width = va_arg(ap, int);
		(*format)++;
	}
	return (width);
}

int			precision_handler(char **format, va_list ap)
{
	int	precision;

	precision = -1;
	if (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			precision = va_arg(ap, int);
			(*format)++;
		}
		else
			precision = 0;
	}
	return (precision);
}

int			size_handler(char **format)
{
	int	size;

	size = 0;
	if (**format == 'h' && *(*format + 1) != 'h')
		size = 104;
	else if (**format == 'h' && *(*format + 1) == 'h')
		size = 208;
	else if (**format == 'l' && *(*format + 1) != 'l')
		size = 108;
	else if (**format == 'l' && *(*format + 1) == 'l')
		size = 216;
	else if (**format == 'L')
		size = 76;
	if (size > 0 && size < 200)
		(*format) += 1;
	else if (size > 200)
		(*format) += 2;
	return (size);
}

t_params	get_params(char **format, va_list ap)
{
	t_params params;

	params.flags = flags_handler(format);
	params.width = width_handler(format, ap);
	params.precision = precision_handler(format, ap);
	params.size = size_handler(format);
	if (params.flags.minus && params.flags.zero)
		params.flags.zero = 0;
	if (params.width < 0)
	{
		params.flags.minus = 1;
		params.width *= -1;
	}
	return (params);
}
