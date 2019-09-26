/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:10:09 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/24 19:43:15 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*hex_convert(unsigned long p, t_params params)
{
	char	*str;
	char	*hex;
	int		i;

	i = 0;
	if (p == 0)
	{
		str = ft_strnew(2);
		str[0] = (params.precision == 0) ? '\0' : '0';
	}
	else
		str = ft_strnew(12);
	hex = "0123456789abcdef";
	while (p > 0)
	{
		str[i] = hex[p % 16];
		p = p / 16;
		i++;
	}
	str = ft_revstr(str);
	str = ft_strjoin_free("0x", str, 2);
	return (str);
}

int			p_spec(t_params params, va_list ap)
{
	char			*str;
	char			*new_s;
	unsigned long	p;
	int				len;
	int				space_len;

	space_len = (params.width > 14) ? (params.width - 14) : 0;
	len = (params.width > 14) ? params.width : 14;
	p = va_arg(ap, unsigned long);
	new_s = ft_strnew((size_t)len);
	str = hex_convert(p, params);
	len = ft_strlen(str);
	if (params.width > len)
		ft_memset(new_s, ' ', params.width - len);
	str = (params.flags.minus) ? (ft_strjoin_free(str, new_s, 1)) :
		(ft_strjoin_free(new_s, str, 2));
	ft_putstr(str);
	free(str);
	free(new_s);
	return (len);
}
