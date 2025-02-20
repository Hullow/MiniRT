/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:28:34 by fallan            #+#    #+#             */
/*   Updated: 2024/04/04 19:40:57 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_pointer(unsigned long long ptr);
int	ft_print_string(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n, int res);
int	ft_putnbr_unsigned(unsigned int n, int res);
int	ft_hex(unsigned int number, char format_specifier);

#endif