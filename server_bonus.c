/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:03:13 by svillalv          #+#    #+#             */
/*   Updated: 2022/09/22 15:10:02 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print_libft/libft.h"

void	get_signal(int sig, siginfo_t *info, void *context)
{
	static int				x = 7;
	static unsigned char	c = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		c |= (1 << x);
	x--;
	if (x < 0)
	{
		if (c == '\0')
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
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
	struct sigaction	sa;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf(ANSI_COLOR_BLUE "Server PID: %d\n" ANSI_COLOR_RESET, pid);
		sa.sa_sigaction = get_signal;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	return (0);
}
