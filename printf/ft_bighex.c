/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bighex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhebert <zhebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:34 by zhebert           #+#    #+#             */
/*   Updated: 2023/11/09 13:06:40 by zhebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_temp(char c)
{
	write(1, &c, 1);
}

int	ft_bighex(unsigned int n)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_bighex(n / 16);
	ft_temp(base[n % 16]);
	count++; 
	return (count);
}

// int main()
// {
//     unsigned int number = 2545;

//     ft_bighex(number);
//     ft_temp('\n');
//     return (0);
// }