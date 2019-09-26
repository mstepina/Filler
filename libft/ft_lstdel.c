/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:15:13 by mstepina          #+#    #+#             */
/*   Updated: 2019/05/09 21:15:26 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1. Takes as a parameter the adress of a pointer to a link and frees
** the memory of this link and every successors of that link using the
** functions del and free(3).
** 2. Finally the pointer to the link that was just freed must be set
**  to NULL (quite similar to the function ft_memdel from the mandatory part).
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next;

	list = *alst;
	while (list && del)
	{
		next = list->next;
		ft_lstdelone(&list, del);
		list = next;
	}
	*alst = NULL;
}
