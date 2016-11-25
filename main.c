/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 00:00:48 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/20 00:00:50 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <wchar.h>

int	ft_printf(const char *fmt, ...);

int main(int argc, char const **argv)
{
	int a[10];
	int	b[10];
	int	n;
	int	i;

	if (argc < 2 && argv[0])
		return (0);
	setlocale(LC_ALL, "");
	// ft_printf("You:\n");
	// ft_printf("Str %s | Num %%d | Char %c\n", argv[1], atoi(argv[2]), argv[3][0]);
	// ft_printf(":%15s:\n", "Hello, world!");
	// ft_printf(":%.10s:\n", "Hello, world!");
	// ft_printf(":%.15s:\n", "Hello, world!");
	// ft_printf(":%15.10s:\n", "Hello, world!");
	// a[0] = ft_printf("%15.4s", "42");
	// a[1] = ft_printf("NULL s %s", "");
	// a[0] = ft_printf("%.4s", "42 is the answer");
	// a[1] = ft_printf("%.4s", "42");
	// a[2] = ft_printf("%4.15s", "42 is the answer");
	// a[3] = ft_printf("%4.s", "42");
	// a[0] = ft_printf("%.4d", 42);
	// a[1] = ft_printf("%.4d", 424242);
	// a[2] = ft_printf("%4.15d", 42);
	// a[3] = ft_printf("%15.4d", 42);
	// a[4] = ft_printf("%4.15d\n", -42);
	// a[5] = ft_printf("%.d, %.0d\n", 0, 0);
	// a[6] = ft_printf("%s", NULL);
	// a[0] = ft_printf("%.22D ", LONG_MAX);
	// a[1] = ft_printf("%.22D\n", LONG_MIN);
	// a[2] = ft_printf("%.u, %.0u ", 0, 0);
	// a[3] = ft_printf("%U\n", ULONG_MAX);
	// a[4] = ft_printf("%o ", INT_MIN / 2);
	// a[5] = ft_printf("%O\n", INT_MIN / 2);
	// a[6] = ft_printf("%.x\n", -255);
	// a[7] = ft_printf("%X", -255);
	// a[0] = ft_printf("%C\n", L'\u4E2A');
	// a[1] = ft_printf("%C", L'a');
	// a[2] = ft_printf("%S\n", L"米米米米米");
	// a[3] = ft_printf("%S\n", L"XYZab");
	// a[0] = ft_printf("%010d\n", 42);
	// a[1] = ft_printf("%010d\n", -42);
	// a[2] = ft_printf("%#o\n", 42);
	// a[3] = ft_printf("%#o\n", 0);
	// a[4] = ft_printf("%#x", 0);
	a[0] = ft_printf("%.o, %.0o\n", 0, 0);
	a[1] = ft_printf("%05.Z\n", 0);
	a[2] = ft_printf("%5.%\n");
	a[3] = ft_printf("%5%\n");
	a[4] = ft_printf("%05.%\n");
	a[5] = ft_printf("%.3%\n");
	a[6] = ft_printf("% #0-.Zoo\n");
	a[7] = ft_printf("% %");
	// a[1] = ft_printf("%.4s", "42");
	// a[2] = ft_printf("%4.15s", "42 is the answer");
	// a[3] = ft_printf("%4.s", "42");
	ft_printf("\n");
	// a[0] = ft_printf("%d", 42);
	// a[1] = ft_printf("%i", 42);
	// a[2] = ft_printf("This is a simple test.");
	// a[3] = ft_printf("%u", -42);
	printf("Lib:\n");
	// printf("integer: %d; character: %C\n", 123, 57000);
	// printf("Str %s | Num %%d | Char %c\n", argv[1], atoi(argv[2])/*, argv[3][0]*/);
	// printf(":%15s:\n", "Hello, world!");
	// printf(":%.10s:\n", "Hello, world!");
	// printf(":%.15s:\n", "Hello, world!");
	// printf(":%15.10s:\n", "Hello, world!");
	// b[0] = printf("%15.4s", "42");
	// b[1] = printf("NULL s %s", "");
	// b[0] = printf("%.4s", "42 is the answer");
	// b[1] = printf("%.4s", "42");
	// b[2] = printf("%4.15s", "42 is the answer");
	// b[3] = printf("%4.s", "42");
	// b[0] = printf("%.4d", 42);
	// b[1] = printf("%.4d", 424242);
	// b[2] = printf("%4.15d", 42);
	// b[3] = printf("%15.4d", 42);
	// b[4] = printf("%4.15d\n", -42);
	// b[5] = printf("%.d, %.0d\n", 0, 0);
	// b[6] = printf("%s", NULL);
	// b[0] = printf("%.22lD ", LONG_MAX);
	// b[1] = printf("%.22lD\n", LONG_MIN);
	// b[2] = printf("%.u, %.0u ", 0, 0);
	// b[3] = printf("%lU\n", ULONG_MAX);
	// b[4] = printf("%o ", INT_MIN / 2);
	// b[5] = printf("%O\n", INT_MIN / 2);
	// b[6] = printf("%.x\n", -255);
	// b[7] = printf("%X", -255);
	// b[0] = printf("%C\n", L'\u4E2A');
	// b[1] = printf("%C", L'a');
	// b[2] = printf("%S\n", L"米米米米米");
	// b[3] = printf("%S\n", L"XYZab");
	// b[0] = printf("%010d\n", 42);
	// b[1] = printf("%010d\n", -42);
	// b[2] = printf("%#o\n", 42);
	// b[3] = printf("%#o\n", 0);
	// b[4] = printf("%#x", 0);
	b[0] = printf("%.o, %.0o\n", 0, 0);
	b[1] = printf("%05.Z\n", 0);
	b[2] = printf("%5.%\n");
	b[3] = printf("%5%\n");
	b[4] = printf("%05.%\n");
	b[5] = printf("%.3%\n");
	b[6] = printf("% #0-.Zoo\n");
	b[7] = printf("% %");
	// wprintf(L"\u4E2A");
	// b[0] = printf("%d", 42);
	// b[1] = printf("%i", 42);
	// b[2] = printf("This is a simple test.");
	// b[3] = printf("%u", -42);
	n = 8;
	i = -1;
	printf("\n");
	while (++i < n)
		if (a[i] != b[i])
			printf("Test %d FAIL: You %d | Lib %d\n", i, a[i], b[i]);
	return (0);
}
