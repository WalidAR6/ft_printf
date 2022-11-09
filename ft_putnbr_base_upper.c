/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:07 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/09 20:16:28 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_base_upper(unsigned int nbr, int *res)
{
	char base[] = "0123456789ABCDEF";
	if (nbr < 16)
			ft_putchar(base[nbr], res);
	else
	{
		ft_putnbr_base_upper(nbr / 16, res );
		ft_putnbr_base_upper(nbr % 16, res);
	}
}