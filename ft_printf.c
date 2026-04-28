#include "ft_printf.h"

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
		if (str[i] == '%' && validate(str[i + 1]))
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
