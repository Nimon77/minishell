/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:03:30 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/04 14:35:25 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (s1 && s2)
	{
		if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (0);
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[a])
		{
			str[i + a] = s2[a];
			a++;
		}
		str[i + a] = '\0';
		return (str);
	}
	return (NULL);
}
