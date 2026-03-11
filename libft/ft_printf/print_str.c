/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:37:35 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2025/11/06 10:24:18 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_char(int c)
{
	int	count;

	count = 0;
	write (1, &c, 1);
	count++;
	return (count);
}

int	print_ptr(void *ptr)
{
	unsigned long long	addr;
	char				*base;
	int					count;

	base = "0123456789abcdef";
	count = 0;
	addr = (unsigned long long)ptr;
	if (!ptr)
		return (write (1, "(nil)", 5));
	write(1, "0x", 2);
	count += 2;
	count += print_hex(addr, base);
	return (count);
}

int	print_hex(unsigned long long addr, char *base)
{
	int	count;

	count = 0;
	if (addr >= 16)
		count += print_hex(addr / 16, base);
	write (1, &base[addr % 16], 1);
	count++;
	return (count);
}

int	print_uint(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += print_uint(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
	count++;
	return (count);
}
