/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:59:26 by rqouchic          #+#    #+#             */
/*   Updated: 2019/11/17 19:58:59 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		(*((unsigned char *)dst)) = ((unsigned char *)src)[i];
		dst++;
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (dst);
		i++;
	}
	return (NULL);
}
