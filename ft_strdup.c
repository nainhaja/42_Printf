/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:33:19 by nainhaja          #+#    #+#             */
/*   Updated: 2019/10/22 22:12:14 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (ptr == 0)
		return (0);
	else
	{
		while (s[i])
		{
			ptr[i] = s[i];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
