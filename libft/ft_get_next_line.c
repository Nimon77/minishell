/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rqouchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:24:24 by rqouchic          #+#    #+#             */
/*   Updated: 2020/06/01 19:59:40 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*ft_refresh_stock(char *stock, int i)
{
	char	*temp;

	if (stock[i])
	{
		temp = ft_strdup(stock + i + 1);
		free(stock);
	}
	else
	{
		free(stock);
		temp = NULL;
	}
	return (temp);
}

int		ft_free_all(int ret, char **buffer, char **stock)
{
	if (ret >= 0 && (*buffer || *stock))
	{
		if (*buffer)
			free(*buffer);
		if (ret == 0 && *stock)
			free(*stock);
	}
	if (ret == -1)
	{
		if (!*buffer)
			free(*buffer);
		if (*stock)
			free(*stock);
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock;
	char		*buffer;
	int			ret;
	int			i;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || fd > 1024 ||
		!(buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (ft_free_all(-1, &buffer, &stock));
	i = 0;
	if (!stock)
		stock = (char *)ft_calloc(sizeof(char), 1);
	while (!ft_strchr(buffer, '\n') && (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (ft_free_all(-1, &buffer, &stock));
		buffer[ret] = '\0';
		stock = ft_strjoin_s1(stock, buffer);
	}
	while (stock[i] && stock[i] != '\n')
		i++;
	*line = ft_substr(stock, 0, i);
	stock = ft_refresh_stock(stock, i);
	if (ret || stock)
		return (ft_free_all(1, &buffer, &stock));
	return (ft_free_all(0, &buffer, &stock));
}
