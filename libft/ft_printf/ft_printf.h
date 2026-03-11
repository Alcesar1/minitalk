/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:06:56 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2025/11/05 16:26:54 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_char(int n);
int		print_str(char *s);
int		print_int(int n);
int		disp_type(va_list ap, char c);
int		print_digit(long n);
int		print_hex(unsigned long long n, char *base);
int		print_ptr(void *ptr);
int		print_x(unsigned int n, char *base);
int		print_uint(unsigned int n);

#endif