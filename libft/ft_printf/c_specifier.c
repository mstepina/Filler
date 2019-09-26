/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:19:09 by mstepina          #+#    #+#             */
/*   Updated: 2019/07/31 13:51:15 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr_all(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int			c_spec(t_params params, va_list ap)
{
	char	c;
	char	*new_s;
	int		len;

	len = 1;
	c = (char)(va_arg(ap, int));
	if (params.width)
		len = params.width;
	new_s = ft_strnew((size_t)len);
	if (params.width && !params.flags.minus)
	{
		ft_memset(new_s, ' ', params.width - 1);
		ft_putstr_all(new_s);
	}
	write(1, &c, 1);
	if (params.width && params.flags.minus)
	{
		ft_memset(new_s, ' ', params.width - 1);
		ft_putstr_all(new_s);
	}
	free(new_s);
	return (len);
}

int			percent_spec(t_params params, va_list ap)
{
	char	*new_s;
	int		len;
	char	c;

	(void)ap;
	len = 1;
	len = (params.width) ? params.width : len;
	new_s = ft_strnew((size_t)len);
	c = (params.flags.zero) ? '0' : ' ';
	if (params.width && !params.flags.minus)
	{
		ft_memset(new_s, c, params.width - 1);
		ft_putstr_all(new_s);
	}
	ft_putchar('%');
	if (params.width && params.flags.minus)
	{
		ft_memset(new_s, c, params.width - 1);
		ft_putstr_all(new_s);
	}
	free(new_s);
	return (len);
}
