/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/08 03:57:30 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int	g_ret;

void	ft_putstrr(const char *str, char t)
{
	if (t == 'c' && *str == '\0')
	{
		ft_putchar('\0');
		g_ret++;
	}
	else
	{
		while (*str)
		{
			ft_putchar(*str);
			str++;
			g_ret++;
		}
	}
}
