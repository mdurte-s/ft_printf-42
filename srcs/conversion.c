/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:35:52 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/29 16:20:38 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion(char flag, va_list args, int *c)
{
	if (flag == 'c')
		ft_putchar(va_arg(args, int), c);
	else if (flag == 's')
		ft_putstr(va_arg(args, char *), c);
	else if (flag == 'p')
		ft_putptr(va_arg(args, void *), c);
	else if (flag == 'd' || flag == 'i')
		putnbr_b((long int)va_arg(args, int), "0123456789", c);
	else if (flag == 'u')
		putnbr_b((long int)va_arg(args, unsigned int), "0123456789", c);
	else if (flag == 'x')
		putnbr_b((long int)va_arg(args, unsigned int), "0123456789abcdef", c);
	else if (flag == 'X')
		putnbr_b((long int)va_arg(args, unsigned int), "0123456789ABCDEF", c);
	else if (flag == '%')
		ft_putchar('%', c);
}

void	ft_putptr(void *ptr, int *c)
{
	if (ptr == 0)
		ft_putstr("(nil)", c);
	else
	{
		ft_putstr("0x", c);
		putnbr_b((long int)ptr, "0123456789abcdef", c);
	}
}

int	validate(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
