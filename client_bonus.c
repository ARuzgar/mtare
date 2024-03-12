/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:18:34 by aerbosna          #+#    #+#             */
/*   Updated: 2023/04/30 10:25:05 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = j * 10;
		j += str[i] - '0';
		i++;
	}
	return (j);
}

void	finish(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message has been received. Now you can go back to your everyday life.\n");
}

void	ft_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Three Or Not Three. (Spoilers, yours is not three and i'm no Shakespeare...\n");
		return (0);
	}
	signal (SIGUSR1, finish);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	return (0);
}
