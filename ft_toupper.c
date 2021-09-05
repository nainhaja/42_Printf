/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:06:05 by nainhaja          #+#    #+#             */
/*   Updated: 2019/10/22 21:52:02 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper(int str)
{
	if (str >= 'A' && str <= 'Z')
		return (str);
	else if (str >= 'a' && str <= 'z')
		return (str - 32);
	else
		return (str);
}
