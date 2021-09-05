/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/09 10:24:49 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int	g_prec;
extern	int	g_len;

char	*ft_convert(char t)
{
	char *p;

	if (!(p = malloc(sizeof(char) * 2)))
		return (0);
	p[0] = t;
	p[1] = '\0';
	if (p[0] == '\0')
		g_len = g_len - 1;
	g_prec = 0;
	return (p);
}
