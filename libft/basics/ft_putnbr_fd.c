/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:13:08 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2025/10/27 14:35:17 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			memory[10];
	int			i;
	long int	nbl;

	nbl = n;
	i = 0;
	if (nbl < 0)
	{
		write(fd, "-", 1);
		nbl *= (-1);
	}
	while ((nbl / 10) != 0)
	{
		memory[i] = (nbl % 10) + 48;
		nbl /= 10;
		i++;
	}
	memory[i] = (nbl % 10) + 48;
	while (i >= 0)
	{
		write (fd, &memory[i], 1);
		i--;
	}
}
