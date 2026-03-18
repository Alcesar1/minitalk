/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:07:29 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2026/03/18 10:10:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "signal.h"
#include "libft.h"

int	main(int ac, char **av)
{
	int				pid;
	char			*msg;
	unsigned char 	c;
	int				bit;
	int				i;

	i = 0;
	pid = ft_atoi(av[1]);
	msg = av[2];
	if (ac != 3)
	{
		ft_printf("Attention le sang, en arg, PID et String only");
		return (0);
	}
	while (msg[i] != '\0')
	{
		c = msg[i];
		bit = 7;
		while (bit >= 0)
		{
			if((c >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			bit--;
		}
		i++;
	}
	c = '\0';
	bit = 7;
	while (bit >= 0)
	{
		if((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bit--;
	}
	return (0);
}
