/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:36:29 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/28 17:37:17 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		characters;
	int		i;
	va_list	args;

	characters = 0;
	i = -1;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && validate(str[i + 1]) == 1)
		{
			characters += conversion(str[i + 1], args);
			i++;
		}
		else
			characters += ft_putchar(str[i]);
	}
	va_end(args);
	return (characters);
}

/*#include <stdio.h>

int	main(void)
{
	char			c;
	char			*str;
	void			*ptr;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	xx;
	
	c = 'a';
	str = "Hello World!";
	ptr = &c;
	d = -42;
	i = 0x2a;
	u = 42;
	x = 42;
	xx = 42;

	printf("char:              %c\n"
			"string:            %s\n"
			"void:              %p\n"
			"decimal:           %d\n"
			"integer:           %i\n"
			"unsigned decimal:  %u\n"
			"hexadecimal (low): %x\n"
			"hexadecimal (up):  %X\n\n", c, str, ptr, d, i, u, x, xx);

	ft_printf("char:              %c\n", c);
	ft_printf("string:            %s\n", str);
	ft_printf("void:              %p\n", ptr);
	ft_printf("decimal:           %d\n", d);
	ft_printf("integer:           %i\n", i);
	ft_printf("unsigned decimal:  %u\n", u);
	ft_printf("hexadecimal (low): %x\n", x);
	ft_printf("hexadecimal (up):  %X\n\n", xx);

	d = printf("char:              %c\n", c);
	ft_printf("decimal:           %d\n", d);
	d = ft_printf("char:              %c\n", c);
	ft_printf("decimal:           %d\n", d);
	return (0);
}*/