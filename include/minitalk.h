/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:56:11 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/01/22 04:59:09 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void			ft_put_number(int num);
int				ft_power(int power, int index);
char			*atob(unsigned char car);
unsigned int	ft_atoi(const char *str);
#endif
