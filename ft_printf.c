/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:25 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/09 23:26:40 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		res;
	char	*r;

	res = 0;
	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				ft_putchar (va_arg(args, int), &res);
			else if (*str == 'd' || *str == 'i')
				ft_putnbr (va_arg(args, int), &res);
			else if (*str == 's')
			{
				r = va_arg(args, char *);
				if (!r)
				{
					ft_putstr ("(null)", &res);
				}
				else
					ft_putstr (r, &res);
			}
			else if (*str == 'p')
			{
				ft_putstr("0x", &res);
				ft_putnbr_base (va_arg(args, unsigned long long), &res);
			}
			else if (*str == 'u')
				ft_putnbr_unsigned (va_arg(args, unsigned int), &res);
			else if (*str == 'x')
				ft_putnbr_base_lower (va_arg(args, unsigned int), &res);
			else if (*str == 'X')
				ft_putnbr_base_upper (va_arg(args, unsigned int), &res);
			else if (*str == '%')
				ft_putchar('%', &res);
		}
		else
			ft_putchar (*str, &res);
		str++;
	}
	va_end (args);
	return (res);
}
#include<stdio.h>
int main()
{
	ft_printf("%s","hrllo");
}