/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:29:21 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/09 22:48:53 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_left_char(char a, t_struct *data, int len)
{
	int		b;

	b = 0;
	if ((data->width > 0 && a == '%') || (data->precision > 0 && a == '%'))
	{
		ft_putchar_fd('%', 1);
		while (data->precision-- - len > 0)
		{
			ft_putchar_fd(' ', 1);
			b++;
		}
	}
	while (data->precision-- - len > 0)
	{
		ft_putchar_fd('0', 1);
		b++;
	}
	if (a != '%')
		ft_putchar_fd(a, 1);
	while (data->width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		b++;
	}
	return (b);
}

int			ft_right_char(char a, t_struct *data, int len, char c)
{
	int		b;

	b = 0;
	while (data->width-- > 0)
	{
		ft_putchar_fd(c, 1);
		b++;
	}
	if (data->precision > 0 && a == '%')
	{
		ft_putchar_fd('%', 1);
		return (b);
	}
	while (data->precision-- - len > 0)
	{
		ft_putchar_fd('0', 1);
		b++;
	}
	ft_putchar_fd(a, 1);
	return (b);
}

int			ft_print_char(char a, t_struct *data)
{
	int		len;
	int		len_width;
	char	c;
	int		b;

	b = 0;
	c = ' ';
	if (data->flag == '0' && data->type == '%' && data->precision > 0)
		data->width = data->width + 1;
	if (data->flag == '0')
		c = '0';
	len = 1;
	len_width = len;
	if (data->precision > len)
		len_width = data->precision;
	data->width = data->width - len_width;
	if (data->flag == '-')
		b = ft_left_char(a, data, len);
	else
		b = ft_right_char(a, data, len, c);
	return (len + b);
}
