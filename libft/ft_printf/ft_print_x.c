/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:54:45 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/09 22:49:08 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			count_len_x(unsigned long long int nb)
{
	int		i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int			ft_left_x(unsigned long long int nb, t_struct *data, int len)
{
	int		i;
	int		a;
	int		p;

	p = data->precision;
	i = 0;
	a = 0;
	if (data->prec_s == -1 && nb == 0)
	{
		a += ft_putchar_fd_return('0', 1);
		data->width--;
	}
	while (data->precision-- - len > 0)
		a += ft_putchar_fd_return('0', 1);
	ft_printbis_x(data, &nb, &p, &a);
	while (data->width-- > 0)
		a += ft_putchar_fd_return(' ', 1);
	return (a);
}

void		ft_printbis_x(t_struct *data, unsigned long long int *nb,
int *p, int *a)
{
	int		i;
	char	*str;

	i = 0;
	if (data->type == 'x')
		str = ft_itoa_base(*nb, "0123456789abcdef");
	else
		str = ft_itoa_base(*nb, "0123456789ABCDEF");
	if (!(*p == -1 && *nb == 0))
		while (str[i])
			*a += ft_putchar_fd_return(str[i++], 1);
	free(str);
}

int			ft_right_x(unsigned long long int nb, t_struct *data, int l, char c)
{
	int		i;
	int		a;
	int		p;

	i = 0;
	a = 0;
	p = data->precision;
	if (data->prec_s == -1 && nb == 0)
	{
		data->precision = 2;
		data->width--;
	}
	if (data->flag == '0' && data->width > 0 && data->precision > 0)
		while (data->width-- > 0)
			a += ft_putchar_fd_return(c, 1);
	while (data->width-- > 0)
		a += ft_putchar_fd_return(c, 1);
	while (data->precision-- - l > 0)
		a += ft_putchar_fd_return('0', 1);
	ft_printbis_x(data, &nb, &p, &a);
	return (a);
}

int			ft_print_x(long long int nb, t_struct *data)
{
	int		len;
	int		len_width;
	char	c;
	int		a;

	a = 0;
	c = ' ';
	if (data->precision == -1 && data->width > 0 && nb == 0)
		data->width = data->width + 1;
	if (data->flag == '0' && (data->precision == 0 || data->prec_s <= -1))
		c = '0';
	len = count_len_x(nb);
	if (nb == 0)
		len = 1;
	len_width = len;
	if (data->precision > len)
		len_width = data->precision;
	data->width = data->width - len_width;
	if (data->flag == '-')
		a = ft_left_x(nb, data, len);
	else
		a = ft_right_x(nb, data, len, c);
	return (a);
}
