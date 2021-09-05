/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/08 01:51:19 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int	g_prec;
extern	int	g_len;

char	*ft_checkprec(char *value, int a)
{
	char *t;

	if (value == 0 && a <= 0)
		t = ft_strdup("(null)");
	else if (value == 0 && a == 1)
	{
		t = ft_strdup("");
		g_prec = 0;
		return (t);
	}
	else if (g_prec == 0 && g_len >= 0 && a > 0)
		t = ft_strdup("");
	else
		t = ft_strdup(value);
	if (g_prec == -1)
		t = ft_strdup("");
	if (g_prec > 0 && g_prec < (int)ft_strlen(t))
	{
		t[g_prec] = '\0';
	}
	g_prec = 0;
	return (t);
}
