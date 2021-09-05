/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/08 02:43:35 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int	g_prec;
extern	int	g_len;
extern	int	g_ret;

char	*ft_printspace(char *value, int a)
{
	int b;
	int c;

	b = g_prec;
	c = g_len;
	if (value[0] == '-')
		g_prec = g_prec + 1;
	if ((ft_strcmp(value, "0") == 0) && a == -1)
		value[0] = '\0';
	if (g_prec > 0 && g_prec > (int)ft_strlen(value))
		g_prec = g_prec - (int)ft_strlen(value);
	else
		g_prec = 0;
	g_len = g_len - ft_strlen(value) - g_prec;
	while (g_len > 0)
	{
		g_ret++;
		ft_putchar(' ');
		g_len--;
	}
	g_prec = b;
	g_len = c;
	return (value);
}
