/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 20:14:54 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/28 17:34:09 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	intlen(long int n);
static int	validate_dup_sign(char *str);

int	putnbr_b(long int nb, char *base)
{
	int			characters;

	characters = intlen(nb);
	if (ft_strlen(base) > 1 && validate_dup_sign(base) == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		if (nb >= (long int)ft_strlen(base))
			putnbr_b(nb / (long int)ft_strlen(base), base);
		ft_putchar(base[nb % (long int)ft_strlen(base)]);
	}
	return (characters);
}

static int	validate_dup_sign(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j] != str[i] && str[j] != '\0')
			j++;
		if (str[j] == str[i])
			return (0);
		i++;
	}
	return (1);
}

static int	intlen(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 9 || n < -9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
