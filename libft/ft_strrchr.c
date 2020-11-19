/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:35:38 by rqouchic          #+#    #+#             */
/*   Updated: 2019/11/17 20:03:28 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(const char *s, int c)
{
	int i;

	i = 1;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strrchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c && !check(s, c))
			return ((char *)s);
		s++;
	}
	if (!c && !*s)
		return ((char *)s);
	return (NULL);
}
