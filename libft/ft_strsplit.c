/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:21:26 by mstepina          #+#    #+#             */
/*   Updated: 2019/05/10 14:11:10 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	word_count;
	size_t	i;
	size_t	j;
	size_t	k;

	word_count = ft_countwords(s, c);
	if (!s || !(res = (char **)malloc(sizeof(*res) * (word_count + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < word_count)
	{
		k = 0;
		if (!(res[i] = ft_strnew(ft_wordlen(&s[j], c) + 1)))
			res[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			res[i][k++] = s[j++];
		res[i][k] = '\0';
	}
	res[i] = 0;
	return (res);
}
