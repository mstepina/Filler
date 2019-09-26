/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:34:41 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/25 12:23:34 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	long_digitcount(unsigned long long n)
{
	int i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	f_length(long double n, t_params params)
{
	int					len;
	unsigned long long	whole;

	len = 0;
	if (n < 0)
		n = -n;
	whole = (unsigned long long)n;
	len = long_digitcount(whole);
	if (params.precision > 0 || params.flags.hash)
		len += 1;
	len += params.precision;
	return (len);
}

char		*fitoa(long double n, t_params params, int len)
{
	int		neg;
	char	*str_whole;
	char	*str;

	neg = 0;
	str_whole = n_whole_dec(n, params, len);
	str = ft_strnew(len);
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	ft_strncpy(str, str_whole, len);
	len--;
	if (str[len] == '9' && len >= 0)
		str = rounding_nine(str, len);
	if (str[0] == '0' && n > 1)
		str = ft_strjoin_free("1", str, 2);
	if (params.width && params.flags.zero && !params.flags.minus)
		str = printer_zero(params, str, len, neg);
	if (neg)
		str = ft_strjoin_free("-", str, 2);
	free(str_whole);
	return (str);
}

int			f_spec(t_params params, va_list ap)
{
	char		*str;
	char		*new_s;
	long double	n;
	int			len;

	len = 1;
	if (params.precision == -1)
		params.precision = 6;
	if (params.size == 76)
		n = va_arg(ap, long double);
	else
		n = va_arg(ap, double);
	len = f_length(n, params);
	str = fitoa(n, params, len);
	if (params.precision == 0 && ft_strlen(str) == 1 && str[0] == '0')
	{
		new_s = ft_strdup(str);
		free(str);
	}
	else
		new_s = printer_dioux(params, str);
	ft_putstr(new_s);
	len = ft_strlen(new_s);
	free(new_s);
	return (len);
}
