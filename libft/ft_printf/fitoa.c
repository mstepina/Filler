/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:04:57 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/24 14:20:03 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*rounding_nine(char *str, int len)
{
	while ((str[len] == '9' || str[len] == '.') && len >= 0)
	{
		if (str[len] != '.')
			str[len] = '0';
		len--;
	}
	str[len] += 1;
	return (str);
}

char	*make_whole(long long whole)
{
	char	*dec;
	char	*str_whole;
	int		i;

	i = 0;
	dec = "0123456789";
	str_whole = ft_strnew(20);
	if (whole == 0)
		str_whole[0] = '0';
	else if (whole < 0)
		whole *= -1;
	while (whole > 0)
	{
		str_whole[i] = dec[whole % 10];
		whole = whole / 10;
		i++;
	}
	str_whole = ft_revstr(str_whole);
	return (str_whole);
}

char	*make_dec(t_params params, long double n)
{
	char	*str_dec;
	char	*dec;
	int		i;

	i = 0;
	dec = "0123456789";
	str_dec = ft_strnew(params.precision + 1);
	while (params.precision >= 0)
	{
		n *= 10;
		str_dec[i] = dec[(int)n];
		n = n - (int)n;
		i++;
		params.precision--;
	}
	return (str_dec);
}

char	*printer_zero(t_params params, char *str, int len, int neg)
{
	char	*new_s;
	int		space_len;

	space_len = 0;
	space_len = params.width - (++len) - neg;
	new_s = ft_strnew(params.width);
	ft_memset(new_s, '0', space_len);
	str = ft_strjoin_free(new_s, str, 2);
	free(new_s);
	return (str);
}

char	*n_whole_dec(long double n, t_params params, int len)
{
	int			neg;
	long long	whole;
	char		*str_whole;
	char		*str_dec;

	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	whole = (unsigned long long)n;
	if (n - whole >= 0.5 && params.precision == 0)
		whole += 1;
	n = n - whole;
	str_whole = make_whole(whole);
	if (params.precision > 0 || params.flags.hash)
		str_whole = ft_strjoin_free(str_whole, ".", 1);
	str_dec = make_dec(params, n);
	str_whole = ft_strjoin_free(str_whole, str_dec, 1);
	if (str_whole[len] >= '5' && str_whole[len] <= '9' &&
			str_whole[len - 1] != '9')
		str_whole[len - 1] += 1;
	free(str_dec);
	return (str_whole);
}
