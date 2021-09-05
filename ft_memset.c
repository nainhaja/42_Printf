/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:45:03 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/09 10:25:20 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_memset(int x, size_t n)
{
	int		*s;
	size_t	i;

	if (!(s = malloc(n)))
		return (0);
	n = n / 4;
	i = 0;
	while (n > i)
	{
		s[i] = x;
		i++;
	}
	return (s);
}
