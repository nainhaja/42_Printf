/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/08 02:46:26 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int	g_prec;
extern	int	g_len;
extern	int	g_ret;

char	*ft_printzero(char *value)
{
	int test;

	test = g_prec;
	if ((value[0] == '-') && g_prec > 0)
	{
		value = ft_substr(value, 1, ft_strlen(value));
		g_ret++;
		ft_putchar('-');
		g_len = g_len - 1;
	}
	else if ((ft_strcmp(value, "0") == 0) && g_prec == 0)
		value[0] = '\0';
	if (g_prec > ((int)ft_strlen(value)))
	{
		g_prec = g_prec - ft_strlen(value);
		while (g_prec > 0)
		{
			g_ret++;
			ft_putchar('0');
			g_prec = g_prec - 1;
		}
	}
	g_prec = test;
	return (value);
}
