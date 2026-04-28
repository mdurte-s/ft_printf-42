#include "ft_printf.h"

int	conversion(char c, va_list args)
{
	int	characters;

	characters = 0;
	if (c == 'c')
		characters += ft_putchar(va_args(args, char));
	else if (c == 's')
		characters += ft_putstr(va_args(args, char *));
	else if (c == 'p')
		characters += ft_putptr(va_args(args, void *));
	else if (c == 'd')
		characters += ft_putdec(va_args(args, int));
	else if (c == 'i')
		characters += ft_putnbr(va_args(args, int));
	else if (c == 'u')
		characters += ft_putnbr_unsigned(va_args(args, unsigned int));
	else if (c == 'x')
		characters += ft_puthex_lower(va_args(args, unsigned int));
	else if (c == 'X')
		characters += ft_puthex_upper(va_args(args, unsigned int));
	else if (c == '%')
		characters += ft_putchar('%');
	return (characters);
}

int	validate(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' ||c == 'x' || c == 'X' ||c == '%')
		return (1);
	return (0);
}
