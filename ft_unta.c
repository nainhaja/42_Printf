/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:42:44 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/09 10:30:05 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_clen(unsigned int a)
{
	int i;

	i = 0;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

static char	*ft_rev(char *s, int len)
{
	int		i;
	char	tmp;

	i = 0;
	len--;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}
	return (s);
}

static char	*ft_remplir(char *s, unsigned int a, int len)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = a;
	while (i < len)
	{
		s[i] = (char)(n % 10) + 48;
		n = n / 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_unta(unsigned int a, int cpt)
{
	unsigned int	len;
	char			*s;

	len = ft_clen(a);
	if (a != 0)
	{
		if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
	}
	else
	{
		if (cpt == 0)
		{
			if (!(s = (char *)malloc(sizeof(char) * (len + 2))))
				return (0);
			s[0] = '0';
			s[1] = '\0';
		}
		else
			s = ft_strdup("");
		return (s);
	}
	s = ft_remplir(s, a, len);
	s = ft_rev(s, len);
	return (s);
}
