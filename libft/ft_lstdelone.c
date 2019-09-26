/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:13:57 by mstepina          #+#    #+#             */
/*   Updated: 2019/05/09 21:14:31 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1. Takes as a parameter a link’s pointer address and frees
** the memory of the link’s content using the function del
** given as a parameter,
** 2. then frees the link’s memory using free(3).
** 3. The memory of next must not be freed under any circumstance.
** 4. Finally, the pointer to the link that was just
** freed must be set to NULL (quite similar to the function
** ft_memdel in the mandatory part).
*/
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && del)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
