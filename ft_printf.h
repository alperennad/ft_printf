/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirca <ademirca@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:46:08 by ademirca          #+#    #+#             */
/*   Updated: 2024/02/05 13:41:19 by ademirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printstr(const char *c);
int	ft_printdec(long c);
int	ft_printhex1(unsigned int c);
int	ft_printhex2(unsigned int c);
int	ft_printchar(const int c);
int	ft_adress(unsigned long c);
int	ft_printf(const char *format, ...);
int	ft_printuns(unsigned int c);

#endif