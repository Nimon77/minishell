/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:07:47 by rqouchic          #+#    #+#             */
/*   Updated: 2019/11/15 17:28:06 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp1;
	t_list *temp2;

	if (lst && *lst)
	{
		temp1 = *lst;
		while (temp1)
		{
			temp2 = temp1->next;
			del(temp1->content);
			free(temp1);
			temp1 = temp2;
		}
		*lst = (NULL);
	}
}
