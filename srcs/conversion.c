/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:35:52 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/28 17:38:09 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(char flag, va_list args)
{
	int	c;

	c = 0;
	if (flag == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (flag == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
	{
		c += ft_putstr("0x");
		c += putnbr_b((long int)va_arg(args, void *), "0123456789abcdef");
	}
	else if (flag == 'd' || flag == 'i')
		c += putnbr_b((long int)va_arg(args, int), "0123456789");
	else if (flag == 'u')
		c += putnbr_b((long int)va_arg(args, unsigned int), "0123456789");
	else if (flag == 'x')
		c += putnbr_b((long int)va_arg(args, unsigned int), "0123456789abcdef");
	else if (flag == 'X')
		c += putnbr_b((long int)va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (flag == '%')
		c += ft_putchar('%');
	return (c);
}

int	validate(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
