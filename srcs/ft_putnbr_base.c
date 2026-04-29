/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 20:14:54 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/29 16:21:43 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	validate_dup_sign(char *str);

void	putnbr_b(long int nb, char *base, int *counter)
{
	if (ft_strlen(base) > 1 && validate_dup_sign(base) == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-', counter);
			nb = nb * -1;
		}
		if (nb >= (long int)ft_strlen(base))
			putnbr_b(nb / (long int)ft_strlen(base), base, counter);
		ft_putchar(base[nb % (long int)ft_strlen(base)], counter);
	}
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
