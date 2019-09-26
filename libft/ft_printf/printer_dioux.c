/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_dioux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 00:25:58 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/25 22:59:18 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printer_minus(t_params params, int space_len, char *str, char *new_s)
{
	if (params.flags.space && !params.flags.plus && str[0] != '-')
	{
		space_len -= 1;
		str = ft_strjoin_free(" ", str, 2);
	}
	ft_memset(new_s, ' ', space_len);
	new_s = ft_strjoin_free(str, new_s, 3);
	return (new_s);
}

char	*zero_and_precision(char *new_s, char *str, int space_len)
{
	char	*str_dup;

	ft_memset(new_s, '0', space_len);
	if (str[0] == '-')
	{
		new_s = ft_strjoin_free("-", new_s, 2);
		str_dup = ft_strdup(&str[1]);
		free(str);
		str = ft_strdup(str_dup);
		free(str_dup);
	}
	str = ft_strjoin_free(new_s, str, 3);
	return (str);
}

char	*printer_width(t_params params, char *str, int len)
{
	char	*new_s;
	int		space_len;

	new_s = ft_strnew(params.width);
	if (str[0] == '-')
		params.flags.plus = 0;
	if (params.width > params.precision && str[0] == '-'
		&& params.precision != -1 && !params.flags.zero && str[1] == '0')
		len += 1;
	space_len = params.width - len - params.flags.plus;
	if (!params.flags.minus && params.flags.zero &&
		(params.precision < 0 || params.precision < params.width))
		str = zero_and_precision(new_s, str, space_len);
	if (!(params.flags.minus || params.flags.zero))
	{
		ft_memset(new_s, ' ', space_len);
		str = ft_strjoin_free(new_s, str, 2);
	}
	if (params.flags.minus)
		str = printer_minus(params, space_len, str, new_s);
	else if (!(params.flags.zero && !params.flags.minus &&
		(params.precision < 0 || params.precision < params.width)))
		free(new_s);
	return (str);
}

char	*precision_not_zero(t_params params, int len, char *str)
{
	int		space_len;
	char	*new_s;
	char	*str_dup;

	space_len = params.precision - len;
	new_s = ft_strnew(params.precision);
	ft_memset(new_s, '0', space_len);
	if (str[0] == '-')
	{
		new_s = ft_strjoin_free("-0", new_s, 2);
		str_dup = ft_strdup(&str[1]);
		str = ft_strdup(str_dup);
	}
	str = ft_strjoin_free(new_s, str, 2);
	free(new_s);
	return (str);
}

char	*printer_dioux(t_params params, char *str)
{
	int		len;

	len = ft_strlen(str);
	if ((params.precision > len || (str[0] == '-' && params.precision >= len))
		&& !params.flags.zero)
	{
		str = precision_not_zero(params, len, str);
		len = params.precision;
	}
	if (params.flags.plus && !(str[0] == '-') && !params.flags.zero)
		str = ft_strjoin_free("+", str, 2);
	if (params.width > len)
		str = printer_width(params, str, len);
	if (params.flags.space && !params.flags.plus &&
	str[0] != '-' && params.width <= len)
		str = ft_strjoin_free(" ", str, 2);
	if (params.flags.plus && !(str[0] == '-') && params.flags.zero)
		str = ft_strjoin_free("+", str, 2);
	if (params.precision == 0 && ft_strlen(str) == 1 && str[0] == '0')
		str[0] = '\0';
	return (str);
}
