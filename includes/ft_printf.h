/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:36:07 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/29 16:45:05 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);

int		ft_strlen(char *str);
int		validate(char c);

void	ft_putchar(int c, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_putptr(void *ptr, int *counter);
void	putnbr_b(long int nb, char *base, int *ccounter);
void	conversion(char c, va_list arg, int *counter);

#endif
