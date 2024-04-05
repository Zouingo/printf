/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:36:28 by zhebert           #+#    #+#             */
/*   Updated: 2023/11/09 13:06:35 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_temp(char c)
{
	write(1, &c, 1);
}

int	ft_hex(unsigned long int n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_hex(n / 16);
	ft_temp(base[n % 16]);
	count++;
	return (count);
}

// int main()
// {
//     unsigned int number = 2545;

//     ft_hex(number);
//     ft_temp('\n');
//     return (0);
// }
