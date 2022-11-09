/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_lower.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:42:57 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/09 20:15:19 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_base_lower(unsigned int nbr, int *res)
{
	char base[] = "0123456789abcdef";
	if (nbr < 16)
			ft_putchar(base[nbr], res);
	else
	{
		ft_putnbr_base_lower(nbr / 16, res);
		ft_putnbr_base_lower(nbr % 16, res);
	}
}