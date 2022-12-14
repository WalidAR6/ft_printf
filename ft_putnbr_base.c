/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:42:39 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/10 18:12:12 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nbr, int *res)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(base[nbr], res);
	else
	{
		ft_putnbr_base(nbr / 16, res);
		ft_putnbr_base(nbr % 16, res);
	}
}
