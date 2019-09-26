/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:05:50 by mstepina          #+#    #+#             */
/*   Updated: 2019/05/09 19:24:26 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” string end- ing with ’\0’.
** Each character of the string is initialized at ’\0’.
** If the allocation fails the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char *ret;

	if (!(ret = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ret[size] = 0;
	while (size-- > 0)
		ret[size] = 0;
	return (ret);
}
