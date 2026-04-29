/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:36:29 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/29 16:41:47 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		c;
	int		i;
	va_list	args;

	c = 0;
	i = -1;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && validate(str[i + 1]) == 1)
		{
			conversion(str[i + 1], args, &c);
			i++;
		}
		else
			ft_putchar(str[i], &c);
	}
	va_end(args);
	return (c);
}

/* int	main(void)
{
	int				real = 0;
	int				fake = 0;
	char			c = 'a';
	char			*str = "Hello World!";
	void			*ptr = &c;
	int				d = -42;
	int				i = 0x2a;
	unsigned int	u = 42;
	unsigned int	x = 42;
	unsigned int	xx = 42;

	printf("char:              %c\n", c);
	printf("string:            %s\n", str);
	printf("void:              %p\n", ptr);
	printf("decimal:           %d\n", d);
	printf("integer:           %i\n", i);
	printf("unsigned decimal:  %u\n", u);
	printf("hexadecimal (low): %x\n", x);
	printf("hexadecimal (up):  %X\n\n", xx);

	ft_printf("char:              %c\n", c);
	ft_printf("string:            %s\n", str);
	ft_printf("void:              %p\n", ptr);
	ft_printf("decimal:           %d\n", d);
	ft_printf("integer:           %i\n", i);
	ft_printf("unsigned decimal:  %u\n", u);
	ft_printf("hexadecimal (low): %x\n", x);
	ft_printf("hexadecimal (up):  %X\n\n", xx);
 
	printf("real = %d | fake = %d\n", real, fake);
	
	return (0);
} */
