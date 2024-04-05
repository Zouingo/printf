/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:34:58 by zhebert           #+#    #+#             */
/*   Updated: 2023/11/09 13:57:14 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_hex(va_arg(args, unsigned long int)) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_num(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_num_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_hex(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_bighex(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *zoui, ...)
{
	va_list	args;
	size_t	len;
	int		i;

	va_start(args, zoui);
	len = 0;
	i = 0;
	if (!zoui)
		return (-1);
	while (zoui[i])
	{
		if (zoui[i] == '%')
		{
			i++;
			len += ft_format(args, zoui[i]);
		}
		else
			len += ft_putchar(zoui[i]);
		i++;
	}
	va_end(args);
	return (len);
}
