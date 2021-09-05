/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:42:44 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/11 23:02:25 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_converthex2(unsigned long long a, char k)
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
			if (a == (unsigned long long)(10 + i))
			{
				test = 1;
				if (k == 'p')
					p = 'a' + i;
			}
			i++;
		}
	}
	else
		p = (char)(a + 48);
	return (p);
}

char	*ft_return2(int p)
{
	if (p != 0)
		return (ft_strdup(""));
	else
		return (ft_strdup("0"));
}

char	*ft_hexconv2(unsigned long long a, char k, int p)
{
	char				*t;
	int					i;
	unsigned long long	b;

	i = 0;
	b = a;
	if (b == 0)
		return (ft_return2(p));
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
		t[i] = ft_converthex2(a % 16, k);
		a = a / 16;
		i--;
	}
	return (t);
}
