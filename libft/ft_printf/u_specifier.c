/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:17:36 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/24 15:38:59 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dec_convert_un(unsigned long long n)
{
	char	*str;
	char	*dec;
	int		i;

	i = 0;
	str = ft_strnew(25);
	dec = "0123456789";
	if (n == 0)
	{
		str[0] = '0';
		i++;
	}
	while (n > 0)
	{
		str[i] = dec[n % 10];
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	str = ft_revstr(str);
	return (str);
}

char	*u_str_length(va_list ap, int size)
{
	char				*str;
	unsigned long long	un;

	un = 0;
	if (size == 216)
	{
		un = va_arg(ap, unsigned long long);
		str = dec_convert_un(un);
	}
	else if (size == 108)
	{
		un = va_arg(ap, unsigned long);
		str = dec_convert_un((unsigned long long)(un));
	}
	else
	{
		un = va_arg(ap, unsigned int);
		if (size == 104)
			str = dec_convert_un((unsigned short)un);
		else if (size == 208)
			str = dec_convert_un((unsigned char)un);
		else
			str = dec_convert_un((unsigned long long)(un));
	}
	return (str);
}

int		u_spec(t_params params, va_list ap)
{
	char	*str;
	char	*new_s;

	str = u_str_length(ap, params.size);
	if (params.precision > 0)
		params.flags.zero = 0;
	params.flags.space = 0;
	params.flags.plus = 0;
	if (params.precision == 0 && str[0] == '0')
	{
		free(str);
		str = ft_strnew(2);
		if (!params.width)
			str[0] = '\0';
		else
		{
			str[0] = ' ';
			str[1] = '\0';
		}
	}
	new_s = printer_dioux(params, str);
	ft_putstr(new_s);
	free(new_s);
	return (ft_strlen(new_s));
}
