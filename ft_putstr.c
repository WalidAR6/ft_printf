/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:41:53 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/09 18:49:04 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *s, int *res)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], res);
		i++;
	}
}