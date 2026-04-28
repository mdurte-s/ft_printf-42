#include "ft_printf.h"

static int	intlen(int n);

int	ft_putnbr(int n)
{
	long int	nn;
	int			len;

	len = intlen(n);
	nn = n;
	if (nn < 0)
	{
		nn = nn * -1;
		ft_putchar('-');
	}
	if (nn > 9)
		ft_putnbr(nn / 10);
	ft_putchar(nn % 10 + 48);
	return (len);
}

static int	intlen(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
