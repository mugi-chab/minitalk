/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:02:41 by svillalv          #+#    #+#             */
/*   Updated: 2022/09/22 18:34:06 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_libft/libft.h"

void	send_bits(int pid, unsigned char octet)
{
	unsigned char	bit;
	int				x;

	x = 8;
	while (x--)
	{
		bit = ((octet >> x) & 1) + '0';
		if (bit == '1')
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf(COLOR_YELLOW NEGRO_T"(ﾉ◕ヮ◕)ﾉ･ﾟ✧ ñam delicious"COLOR_RESET"\n");
		exit (0);
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
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		while (i <= ft_strlen(av[2]))
		{
			send_bits(pid, av[2][i]);
			i++;
		}
		while (1)
			pause();
	}
	else
		ft_printf("Invalid number of arguments.\n");
	return (0);
}
