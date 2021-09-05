/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/08 02:50:20 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int	g_prec;
extern	int	g_len;
extern	int	g_ret;

void	ft_zerondspace(int test, char *value)
{
	g_len = g_len - ft_strlen(value);
	if (test == 0)
	{
		while (g_len > 0)
		{
			g_ret++;
			ft_putchar('0');
			g_len = g_len - 1;
		}
	}
	else
	{
		while (g_len > 0)
		{
			g_ret++;
			ft_putchar(' ');
			g_len = g_len - 1;
		}
	}
}

char	*ft_printzero2(char *value, int a)
{
	int test;

	test = 0;
	if ((ft_strcmp(value, "0") == 0) && g_prec > 0)
		value[0] = '\0';
	else if ((ft_strcmp(value, "0") == 0) && g_len == -1 && a == -1)
		value[0] = '\0';
	if (a == -1 && value[0] != '%')
		test++;
	if ((value[0] == '-') && g_len > 0 && g_prec != -1)
	{
		value = ft_substr(value, 1, ft_strlen(value));
		g_ret++;
		ft_putchar('-');
	}
	else if ((value[0] == '-') && g_len > 0 && g_prec == -1)
	{
		g_len++;
	}
	if (g_len > ((int)ft_strlen(value)))
		ft_zerondspace(test, value);
	return (value);
}
