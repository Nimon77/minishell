/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:02:47 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/09 22:48:57 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			count_len(int nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int			ft_left(int nb, t_struct *data, int len)
{
	int		a;
	int		p;

	a = 0;
	p = data->precision;
	if (data->precision >= len && nb < 0)
		data->width = data->width - 1;
	if (nb < 0 && data->precision >= len)
	{
		ft_putchar_fd('-', 1);
		a += ft_putchar_fd_return('0', 1);
	}
	if ((p >= len && nb < 0) || (nb < 0 && data->width > 0
	&& p == 0 && data->flag == '0'))
		nb = -nb;
	while (data->precision-- - len > 0)
		a += ft_putchar_fd_return('0', 1);
	if (!(p == -1 && nb == 0))
		ft_putnbr_fd(nb, 1, 0);
	while (data->width-- > 0)
		a += ft_putchar_fd_return(' ', 1);
	while (data->width-- > 0)
		a += ft_putchar_fd_return(' ', 1);
	return (a);
}

int			ft_right(int nb, t_struct *data, int len, char c)
{
	int		a;
	int		p;
	int		w;

	p = data->precision;
	w = data->width + len;
	a = 0;
	if (data->precision >= len && nb < 0)
		data->width = data->width - 1;
	while (data->width-- > 0)
		a += ft_putchar_fd_return(c, 1);
	if ((p >= len && nb < 0))
	{
		ft_putchar_fd('-', 1);
		a += ft_putchar_fd_return('0', 1);
	}
	while (data->precision-- - len > 0)
		a += ft_putchar_fd_return('0', 1);
	if ((p >= len && nb < 0) || (nb < 0 && w > 0
	&& p == 0 && data->flag == '0')
	|| (nb < 0 && data->prec_s <= -1 && data->flag == '0'))
		nb = -nb;
	if (!(p == -1 && nb == 0))
		ft_putnbr_fd(nb, 1, 0);
	return (a);
}

void		ft_raccou_nb(t_struct *data, int nb, int *len)
{
	if (data->precision == -1 && nb == 0)
	{
		if (data->width > 0)
			data->width = data->width + 1;
		*len = 0;
	}
	if (data->prec_s == -1 && nb == 0)
	{
		data->precision = 0;
		data->width--;
		*len = *len + 1;
	}
	if (data->prec_s <= -1 && nb < 0 && data->flag == '0')
	{
		ft_putchar_fd('-', 1);
	}
}

int			ft_print_nb(int nb, t_struct *data)
{
	int		a;
	int		len;
	int		len_width;
	char	c;

	a = 0;
	c = ' ';
	if (data->flag == '0' && (data->precision == 0 || data->prec_s <= -1))
		c = '0';
	len = count_len(nb);
	len_width = len;
	if ((data->precision == -1 && nb == 0) || (data->prec_s <= -1 && nb < 0))
		ft_raccou_nb(data, nb, &len);
	if (nb < 0 && data->flag == '0' && data->width > 0
	&& data->precision == 0)
		ft_putchar_fd('-', 1);
	if (data->precision > len)
		len_width = data->precision;
	data->width = data->width - len_width;
	if (data->flag == '-')
		a = ft_left(nb, data, len);
	else
		a = ft_right(nb, data, len, c);
	return (len + a);
}
