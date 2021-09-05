/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:24:20 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/11 23:01:37 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int	g_prec;
extern int	g_len;

char	*ft_init(char *value, int **t, int *i, int *a)
{
	int j;

	j = 0;
	while (j < 5)
	{
		t[0][j] = 0;
		j++;
	}
	if (value != NULL)
		*i = *i + 2;
	g_len = 0;
	g_prec = 0;
	value = NULL;
	*a = 0;
	return (value);
}
