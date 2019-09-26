/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:41:04 by mstepina          #+#    #+#             */
/*   Updated: 2019/05/09 15:45:48 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strwospace(char const *s)
{
	size_t len;
	size_t sp_len;

	if (!*s)
		return (0);
	len = 0;
	while (*s)
	{
		len++;
		sp_len = (ft_isspace(*s) ? (sp_len + 1) : 0);
		s++;
	}
	return (len - (ft_isspace(*(s - 1)) ? sp_len : 0));
}

char			*ft_strtrim(char const *s)
{
	if (!s)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	return (ft_strsub(s, 0, ft_strwospace(s)));
}
