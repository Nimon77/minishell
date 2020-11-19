/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:09:21 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/30 21:56:18 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd, int i)
{
	long nb;

	nb = n;
	if (nb < 0)
	{
		if (i == 1)
			ft_putchar_fd('0', fd);
		else
			ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd, 0);
	ft_putchar_fd((nb % 10) + '0', fd);
}
