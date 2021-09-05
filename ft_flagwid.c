/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/08 01:57:54 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int	g_prec;
extern	int	g_len;
extern	int	g_ret;

int	ft_flagwid(int *i, const char *buff, int **t, va_list args)
{
	while (buff[*i + 1] == '-')
	{
		*i = *i + 1;
		t[0][1] = t[0][1] + 1;
	}
	while (buff[*i + 1] == '0')
	{
		*i = *i + 1;
		t[0][2] = t[0][2] + 1;
	}
	while (ft_isdigit(buff[*i + 1]) == 1 || buff[*i + 1] == '*')
	{
		*i = *i + 1;
		t[0][0] = t[0][0] + 1;
	}
	if (t[0][0] != 0 && buff[*i + 1 - t[0][0]] != '*')
		g_len = ft_width(buff, *i - t[0][0], t[0][0]);
	else if (t[0][0] != 0 && buff[*i + 1 - t[0][0]] == '*')
		g_len = va_arg(args, int);
	if (g_len < 0)
	{
		g_len = g_len * (-1);
		t[0][1] = 1;
	}
	return (g_len);
}
