/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:37:32 by rqouchic          #+#    #+#             */
/*   Updated: 2019/11/17 20:07:02 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;

	count = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (*haystack && count <= len)
	{
		i = 0;
		while (needle[i] && haystack[i] && haystack[i] == needle[i])
			i++;
		if (!needle[i] && i + count <= len)
			return ((char *)haystack);
		haystack++;
		count++;
	}
	return (NULL);
}
