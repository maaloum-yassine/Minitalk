/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 07:40:54 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/05/21 03:37:07 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_send_signal_client(int pid_client)
{
	if (kill (pid_client, SIGUSR2) == -1)
	{
		write(2, "Erreur signal chèque l'identifiant process", 43);
		exit(1);
	}
}

int	ft_putchar(int assci)
{
	write(1, &assci, 1);
	return (7);
}

void	my_handler(int num, siginfo_t *info, void *ptr)
{
	static int	index = 7;
	static int	assci = 0;
	static int	pid = 0;

	(void)*ptr;
	if (pid != info->si_pid)
	{
		index = 7;
		assci = 0;
	}
	if (index > -1)
	{
		if (num == SIGUSR1)
			assci += ft_power(index--, 1);
		else
		index--;
	}
	if (index == -1)
	{
		if (assci == 0)
			ft_send_signal_client(pid);
		index = ft_putchar(assci);
		assci = 0;
	}
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = my_handler;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_put_number(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
