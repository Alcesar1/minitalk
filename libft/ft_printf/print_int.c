/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:24:45 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2025/11/05 16:25:23 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += print_digit (n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
	count++;
	return (count);
}

int	print_int(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr = -nbr;
	}
	count += print_digit(nbr);
	return (count);
}

int	print_x(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n / 16)
		count += print_x(n / 16, base);
	write (1, &base[n % 16], 1);
	count++;
	return (count);
}
