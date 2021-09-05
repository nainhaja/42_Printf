/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/09 10:26:38 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int	g_prec;
extern	int	g_len;
extern	int	g_ret;

int		ft_condition(char s, int t)
{
	int a;

	a = 0;
	if (g_len >= 0 && t != 0 && s != 's')
		a = 0;
	else if (g_len >= 0)
		a = 1;
	else if (g_len < 0 && s == 's')
		a = 2;
	else
		a = 0;
	return (a);
}

int		ft_condition2(void)
{
	int a;

	a = -1;
	g_prec = -1;
	return (a);
}

int		ft_condition3(int a, const char *s, int i, int j)
{
	g_prec = ft_width(s, i, j);
	if (g_prec == -1)
		a = -1;
	return (a);
}

int		ft_prectime(int *i, const char *buff, int **t, va_list args)
{
	int a;

	a = 0;
	if (buff[*i + 1] == '.')
	{
		while (ft_isdigit(buff[*i + 2]) == 1 || buff[*i + 2] == '*')
		{
			*i = *i + 1;
			t[0][4] = t[0][4] + 1;
		}
		if (t[0][4] != 0 && buff[*i + 2 - t[0][4]] != '*')
			a = ft_condition3(a, buff, *i + 1 - t[0][4], t[0][4]);
		else if (t[0][4] != 0 && buff[*i + 2 - t[0][4]] == '*')
		{
			g_prec = va_arg(args, int);
			if (g_prec < 0)
				t[0][4] = 0;
			else if (g_prec == 0)
				a = ft_condition(buff[*i + 2], t[0][1]);
		}
		else
			a = ft_condition2();
		*i = *i + 1;
	}
	return (a);
}
