/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:28:48 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/24 15:31:02 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_error(t_params params)
{
	if (params.flags.hash || params.flags.plus ||
			params.flags.space || params.size != 0)
		ft_putstr("undefined behavior\n");
}

char		*printer_space(t_params params, char *str, int len, int space_len)
{
	char *new_s;

	new_s = ft_strnew((size_t)len);
	if (params.flags.minus == 0)
	{
		ft_memset(new_s, ' ', len);
		ft_strncpy(&new_s[space_len], str, len - space_len);
	}
	else
	{
		ft_strncpy(new_s, str, len - space_len);
		ft_memset(&new_s[len - space_len], ' ', space_len);
	}
	return (new_s);
}

static int	check_len(t_params params, char *str)
{
	int len;

	len = ft_strlen(str);
	if (params.precision >= 0 && params.precision < len)
		len = params.precision;
	return (len);
}

int			s_spec(t_params params, va_list ap)
{
	char	*str;
	int		len;
	int		space_len;
	char	*new_s;

	space_len = 0;
	check_error(params);
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = check_len(params, str);
	space_len = (params.width > len) ? (params.width - len) : 0;
	if (space_len)
		len = params.width;
	new_s = ft_strnew((size_t)len);
	new_s = (space_len > 0) ? printer_space(params, str, len, space_len) :
		ft_strncpy(new_s, str, len);
	ft_putstr_all(new_s);
	len = ft_strlen(new_s);
	free(new_s);
	return (len);
}
