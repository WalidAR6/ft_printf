/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:25 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/10 22:38:34 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conditions(const char *str, int *res, va_list	args)
{
	if (*str == 'c')
		ft_putchar (va_arg(args, int), res);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr (va_arg(args, int), res);
	else if (*str == 's')
		ft_putstr (va_arg(args, char *), res);
	else if (*str == 'p')
	{
		ft_putstr("0x", res);
		ft_putnbr_base(va_arg(args, unsigned long long), res);
	}
	else if (*str == 'u')
		ft_putnbr_unsigned (va_arg(args, unsigned int), res);
	else if (*str == 'x')
		ft_putnbr_base_lower (va_arg(args, unsigned int), res);
	else if (*str == 'X')
		ft_putnbr_base_upper (va_arg(args, unsigned int), res);
	else if (*str == '%')
		ft_putchar('%', res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		res;

	res = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!*str)
			{
				write(1, "", 1);
				break ;
			}
			else
				conditions(str, &res, args);
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
	ft_printf("%","hello");
}
