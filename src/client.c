/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:15:01 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/05/21 03:37:10 by ymaaloum         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	unsigned int	process_id;
	char			*binairy;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (ac >= 3)
	{
		process_id = ft_atoi(av[1]);
		while (av[2][i])
		{
			binairy = atob ((unsigned char)av[2][i]);
			while (binairy[j])
			{
				ft_send_signal (binairy[j], process_id);
				j++;
				usleep(150);
			}
			i++;
			free (binairy);
			j = 0;
		}
	}
	else
	{
		write(2, "Le client du programme prend deux arguments, l'identifiant du serveur et le message !", 83);
		return (1);
	}
	return (0);
}
