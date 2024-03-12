/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:16:43 by aerbosna          #+#    #+#             */
/*   Updated: 2023/04/30 09:26:41 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr(int sig, siginfo_t *info, void *context)
{
	static char		str = 0;
	static pid_t	client_id = 0;
	static int		get_byte = 0;

	(void)context;
	if (client_id == 0)
		client_id = info->si_pid;
	if (sig == SIGUSR1)
		str = str | 1;
	if (++get_byte == 8)
	{
		get_byte = 0;
		if (!str)
		{
			kill(client_id, SIGUSR1);
			client_id = 0;
			ft_printf("\n");
		}
		ft_printf("%c", str);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	struct sigaction	client;

	client.sa_sigaction = sig_usr;
	client.sa_flags = SA_SIGINFO;
	ft_printf("Proc. ID : %d\n", getpid());
	sigaction(SIGUSR1, &client, 0);
	sigaction(SIGUSR2, &client, 0);
	while (1)
	{
		pause();
	}
	return (0);
}
