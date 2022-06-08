/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:18:19 by yjoo              #+#    #+#             */
/*   Updated: 2022/06/08 18:18:19 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	signal_error(void)
{
	ft_putstr_fd("\n[server : signal_error]\n", 1);
	exit(EXIT_FAILURE);
}

void	var_init(int *cli_pid, int *i, char *c, int new_pid)
{
	*cli_pid = new_pid;
	*i = 0;
	*c = 0;
}

void	print_msg(int *i, char *c, int *cli_pid)
{
	if (*c == 0)
	{
		ft_putchar_fd(*c, 1);
		ft_putstr_fd("\nfrom client pid : ", 1);
		ft_putnbr_fd(*cli_pid, 1);
		ft_putstr_fd("\n", 1);
		if (kill(*cli_pid, SIGUSR1) == -1)
			signal_error();
		return ;
	}
	ft_putchar_fd(*c, 1);
	*i = 0;
}

void	send_handler(int signo, siginfo_t *info, void *context)
{
	static int	i;
	static int	cli_pid;
	static char	c;

	(void)context;
	if (!cli_pid || cli_pid != info->si_pid)
		var_init(&cli_pid, &i, &c, info->si_pid);
	c |= (signo == SIGUSR2);
	i++;
	if (i == 8)
		print_msg(&i, &c, &cli_pid);
	c <<= 1;
	usleep(80);
	if (kill(cli_pid, SIGUSR2) == -1)
		signal_error();
}

int	main(void)
{
	struct sigaction	ser_sig;

	ser_sig.sa_sigaction = send_handler;
	sigemptyset(&ser_sig.sa_mask);
	ser_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ser_sig, 0);
	sigaction(SIGUSR2, &ser_sig, 0);
	ft_putstr_fd("SERVER PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
