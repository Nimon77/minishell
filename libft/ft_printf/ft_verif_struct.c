/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:24:15 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/09 23:00:25 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_verif_type(const char *str, t_struct *data, int **i)
{
	if (str[**i] && (str[**i] == 'c' || str[**i] == 's' || str[**i] == 'p' ||
		str[**i] == 'd' || str[**i] == 'i' ||
		str[**i] == 'u' || str[**i] == 'x' || str[**i] == 'X' ||
		str[**i] == '%'))
	{
		data->type = str[**i];
		**i = **i + 1;
	}
	else
		data->type = 'z';
}

void	ft_verif_precision(const char *str, t_struct *data, int **i,
va_list arg)
{
	if (str[**i] && str[**i] == '.')
	{
		**i += 1;
		if (str[**i] == '*')
		{
			data->bool = 1;
			data->precision = va_arg(arg, int);
			data->prec_s = data->precision;
			if (data->precision == 0)
				data->precision = -1;
		}
		else
		{
			data->precision = ft_atoi(&str[**i]) != 0 ? ft_atoi(&str[**i]) : -1;
		}
		while (str[**i] && ((str[**i] >= '0' && str[**i] <= '9') ||
			str[**i] == '*'))
			**i += 1;
	}
}

void	ft_verif_width(const char *str, t_struct *data, int **i, va_list arg)
{
	if (str[**i] >= '0' && str[**i] <= '9')
		data->width = ft_atoi(&str[**i]);
	if (str[**i] == '*')
	{
		data->width = va_arg(arg, int);
		if (data->width < 0)
		{
			data->width = -data->width;
			data->flag = '-';
		}
	}
	while (str[**i] && ((str[**i] >= '0' && str[**i] <= '9') ||
	str[**i] == '*'))
		**i += 1;
}

void	ft_verif_flags(const char *str, t_struct *data, int **i)
{
	if (str[**i] == '-')
	{
		data->flag = '-';
		while (str[**i] && (str[**i] == '-' || str[**i] == '0'))
			**i += 1;
		return ;
	}
	if (str[**i] == '0')
	{
		data->flag = '0';
		while (str[**i] && (str[**i] == '0' || str[**i] == '-'))
		{
			if (str[**i] == '-')
				data->flag = '-';
			**i += 1;
		}
		return ;
	}
}

void	ft_initial_data(t_struct *data)
{
	data->flag = 0;
	data->width = 0;
	data->precision = 0;
	data->type = 0;
	data->bool = 0;
	data->prec_s = 0;
	data->x = 0;
}
