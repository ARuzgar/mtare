/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:07:16 by aerbosna          #+#    #+#             */
/*   Updated: 2023/04/30 09:26:54 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr(int sig)
{
	static unsigned char	str = 0;	
	static int				get_byte = 0;

	if (sig == SIGUSR1)
		str = str | 1;
	if (++get_byte == 7)
	{
		get_byte = 0;
		ft_printf("%c", str);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	ft_printf("pid = %d\n", getpid());
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	while (1)
	{
		pause();
	}
	return (0);
}
