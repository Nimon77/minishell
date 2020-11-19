/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:36:48 by rqouchic          #+#    #+#             */
/*   Updated: 2019/11/07 16:03:55 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nombre, size_t size)
{
	void *str;

	if (!(str = malloc(size * nombre)))
		return (0);
	ft_bzero(str, nombre * size);
	return (str);
}
