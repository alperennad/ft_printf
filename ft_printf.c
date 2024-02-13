/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirca <ademirca@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:46:11 by ademirca          #+#    #+#             */
/*   Updated: 2024/02/06 16:14:47 by ademirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printchar(const int c)
{
	int	i;

	i = 0;
	i = write(1, &c, 1);
	if (i == -1)
		return (-1);
	else
		return (i);
}

int	ft_adress(unsigned long c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (c >= 16)
	{
		i = ft_adress(c / 16);
		if (i == -1)
			return (-1);
		len += i;
	}
	if (write(1, &"0123456789abcdef"[c % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}

static int	ft_control(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'p' || c == '%')
		return (1);
	else
		return (0);
}

static int	print_funcs(va_list args, char format)
{
	if (format == 'c')
		return (ft_printchar(va_arg(args, const int)));
	else if (format == 's')
		return (ft_printstr(va_arg(args, const char *)));
	else if (format == 'd' || format == 'i')
		return (ft_printdec(va_arg(args, int)));
	else if (format == 'x')
		return (ft_printhex1(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_printhex2(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_printchar('%'));
	else if (format == 'u')
		return (ft_printuns(va_arg(args, unsigned int)));
	else if (format == 'p')
	{
		if (ft_printstr("0x") == -1)
			return (-1);
		return (2 + ft_adress(va_arg(args, unsigned long)));
	}
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		temp;
	va_list	args;
	int		len;

	i = -1;
	temp = 0;
	len = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && ft_control(format[i + 1]))
			temp = print_funcs(args, format[++i]);
		else if (format[i] != '%')
			temp = ft_printchar(format[i]);
		if (temp == -1)
			return (-1);
		len += temp;
		temp = 0;
	}
	va_end(args);
	return (len);
}
/* 
#include <stdio.h>
int main ()
{
	ft_printf("%cs%cs%c", 'c', 'b', 'a');
	printf("\n%cs%cs%c", 'c', 'b', 'a');
}
*/
