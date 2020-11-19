/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:09:21 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/07 00:34:45 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_putnbr_unsigned(unsigned int n)
{
	long			nb;
	int				i;

	i = 0;
	nb = n;
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10);
	i += ft_putchar_fd_return((nb % 10) + '0', 1);
	return (i);
}
