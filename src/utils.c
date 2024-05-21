/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:48:58 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/05/21 03:35:55 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_put_number(int num)
{
	if (num >= 0 && num <= 9)
	{
		num += 48;
		write(1, &num, 1);
	}
	else if (num > 9)
	{
		ft_put_number(num / 10);
		ft_put_number(num % 10);
	}
}

int	ft_power(int power, int index)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	if (power == 0 && index == 1)
		return (1);
	if (index == 1)
	{
		while (i < power)
		{
			res *= 2;
			i++;
		}
		return (res);
	}
	return (0);
}

char	*atob(unsigned char car)
{
	char	*ptr;
	int		i;

	i = 7;
	ptr = malloc(9);
	if (!ptr)
		return (NULL);
	while (i >= 0)
	{
		if (car % 2 == 1)
			ptr[i--] = '1';
		else
			ptr[i--] = '0';
		car /= 2;
	}
	ptr[8] = '\0';
	return (ptr);
}

unsigned int	ft_atoi(const char *str)
{
	unsigned int	res;
	int				i;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "L'identifiant process invalide", 30);
			exit(1);
		}
		res = res * 10 + str[i++] - '0';
	}
	return (res);
}
