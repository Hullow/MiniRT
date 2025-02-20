/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:27:06 by fallan            #+#    #+#             */
/*   Updated: 2024/04/04 14:41:17 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_formatted_output(const char format_specifier, va_list ap)
{
	int					res;

	res = 0;
	if (format_specifier == 'd' || format_specifier == 'i')
		res += ft_putnbr(va_arg(ap, int), 0);
	if (format_specifier == 'u')
		res += ft_putnbr_unsigned(va_arg(ap, unsigned int), res);
	if (format_specifier == 'c')
		res += ft_putchar(va_arg(ap, int));
	if (format_specifier == 's')
		res += ft_print_string(va_arg(ap, char *));
	if (format_specifier == 'p')
		res += ft_print_pointer(va_arg(ap, unsigned long long));
	if (format_specifier == '%')
		res += write(1, "%", 1);
	if (format_specifier == 'X' || format_specifier == 'x')
			res += ft_hex(va_arg(ap, unsigned int), format_specifier);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
			res += ft_print_formatted_output(format[++i], ap);
		else
		{
			ft_putchar(format[i]);
			res++;
		}
		i++;
	}
	va_end(ap);
	return (res);
}

// static void	test_string(char *str);
// static void	test_character(int character);
// static void	test_number(int number);
// static void	test_pointer(void *ptr);
/*  
#include <limits.h>
void	paco_tests()
{
	int pf = 0;
	int ft = 0;
	pf = printf("   printf:\n %ld %ld \n", LONG_MIN, LONG_MAX);
	ft = ft_printf("ft_printf:\n %p %p \n", LONG_MIN, LONG_MAX);

	if (pf == ft)
		printf("same returns\n\n**********************************\n");
	else
		printf("pf == %d, ft = %d\n\n**********************************\n", pf, ft);

	pf = printf("   printf:\n %lu %lu \n", ULONG_MAX, -ULONG_MAX);
	ft = ft_printf("ft_printf:\n %p %p \n", ULONG_MAX, -ULONG_MAX);

	if (pf == ft)
		printf("same returns\n");
	else
		printf("pf == %d, ft = %d\n\n**********************************\n", pf, ft);
}
 */

/*

int main()
{
	paco_tests();
// random values tests
// int pf_res = 0;
// int ft_res = 0;

// pointer tests:
	// char character2 = 'b';
	// char *str2 = "hello";
	// int number2 = 10;
	// test_pointer(&character2);
	// test_pointer(&str2);
	// test_pointer(&number2);

	// test_pointer(NULL);
	// test_pointer((void*)-14523);

// number tests:
	// test_number(-995002516);
	// test_number(10);
	// test_number(-10);
	// test_number(0);
	// test_number(-0);
	// test_number(1);
	// test_number(100);
	// test_number(12832);
	// test_number(2147483647);
	// test_number(18446744073709551615);
	// test_number(-100);
	// test_number(-2147483647);
	// test_number(-2147483648);
	// test_number(0.5);
	// test_number(100.5);

// character tests:
// char character = 'b';
	// test_character(0); // tests char = 0->127


// string tests:
// char *str = "hello";
	// printf("aaa%saaa%%aaa%s\n", str, str);
	// ft_printf("aaa%saaa%%aaa%s\n", str, str);
	// printf("aaa%c\n", character);
	// ft_printf("aaa%c\n", character);
	// ft_printf("aaa%c\n", "hello");
	// test_string("aaa");
	// test_string("aaa%saaa%%aaa%s\n");
	// test_string(NULL);
	// test_string("");
	// test_string("0");
	// test_string("a");
	// test_string("\t");

	return 0;
}
 */

/* 
static void	test_number(int number)
{
	int	pf_res = 0;
	int	ft_res = 0;

	// testing for %d
	printf("testing '%d' for %%d:\n", number);
	pf_res = printf("pf - %%d: %d\n", number);
	printf("pf_res 1 = %d\n\n", pf_res);
	ft_res = ft_printf("ft - %%d: %d\n", number);
	printf("ft_res 1 = %d\n", ft_res);
	printf("*********************\n");

	// testing for %i
	// pf_res = 0;
	// ft_res = 0;
	// printf("testing '%d' for %%i:\n", number);
	// printf("pf - %%i: %i\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_printf("ft - %%i: %i\n", number);
	// printf("ft_res = %d\n\n", ft_res);

	// testing for %X
	// printf("testing '%d' for %%X:\n", number);
	// pf_res = printf("pf - %%X: %X\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_res = ft_printf("ft - %%X: %X\n", number);
	// printf("ft_res = %d\n", ft_res);
	// printf("*********************\n");

	// testing for %x
	// printf("testing '%d' for %%x:\n", number);
	// pf_res = printf("pf - %%x: %x\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_res = ft_printf("ft - %%x: %x\n", number);
	// printf("ft_res = %d\n", ft_res);
	// printf("*********************\n");

	// testing for %u
	// pf_res = 0;
	// ft_res = 0;
	// printf("testing '%d' for %%u:\n", number);
	// pf_res = printf("pf - %%u: %u\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_res = ft_printf("ft - %%u: %u\n", number);
	// printf("ft_res = %d\n", ft_res);
	// printf("*********************\n");
}
 */

/*
static void	test_pointer(void *address)
{
	int	pf_res = 0;
	int	ft_res = 0;
	pf_res = printf("pf - %%p: %p\n", address);
	printf("pf_res = %d\n\n", pf_res);
	ft_res = ft_printf("ft - %%p: %p\n", address);
	printf("ft_res = %d\n******************\n", ft_res);
}
 */

/* 
static void	test_string(char *str)
{
	int	pf_res = 0;
	int	ft_res = 0;
	printf("testing '%s':\n--------------\n", str);
	printf("pf - %%s: %s\n", str);
	printf("pf_res = %d\n\n", pf_res);
	ft_printf("ft - %%s: %s\n", str);
	printf("ft_res = %d\n***************************\n", ft_res);
}
 */

/*
static void	test_character(int character)
{
	int	pf_res = 0;
	int	ft_res = 0;
	while (character < 128)
	{
		ft_res = ft_printf("ft: %cokok\n", character);
		printf("ft_res = %d\n", ft_res);

		pf_res = printf("pf: %cokok\n", character);
		printf("pf_res = %d\n\n", pf_res);
	
		character++;
		pf_res = 0;
		ft_res = 0;
	}
}
*/