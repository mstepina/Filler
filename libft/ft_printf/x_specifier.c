/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:39:30 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/25 15:49:15 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*hex_convert_un(unsigned long long p)
{
	char	*str;
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	if (p == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		i++;
	}
	else
		str = ft_strnew(25);
	while (p > 0)
	{
		str[i] = hex[p % 16];
		p = p / 16;
		i++;
	}
	str[i] = '\0';
	str = ft_revstr(str);
	return (str);
}

char			*x_str_length(va_list ap, int size)
{
	char				*str;
	unsigned long long	un;

	un = 1;
	if (size == 216)
	{
		un = va_arg(ap, unsigned long long);
		str = hex_convert_un(un);
	}
	else if (size == 108)
	{
		un = va_arg(ap, unsigned long);
		str = hex_convert_un((unsigned long long)(un));
	}
	else
	{
		un = va_arg(ap, unsigned int);
		if (size == 104)
			str = hex_convert_un((unsigned short)un);
		else if (size == 208)
			str = hex_convert_un((unsigned char)un);
		else
			str = hex_convert_un((unsigned long long)(un));
	}
	return (str);
}

static char		*precision_for_zero(char *str)
{
	free(str);
	str = ft_strnew(2);
	str[0] = ' ';
	str[1] = '\0';
	return (str);
}

int				x_spec(t_params params, va_list ap)
{
	char	*str;
	char	*new_s;

	str = x_str_length(ap, params.size);
	if (params.precision > 0)
		params.flags.zero = 0;
	if (params.precision != 0 || params.width || str[0] != '0'
		|| params.flags.plus)
	{
		if (params.precision == 0 && str[0] == '0')
			str = precision_for_zero(str);
		if (params.flags.hash && str[0] != '0' && !params.flags.zero &&
		(params.precision <= (int)ft_strlen(str)))
			str = ft_strjoin_free("0x", str, 2);
		new_s = printer_dioux(params, str);
		if (params.flags.hash && str[0] != '0' && !params.flags.zero &&
		(params.precision > (int)ft_strlen(str)))
			new_s = ft_strjoin_free("0x", new_s, 2);
		if (params.flags.hash && new_s[0] != '\0' && params.flags.zero)
			new_s[1] = 'x';
		ft_putstr(new_s);
		free(new_s);
		return (ft_strlen(new_s));
	}
	return (0);
}
