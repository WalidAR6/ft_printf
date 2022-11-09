/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:49:28 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/09 02:27:53 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		ft_putnbr(n);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}

void ft_putnbr_unsigned(unsigned int nbr)
{
	if (nbr < 10)
		ft_putchar(nbr + 48);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void ft_putnbr_base(unsigned long long nbr)
{
	char base[] = "0123456789abcdef";
	if (nbr < 16)
			ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base(nbr / 16);
		ft_putnbr_base(nbr % 16);
	}
}

void ft_putnbr_base_lower(unsigned int nbr)
{
	char base[] = "0123456789abcdef";
	if (nbr < 16)
			ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base_lower(nbr / 16);
		ft_putnbr_base_lower(nbr % 16);
	}
}

void ft_putnbr_base_upper(unsigned int nbr)
{
	char base[] = "0123456789ABCDEF";
	if (nbr < 16)
			ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base_upper(nbr / 16);
		ft_putnbr_base_upper(nbr % 16);
	}
}


void ft_printf(const char *str, ...)
{
    va_list	args;
	va_start(args,str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				ft_putchar(va_arg(args,int));
			else if (*str == 'd' || *str == 'i')
				ft_putnbr(va_arg(args,int));
			else if (*str == 's')
				ft_putstr(va_arg(args,char *));
			else if (*str == 'p')
			{
				ft_putstr("0x");
				ft_putnbr_base(va_arg(args,unsigned long long));
			}
			else if (*str == 'u')
				ft_putnbr_unsigned(va_arg(args, unsigned int));
			else if (*str == 'x')
				ft_putnbr_base_lower(va_arg(args,unsigned int));
			else if (*str == 'X')
				ft_putnbr_base_upper(va_arg(args,unsigned int));
			else if (*str == '%')
				ft_putchar('%');
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(args);
}
