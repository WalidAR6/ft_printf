/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:42:25 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/09 21:33:00 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_unsigned(unsigned int nbr, int *res)
{
	if (nbr < 10)
		ft_putchar(nbr + 48, res);
	else
	{
		ft_putnbr(nbr / 10, res);
		ft_putnbr(nbr % 10, res);
	}
}