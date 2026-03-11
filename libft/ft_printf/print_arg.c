/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:45:10 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2025/11/06 11:24:14 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	disp_type(va_list ap, char c)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += print_char(va_arg(ap, int));
	if (c == 's')
		count += print_str(va_arg (ap, char *));
	if (c == 'd' || c == 'i')
		count += print_int(va_arg(ap, int));
	if (c == 'p')
		count += print_ptr(va_arg(ap, void *));
	if (c == 'u')
		count += print_uint(va_arg(ap, unsigned int));
	if (c == 'x')
		count += print_x(va_arg(ap, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count += print_x(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (c == '%')
	{
		write (1, "%", 1);
		count++;
	}
	return (count);
}
