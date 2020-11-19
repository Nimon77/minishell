/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_return.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:12:32 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/07 00:35:02 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_putchar_fd_return(char c, int fd)
{
	int i;

	i = 0;
	write(fd, &c, 1);
	i++;
	return (i);
}
