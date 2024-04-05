/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:32:23 by zhebert           #+#    #+#             */
/*   Updated: 2023/11/06 15:14:19 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_temp(char c)
{
	write (1, &c, 1);
}

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count ++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_num(int n)
{
	int	a;

	a = n;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_temp('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr_num (n / 10);
	ft_temp ((n % 10 + '0'));
	return (count_digits(a));
}

// int main()
// {
//     int num = -2147483647;
//     int printed = ft_putnbr_num(num);
//     write(1, "\n", 1);
//     printf("%d", printed);
// 	return (0);
// }