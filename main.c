/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:49:28 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/09 18:34:50 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include<unistd.h>
//*******ft_putchar*******//
void	ft_putchar(char c , int *res)
{
	write(1, &c, 1);
	*res = *res + 1;
}

//*******ft_putstr*******//
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

//*******ft_putnbr*******//
void	ft_putnbr(int n, int *res)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", res);
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-', res);
		ft_putnbr(n, res);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + 48, res);
		else
		{
			ft_putnbr(n / 10, res);
			ft_putnbr(n % 10, res);
		}
	}
}

//*******ft_putnbr_unsigned*******//
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

//*******ft_putnbr_base*******//
void ft_putnbr_base(unsigned long long nbr, int *res)
{
	char base[] = "0123456789abcdef";
	if (nbr < 16)
			ft_putchar(base[nbr], res);
	else
	{
		ft_putnbr_base(nbr / 16, res);
		ft_putnbr_base(nbr % 16, res);
	}
}

//*******ft_putnbr_base_lower*******//
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

//*******ft_putnbr_base_upper*******//
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


//*******ft_printf*******//
int ft_printf(const char *str, ...)
{
    va_list	args;
	int res;

	res = 0;
	va_start(args,str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				ft_putchar(va_arg(args,int), &res);
			else if (*str == 'd' || *str == 'i')
				ft_putnbr(va_arg(args,int), &res);
			else if (*str == 's')
			{
				if (!va_arg(args, char*))
					ft_putstr("(null)", &res);
				else
					ft_putstr(va_arg(args,char *), &res);
			}
			else if (*str == 'p')
			{
				ft_putstr("0x", &res);
				ft_putnbr_base(va_arg(args,unsigned long long), &res);
			}
			else if (*str == 'u')
				ft_putnbr_unsigned(va_arg(args, unsigned int), &res);
			else if (*str == 'x')
				ft_putnbr_base_lower(va_arg(args,unsigned int), &res);
			else if (*str == 'X')
				ft_putnbr_base_upper(va_arg(args,unsigned int), &res);
			else if (*str == '%')
				ft_putchar('%', &res);
		}
		else
			ft_putchar(*str, &res);
		str++;
	}
	va_end(args);
	return (res);
}

int main()
{
	ft_printf("%d",ft_printf("%s",NULL));
}
