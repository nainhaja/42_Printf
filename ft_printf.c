/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:13:12 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/11 23:16:21 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "string.h"
#include <limits.h>

int g_ret;
int g_prec;
int g_len;

int		ft_checkign(int varg, int *t, char s, int *a)
{
	if (varg < 0)
		*t = 0;
	else if (varg == 0)
	{
		if (g_len >= 0)
			*a = 1;
		else if (g_len < 0 && s == 's')
			*a = 2;
	}
	return (varg);
}

void	ft_checkneg(char *value, char t)
{
	if (value[0] == '-')
		g_len = g_len - 1;
	if (t == 'u' || t == 'x')
	{
		if (g_len == 0)
			g_len = (-1);
	}
	if (g_len <= 0)
		g_len = (-1);
}

char	*ft_cases(va_list args, int a, const char *buff, int i)
{
	char *value;

	value = NULL;
	if (buff[i + 1] == 'd' || buff[i + 1] == 'i')
		value = ft_checkk(ft_itoa(va_arg(args, int)), a);
	else if (buff[i + 1] == 'c')
		value = ft_convert(va_arg(args, int));
	else if (buff[i + 1] == '%')
		value = ft_convert('%');
	else if (buff[i + 1] == 'u')
		value = ft_unta(va_arg(args, unsigned int), a);
	else if (buff[i + 1] == 'x' || buff[i + 1] == 'X')
		value = ft_hexconv(va_arg(args, unsigned int), buff[i + 1], a);
	else if (buff[i + 1] == 'p')
	{
		value = ft_hexconv2(va_arg(args, unsigned long long), buff[i + 1], a);
		value = ft_strjoin("0x", value);
	}
	else if (buff[i + 1] == 's')
		value = ft_checkprec(va_arg(args, char*), a);
	return (value);
}

void	ft_finalcases(int *t, char *value, char buff, int a)
{
	if (t[1] == 0)
	{
		if (t[4] > 0 && value[0] != '%' && buff != 's')
		{
			value = ft_printspace(value, a);
			value = ft_printzero(value);
		}
		else if (t[2] > 0)
		{
			ft_checkneg(value, buff);
			value = ft_printzero2(value, a);
		}
		else
			value = ft_printspace(value, a);
		ft_putstrr(value, buff);
	}
	else
	{
		if (t[4] > 0 && value[0] != '%')
			value = ft_printzero(value);
		else
			g_prec = 0;
		ft_putstrr(value, buff);
		value = ft_printspace(value, a);
	}
}

int		ft_printf(const char *buff, ...)
{
	int		i;
	int		a;
	char	*value;
	int		*t;
	va_list	args;

	value = NULL;
	ft_globalinit(&i, &a);
	t = ft_memset(0, sizeof(int) * 5);
	va_start(args, buff);
	while (buff[i])
	{
		while (buff[i] == '%')
		{
			g_len = ft_flagwid(&i, buff, &t, args);
			a = ft_prectime(&i, buff, &t, args);
			value = ft_cases(args, a, buff, i);
			ft_finalcases(t, value, buff[i + 1], a);
			value = ft_init(value, &t, &i, &a);
		}
		ft_printremaining(buff, &i);
	}
	free(value);
	va_end(args);
	return (g_ret);
}
