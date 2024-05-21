/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 07:40:30 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/05/21 03:38:06 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_send_signal(char binary_digit, unsigned int pid)
{
	if (binary_digit == '1')
	{
		if (kill (pid, SIGUSR1) == -1)
		{
			write(2, "Erreur signal chèque l'identifiant process", 43);
			exit(1);
		}
	}
	else
	{
		if (kill (pid, SIGUSR2) == -1)
		{
			write(2, "Erreur signal chèque l'identifiant process", 43);
			exit (1);
		}
	}
}

void	ft_handler(int num)
{
	if (num == SIGUSR2)
		write(1, "le Msg bien recu au server\n", 27);
}

void	ft_send_signal_reponsed(unsigned int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (kill (pid, SIGUSR2) == -1)
		{
			write(2, "Erreur signal chèque l'identifiant process", 43);
			exit(1);
		}
		i++;
		usleep(150);
	}
}

int	main(int ac, char **av)
{
	unsigned int			process_id;
	char				*binairy;
	int				i;
	int				j;

	i = 0;
	j = 0;
	signal(SIGUSR2, ft_handler);
	if (ac >= 3)
	{
		process_id = ft_atoi(av[1]);
		while (av[2][i])
		{
			binairy = atob ((unsigned char)av[2][i++]);
			while (binairy[j])
			{
				ft_send_signal (binairy[j++], process_id);
				usleep(150);
			}
			free (binairy);
			j = 0;
		}
		ft_send_signal_reponsed(process_id);
	}
	else
	{
		write(2, "Le client du programme prend deux arguments, l'identifiant du serveur et le message !", 83);
		return (1);
	}
	return (0);
}
