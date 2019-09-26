/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 04:06:28 by mstepina          #+#    #+#             */
/*   Updated: 2019/08/07 22:12:32 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*d_str_length(va_list ap, int size)
{
	char		*str;
	long long	n;

	n = 0;
	if (size == 108 || size == 216)
	{
		n = va_arg(ap, long long);
		if (n < LLONG_MIN || n > LLONG_MAX)
			str = ft_itoa_long_long((intmax_t)n);
		else
			str = long_itoa((long long)(n));
	}
	else
	{
		n = va_arg(ap, int);
		if (size == 104 && (n > SHRT_MAX || n < SHRT_MIN))
			str = ft_itoa((short)n);
		else if (size == 208 && (n > SCHAR_MAX || n < SCHAR_MIN))
			str = ft_itoa((char)n);
		else
			str = ft_itoa(n);
	}
	return (str);
}

char			*difference(t_params params, char *str)
{
	int		difference;
	int		i;

	i = 0;
	difference = params.width - params.precision;
	while (difference > 0)
	{
		str[i] = ' ';
		i++;
		difference--;
	}
	return (str);
}

static char		*precision_for_zero(char *str, t_params params)
{
	free(str);
	str = ft_strnew(2);
	if (params.flags.plus)
		str[0] = '\0';
	else
		str[0] = ' ';
	str[1] = '\0';
	return (str);
}

int				d_spec(t_params params, va_list ap)
{
	char	*str;
	char	*new_s;

	str = d_str_length(ap, params.size);
	if (str[0] == '-')
		params.flags.space = 0;
	if (params.precision > 0)
		params.flags.zero = 0;
	if (params.precision != 0 || params.width ||
	str[0] != '0' || params.flags.plus)
	{
		if (params.precision == 0 && str[0] == '0')
			str = precision_for_zero(str, params);
		new_s = printer_dioux(params, str);
		if (params.flags.zero && params.width > params.precision
			&& params.precision > 0 && new_s[0] != '-')
			new_s = difference(params, new_s);
		else if (params.flags.space && !params.flags.plus)
			new_s[0] = ' ';
		ft_putstr(new_s);
		free(new_s);
		return (ft_strlen(new_s));
	}
	return (0);
}
