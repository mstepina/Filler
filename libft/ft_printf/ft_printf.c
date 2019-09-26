/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:14:58 by mstepina          #+#    #+#             */
/*   Updated: 2019/08/07 16:34:01 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_dispatcher	*g_func_array[] = {s_spec,
	c_spec, percent_spec, p_spec, d_spec, o_spec,
	u_spec, x_spec, xx_spec, f_spec};

char	g_arr_flags[16] = {'s', 'p', 'd',
	'i', 'o', 'u', 'x', 'X', 'c', '%', 'b'};

char	*ft_strjoin_free(char *s1, char *s2, int indx)
{
	char	*new_s;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_s = ft_strnew(len)))
		return (NULL);
	ft_strcat(new_s, s1);
	ft_strcat(new_s, s2);
	if (indx == 1 || indx == 3)
		free(s1);
	if (indx == 2 || indx == 3)
		free(s2);
	return (new_s);
}

int		scpf(char **format, t_params params, va_list ap)
{
	int c;

	c = 0;
	if (**format == 's')
		c = g_func_array[0](params, ap);
	else if (**format == 'p')
		c = g_func_array[3](params, ap);
	else if (**format == 'c')
		c = g_func_array[1](params, ap);
	else if (**format == '%')
		c = g_func_array[2](params, ap);
	else if (**format == 'b')
		c = g_func_array[14](params, ap);
	else if (**format == 'f')
		c = g_func_array[9](params, ap);
	return (c);
}

int		dioux(char **format, t_params params, va_list ap)
{
	int	c;

	c = 0;
	if (**format == 'd')
		c = g_func_array[4](params, ap);
	else if (**format == 'i')
		c = g_func_array[4](params, ap);
	else if (**format == 'o')
		c = g_func_array[5](params, ap);
	else if (**format == 'u')
		c = g_func_array[6](params, ap);
	else if (**format == 'x')
		c = g_func_array[7](params, ap);
	else if (**format == 'X')
		c = g_func_array[8](params, ap);
	return (c);
}

int		flagged(char **format, va_list ap)
{
	t_params	params;
	int			c;

	c = 0;
	(*format)++;
	params = get_params(format, ap);
	if (**format == 's' || **format == 'c'
	|| **format == 'p' || **format == 'f'
	|| **format == '%')
	{
		c = scpf(format, params, ap);
		return (c);
	}
	else if (**format == 'd' || **format == 'i'
	|| **format == 'o' || **format == 'u'
	|| **format == 'x' || **format == 'X')
	{
		c = dioux(format, params, ap);
		return (c);
	}
	else
		return (0);
}

int		ft_printf(char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		format += (*format == '{') ? colors(format) : 0;
		if (*format == '%')
		{
			count += flagged(&format, ap);
			if (count != 0 || *format != '\0')
				(format++);
			else
				return (0);
		}
		else
		{
			write(1, format, 1);
			count++;
			format++;
		}
	}
	va_end(ap);
	return (count);
}
