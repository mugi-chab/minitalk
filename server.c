/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:57:05 by svillalv          #+#    #+#             */
/*   Updated: 2022/09/22 17:20:18 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print_libft/libft.h"

void	handle_signal(int signal)
{
	static int				x = 7;
	static unsigned char	c = 0;

	if (signal == SIGUSR2)
		c |= (1 << x);
	x--;
	if (x < 0)
	{
		if (c == '\0')
		{
			x = 7;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", c);
		x = 7;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf(ANSI_COLOR_BLUE BLANCO_F "Server PID: %d" ANSI_COLOR_RESET "\n", pid);
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		while (1)
			pause();
	}
}
