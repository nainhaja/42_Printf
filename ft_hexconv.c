/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:43:07 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/11 23:02:02 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_converthex(unsigned int a, char k)
{
	int		test;
	int		i;
	char	p;

	test = 0;
	i = 0;
	if (a >= 10)
	{
		while (test == 0)
		{
			if (a == (unsigned int)(10 + i))
			{
				test = 1;
				if (k == 'x' || k == 'p')
					p = 'a' + i;
				else if (k == 'X')
					p = 'A' + i;
			}
			i++;
		}
	}
	else
		p = (char)(a + 48);
	return (p);
}

char	*ft_return(int p)
{
	if (p != 0)
		return (ft_strdup(""));
	else
		return (ft_strdup("0"));
}

char	*ft_hexconv(unsigned int a, char k, int p)
{
	char				*t;
	int					i;
	unsigned int		b;

	i = 0;
	b = a;
	if (b == 0)
		return (ft_return(p));
	while (b > 0)
	{
		b = b / 16;
		i++;
	}
	if (!(t = malloc(sizeof(char) * (i + 1))))
		return (0);
	t[i] = '\0';
	i--;
	while (a > 0)
	{
		t[i] = ft_converthex(a % 16, k);
		a = a / 16;
		i--;
	}
	return (t);
}
