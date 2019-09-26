/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:46:26 by mstepina          #+#    #+#             */
/*   Updated: 2019/08/08 14:53:38 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	long_size(size_t i)
{
	int	size;

	if (i == 0)
		return (2);
	size = 1;
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa_long_long(intmax_t n)
{
	char	*str;
	int		len;
	int		sign;
	size_t	res;

	sign = 0;
	if (n < 0)
		sign = 1;
	res = (size_t)n;
	len = long_size(res);
	len += (sign) ? 1 : 0;
	if ((str = (char *)malloc(len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (--len >= sign)
	{
		str[len] = res % 10 + '0';
		res /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
