/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:43:56 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/25 16:14:20 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*oct_convert(long long n)
{
	char	*str;
	char	*oct;
	int		i;

	i = 0;
	str = ft_strnew(25);
	oct = "01234567";
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		str[i] = oct[n % 8];
		n = n / 8;
		i++;
	}
	str = ft_revstr(str);
	return (str);
}

char	*oct_convert_un(unsigned long long n)
{
	char	*str;
	char	*oct;
	int		i;

	i = 0;
	str = ft_strnew(25);
	oct = "01234567";
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i] = oct[n % 8];
		n = n / 8;
		i++;
	}
	str = ft_revstr(str);
	return (str);
}

char	*o_str_length(va_list ap, int size)
{
	char				*str;
	unsigned long long	un;

	un = 1;
	if (size == 216)
	{
		un = va_arg(ap, unsigned long long);
		str = oct_convert_un(un);
	}
	else if (size == 108)
	{
		un = va_arg(ap, unsigned long);
		str = oct_convert_un((unsigned long long)(un));
	}
	else
	{
		un = va_arg(ap, unsigned int);
		if (size == 104)
			str = oct_convert_un((unsigned short)un);
		else if (size == 208)
			str = oct_convert_un((unsigned char)un);
		else
			str = oct_convert_un((unsigned long long)(un));
	}
	return (str);
}

char	*precision_hash(char *str)
{
	free(str);
	str = ft_strnew(2);
	str[0] = '\0';
	return (str);
}

int		o_spec(t_params params, va_list ap)
{
	char	*str;
	char	*new_s;
	int		len;

	if (params.precision > 0)
		params.flags.zero = 0;
	str = o_str_length(ap, params.size);
	if (params.precision == 0 && !params.flags.hash && str[0] == '0')
		str = precision_hash(str);
	if (params.flags.hash && str[0] != '0')
		str = ft_strjoin_free("0", str, 2);
	if (params.flags.hash && params.precision == 0)
		new_s = str;
	else
		new_s = printer_dioux(params, str);
	ft_putstr(new_s);
	len = ft_strlen(new_s);
	free(new_s);
	return (len);
}
