/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:01:40 by mstepina          #+#    #+#             */
/*   Updated: 2019/05/08 23:25:48 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strdup() function allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it.  The pointer may
** subsequently be used as an argument to the function free(3).
** If insufficient memory is available, NULL is returned
*/

/*
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

*/
char    *ft_strdup(char *src)
{
	int i;
	char *dup;
	int len;

	len = ft_strlen(src);
	i = 0;
	dup = (char *)malloc(sizeof(*dup) *(len + 1));
	if (!dup)
		return (NULL);
	while(src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str;

	//str = "123";
	//str = "+hello";
	//str = "wer24";
	//str = "-this is it";
	//str = "+-346";
	str = "&df-67";
	printf("%s\n", ft_strdup(str));
	printf("%s", strdup(str));
	return(0);
}
*/

