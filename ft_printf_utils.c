/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirca <ademirca@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:45:52 by ademirca          #+#    #+#             */
/*   Updated: 2024/02/05 17:41:53 by ademirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printstr(const char *c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!c)
	{
		len = write(1, "(null)", 6);
		if (len == -1)
			return (-1);
		else
			return (6);
	}
	while (c[i])
	{
		len = write(1, &c[i++], 1);
		if (len == -1)
			return (-1);
	}
	return (i);
}

int	ft_printuns(unsigned int c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (c > 9)
	{
		i = ft_printuns(c / 10);
		if (i == -1)
			return (-1);
		len += i;
	}
	if (write(1, &"0123456789"[c % 10], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_printdec(long c)
{
	int	i;

	i = 0;
	if (c < 0)
	{
		if (ft_printchar('-') == -1)
			return (-1);
		i++;
		c *= -1;
	}
	if (c > 9)
	{
		i += ft_printdec(c / 10);
		if (i == -1)
			return (-1);
	}
	if (write(1, &"0123456789"[c % 10], 1) == -1)
		return (-1);
	return (i + 1);
}

int	ft_printhex1(unsigned int c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (c >= 16)
	{
		i = ft_printhex1(c / 16);
		if (i == -1)
			return (-1);
		len += i;
	}
	if (write(1, &"0123456789abcdef"[c % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_printhex2(unsigned int c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (c >= 16)
	{
		i = ft_printhex2(c / 16);
		if (i == -1)
			return (-1);
		len += i;
	}
	if (write(1, &"0123456789ABCDEF"[c % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}
