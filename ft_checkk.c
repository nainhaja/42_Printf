/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/08 01:48:48 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int	g_prec;
extern	int	g_len;

char	*ft_checkk(char *value, int a)
{
	if (g_len == 0 && value[0] == '0')
		g_len = -1;
	else if (g_prec == 0 && value[0] == '0')
		g_len = g_len + a;
	else if (value[0] == '0' && a == -1)
		value[0] = '\0';
	return (value);
}
