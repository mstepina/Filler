/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:03:37 by mstepina          #+#    #+#             */
/*   Updated: 2019/05/09 16:13:55 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int sign;
	int res;

	sign = 1;
	res = 0;
	while(*str && ((*str > 8 && *str < 14) || *str == 32))
	        str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;	
	}
	while(*str >= '0' && *str <='9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

/*		
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const char *str;
	
	//str = "123";
	//str = "+123;gh";
	//str = "wer24";
	//str = "-12345";
	//str = "+-346";
	str = "&df-67";
	printf("%d\n", ft_atoi(str));
	printf("%d", atoi(str));
	return(0);
}
*/
