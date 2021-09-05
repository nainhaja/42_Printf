/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 01:54:49 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/08 03:56:10 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putnbr2(unsigned int a)
{
	if (a <= 9)
		ft_putchar(((char)a) + '0');
	else
	{
		ft_putnbr2(a / 10);
		ft_putnbr2(a % 10);
	}
}

void			ft_putnbr(int a)
{
	if (a < 0)
	{
		ft_putchar('-');
		ft_putnbr2(-a);
	}
	else
		ft_putnbr2(a);
}
