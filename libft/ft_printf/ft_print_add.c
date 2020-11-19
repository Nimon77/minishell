/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:00:59 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/09 22:48:49 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_left_add(char *str, t_struct *data, int len)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (data->precision-- - len > 0)
	{
		ft_putchar_fd('0', 1);
		a++;
	}
	write(1, "0x", 2);
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	while (data->width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		a++;
	}
	return (a);
}

int			ft_right_add(char *str, t_struct *data, int len, char c)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (data->width-- > 0)
	{
		ft_putchar_fd(c, 1);
		a++;
	}
	while (data->precision-- - len > 0)
	{
		ft_putchar_fd('0', 1);
		a++;
	}
	write(1, "0x", 2);
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (a);
}

char		*ft_str_raccou_add(long long int nb)
{
	char	*str;

	if (nb != 0)
		str = ft_itoa_base_add(nb, "0123456789abcdef");
	else
		str = ft_strdup("0");
	return (str);
}

void		ft_raccou_add_2(t_struct *data, int *len, int nb, char *str)
{
	if (data->precision == -1 && nb == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (data->precision == -1 && nb == 0)
		*len = *len - 1;
}

int			ft_print_add(long long int nb, t_struct *data)
{
	char	*str;
	int		len;
	int		len_width;
	char	c;
	int		a;

	a = 0;
	c = ' ';
	if (data->flag == '0')
		c = '0';
	str = ft_str_raccou_add(nb);
	len = ft_strlen(str) + 2;
	ft_raccou_add_2(data, &len, nb, str);
	len_width = len;
	if (data->precision > len)
		len_width = data->precision;
	data->width = data->width - len_width;
	if (data->flag == '-')
		a = ft_left_add(str, data, len);
	else
		a = ft_right_add(str, data, len, c);
	free(str);
	return (len + a);
}
