/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:02:36 by svillalv          #+#    #+#             */
/*   Updated: 2022/09/22 14:49:47 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_libft/libft.h"

void	send_bits(int pid, unsigned char c)
{
	unsigned char	bit;
	int				x;

	x = 8;
	while (x--)
	{
		bit = ((c >> x) & 1) + '0';
		if (bit == '1')
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	size_t	i;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		while (i <= ft_strlen(av[2]))
		{
			send_bits(pid, av[2][i]);
			i++;
		}
	}
	else
		ft_printf("Invalid number of arguments.\n");
	return (0);
}
