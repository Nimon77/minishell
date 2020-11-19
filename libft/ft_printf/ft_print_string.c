/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:44 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/09 22:49:01 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_left_string(char *str, t_struct *data, int len)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	if (data->precision > 0)
		while (str[i] && i < data->precision)
			a += ft_putchar_fd_return(str[i++], 1);
	else
		while (str[i])
			a += ft_putchar_fd_return(str[i++], 1);
	if (data->precision >= len)
		while (data->width-- + data->precision - len > 0)
			a += ft_putchar_fd_return(' ', 1);
	else if (data->precision > 0 && data->precision < len)
	{
		while (data->width-- + len - data->precision > 0)
			a += ft_putchar_fd_return(' ', 1);
	}
	else
		while (data->width-- > 0)
			a += ft_putchar_fd_return(' ', 1);
	return (a);
}

int			ft_right_string(char *str, t_struct *data, int len, char c)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (data->width > 0 && data->precision == 0)
		len = 0;
	if (data->precision >= len)
		while (data->width-- + data->precision - len > 0)
			a += ft_putchar_fd_return(c, 1);
	else if (data->precision > 0 && data->precision < len)
		while (data->width-- + len - data->precision > 0)
			a += ft_putchar_fd_return(c, 1);
	if (data->precision > 0)
		while (str[i] && i < data->precision)
			a += ft_putchar_fd_return(str[i++], 1);
	else
		while (str[i])
			a += ft_putchar_fd_return(str[i++], 1);
	return (a);
}

char		ft_raccou_string(char *str, t_struct *data)
{
	char	a;
	char	b;

	a = '0';
	b = ' ';
	if (data->prec_s <= -1)
		data->precision = ft_strlen(str);
	if (data->flag == '0')
		return (a);
	return (b);
}

int			ft_printbis_string(char *str, t_struct *data, int *len, char *c)
{
	int		a;

	a = 0;
	if (data->flag == '-')
		a = ft_left_string(str, data, *len);
	else
		a = ft_right_string(str, data, *len, *c);
	return (a);
}

int			ft_print_string(char *str, t_struct *data)
{
	int		len;
	int		len_width;
	char	c;
	int		a;

	a = 0;
	if (data->precision == -1 && data->prec_s == 0)
	{
		data->precision = 0;
		str = ft_strdup("");
		data->x = 1;
	}
	if (!str)
		str = ft_strdup("(null)");
	c = ft_raccou_string(str, data);
	len = ft_strlen(str);
	len_width = len;
	if (data->precision > len)
		len_width = data->precision;
	data->width = data->width - len_width;
	a = ft_printbis_string(str, data, &len, &c);
	if ((data->precision == -1 && data->prec_s == 0) || !str ||
	(str[0] == '(' && str[1] == 'n') || data->x == 1)
		free(str);
	return (a);
}
