/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:37:48 by mstepina          #+#    #+#             */
/*   Updated: 2019/05/09 19:55:01 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strnstr() function locates the first occurrence of the null-terminated
** string needle in the string haystack, where not more than len characters
** are searched.  Characters that appear after a `\0' character are not
** searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if ((!len || !haystack) && !*needle)
		return ((char*)haystack);
	while (*haystack && len-- > 0)
	{
		i = 0;
		while (needle[i] && haystack[i] == needle[i] && i <= len)
			i++;
		if (!needle[i])
			return ((char*)haystack);
		haystack++;
	}
	return (0);
}
