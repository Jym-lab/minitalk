/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:55 by yjoo              #+#    #+#             */
/*   Updated: 2022/06/09 13:14:55 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minitalk_bonus.h"

void	error(void)
{
	ft_putstr_fd("\n[client : signal transmission error\n", 1);
	exit(EXIT_FAILURE);
}

void	send_bin_msg(int server_pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 128)
		{
			if (kill(server_pid, SIGUSR2) == -1)
				error();
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
				error();
		}
		c <<= 1;
		i++;
		pause();
		usleep(50);
	}
}

void	send(int server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_bin_msg(server_pid, str[i++]);
	send_bin_msg (server_pid, 0);
}

void	receive_handler(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signo == SIGUSR1)
	{
		ft_putstr_fd("\nsignal sent complete\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	int					server_pid;
	struct sigaction	cli_sig;

	if (ac == 3)
	{
		ft_putstr_fd("client pid : ", 1);
		ft_putnbr_fd(getpid(), 1);
		cli_sig.sa_sigaction = receive_handler;
		sigemptyset(&cli_sig.sa_mask);
		cli_sig.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &cli_sig, 0);
		sigaction(SIGUSR2, &cli_sig, 0);
		server_pid = ft_atoi(av[1]);
		send(server_pid, av[2]);
	}
	else
		ft_putstr_fd("Num of aguments error\n./client [server_pid] [msg]\n", 1);
	return (0);
}
