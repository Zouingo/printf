/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_num_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:14 by zhebert           #+#    #+#             */
/*   Updated: 2023/11/06 12:30:01 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_temp(char c)
{
	write (1, &c, 1);
}

static int	count_digits(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_num_unsigned(unsigned int n)
{
	unsigned int	a;

	a = n;
	if (n == 4294967295)
	{
		write (1, "4294967295", 10);
		return (10);
	}
	if (n > 9)
		ft_putnbr_num_unsigned (n / 10);
	ft_temp ((n % 10 + '0'));
	return (count_digits(a));
}

// int main()
// {
//     unsigned int num = 10;
//     unsigned int printed = ft_putnbr_num_unsigned(num);
//     write(1, "\n", 1);
//     printf("%d", printed);
// 	return (0);
// }