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

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <wchar.h>

int	 ft_printf(const char *fmt, ...);
void ft_putlldbl(long double n, int prec);

int	main(int argc, char const **argv)
{
	int a[11];
	int	b[11];
	int	n;
	int	i;

	if (argc < 2 && argv[0])
		return (0);
	printf("%s\n", argv[1]);
	// setlocale(LC_ALL, "");
	// ft_printf("You:\n");
	// ft_printf(":%15s:\n", "Hello, world!");
	// ft_printf(":%.10s:\n", "Hello, world!");
	// ft_printf(":%.15s:\n", "Hello, world!");
	// ft_printf(":%15.10s:\n", "Hello, world!");
	// ft_putlldbl(100.424242, 4);
	// ft_printf("\n");
	// a[0] = ft_printf("{%f}{%F}\n", -100.42, -100.42);
	// a[1] = ft_printf("{%f}{%F}\n", -1.42, -1.42);
	// a[2] = ft_printf("{%f}{%F}\n", -1.41676767, -1.41676767);
	// a[3] = ft_printf("{%.f}{%.F}", -1.0, -1.0);
	a[0] = ft_printf("%5.5d| %5.5d| %5.- d| %5.-+0# d|\n", -33812, -33812, -33812, -33812);
	a[1] = ft_printf("%5.4d| %5.4d| %5.4- d| %5.4-+0# d|\n", -33812, -33812, -33812, -33812);
	a[2] = ft_printf("%5.5d| %5.5d| %5.- d| %5.-+0# d|\n", 33812, 33812, 33812, 33812);
	a[3] = ft_printf("%5.4d| %5.4d| %5.4- d| %5.4-+0# d|\n", 33812, 33812, 33812, 33812);
	a[4] = ft_printf("%5.5d|%5.5d|%5. d|%5.+0# d|\n", 0, 0, 0, 0);
	a[5] = ft_printf("%5.5d|%5.4d|%5.4 d|%5.4+0# d|\n", 0, 0, 0, 0);
	a[6] = ft_printf("%5.5d|%5.5d|%5. d|%5.+0# d|\n", 1001, 1001, 1001, 1001);
	a[7] = ft_printf("%5.5d|%5.4d|%5.4 d|%5.4+0# d|\n", -1000, -1000, -1000, -1000);
	a[8] = ft_printf("%5.5d|%5.5d|%5. d|%5.+0# d|\n", 1, 1, 1, 1);
	// a[0] = ft_printf("%.-5d| %.5-d| %.- d| %.-+0# d|\n", -33812, -33812, -33812, -33812);
	// a[1] = ft_printf("%.-4d| %.4-d| %.4- d| %.4-+0# d|\n", -33812, -33812, -33812, -33812);
	// a[2] = ft_printf("%.-5d| %.5-d| %.- d| %.-+0# d|\n", 33812, 33812, 33812, 33812);
	// a[3] = ft_printf("%.-4d| %.4-d| %.4- d| %.4-+0# d|\n", 33812, 33812, 33812, 33812);
	// a[4] = ft_printf("%.-5d|%.5-d|%.- d|%.-+0# d|\n", 0, 0, 0, 0);
	// ft_printf("%.4- d", 1);
	// printf("%.4- d\n", 1);
	// a[4] = ft_printf("%.-5d\n", 0);
	// a[5] = ft_printf("%.5-d\n", 0);
	// a[6] = ft_printf("%.- d\n", 0);
	// a[7] = ft_printf("%.-+0# d", 0);
	// a[5] = ft_printf("%.-4d|%.4-d|%.4- d|%.4-+0# d|\n", 0, 0, 0, 0);
	// a[6] = ft_printf("%.-5d|%.5-d|%.- d|%.-+0# d|\n", 1001, 1001, 1001, 1001);
	// a[7] = ft_printf("%.-4d|%.4-d|%.4- d|%.4-+0# d|\n", -1000, -1000, -1000, -1000);
	// a[8] = ft_printf("%.-5d|%.5-d|%.- d|%.-+0# d|\n", 1, 1, 1, 1);
	// a[9] = ft_printf("{%+03d}", 0);
	// ft_printf("\n%.-5d %.5-d", 0, 0);
	// a[0] = ft_printf("{%3*d}\n", 0, 0);
	// a[1] = ft_printf("%*d\n", 5, 42);
	// a[2] = ft_printf("%*.*d\n", 0, 3, 0);
	// a[3] = ft_printf("{%05.*d}\n", -15, 42);
	// a[4] = ft_printf("{%.*d}\n", -5, 42);
	// a[5] = ft_printf("{%.*d}\n", 0, 42);
	// a[6] = ft_printf("{%.*s}", 0, "42");
	// a[7] = ft_printf("\n{%.d}", 42);
	// a[8] = ft_printf("\n{%.u}", 42);
	// a[9] = ft_printf("\n%.d, %.0d", 0, 0);
	// ft_printf("\nLe fichier \x1b[36m%s\x1b[0m contient : \x1b[31m%s\x1b[0m", "xyz", "ABCDEF");
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
	// a[0] = ft_printf("%#.o\n", 42);
	// a[1] = ft_printf("%.p\n", 42);
	// a[2] = ft_printf("%#.x\n", 42);
	// a[3] = ft_printf("%#.x, %#.0x\n", 0, 0);
	// a[4] = ft_printf("%.x, %.0x\n", 0, 0);
	// a[5] = ft_printf("%#5x\n", 0);
	// a[6] = ft_printf("%.o, %.0o\n", 0, 0);
	// a[7] = ft_printf("%#.o, %#.0o\n", 0, 0);
	// a[8] = ft_printf("%5p\n", 0);
	// a[9] = ft_printf("%.p, %.0p\n", 0, 0);
	// a[10] = ft_printf("%p, %0p", 0, 0);
	// a[0] = ft_printf("%15.4d\n", 42);
	// a[1] = ft_printf("{%10d}\n", 42);
	// a[2] = ft_printf("{%-10d}\n", 42);
	// a[3] = ft_printf("{%010d}\n", 42);
	// a[4] = ft_printf("{%+03d}", 0);
	// a[5] = ft_printf("%15.4x\n", 42);
	// a[6] = ft_printf("% #0-.Zoo\n");
	// a[7] = ft_printf("% %");
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
	// b[0] = printf("%#.o\n", 42);
	// b[1] = printf("%.p\n", 42);
	// b[2] = printf("%#.x\n", 42);
	// b[3] = printf("%#.x, %#.0x\n", 0, 0);
	// b[4] = printf("%.x, %.0x\n", 0, 0);
	// b[5] = printf("%#5x\n", 0);
	// b[6] = printf("%.o, %.0o\n", 0, 0);
	// b[7] = printf("%#.o, %#.0o\n", 0, 0);
	// b[8] = printf("%5p\n", 0);
	// b[9] = printf("%.p, %.0p\n", 0, 0);
	// b[10] = printf("%p, %0p", 0, 0);
	// b[0] = printf("%15.4d\n", 42);
	// b[1] = printf("{%10d}\n", 42);
	// b[2] = printf("{%-10d}\n", 42);
	// b[3] = printf("{%010d}\n", 42);
	// b[4] = printf("{%+03d}", 0);
	// b[5] = printf("%.3%\n");
	// b[6] = printf("% #0-.Zoo\n");
	// b[7] = printf("% %");
	// b[0] = printf("%d", 42);
	// b[1] = printf("%i", 42);
	// b[2] = printf("This is a simple test.");
	// b[3] = printf("%u", -42);
	// b[0] = printf("{%f}{%F}\n", -100.42, -100.42);
	// b[1] = printf("{%f}{%F}\n", -1.42, -1.42);
	// b[2] = printf("{%f}{%F}\n", -1.41676767, -1.41676767);
	// b[3] = printf("{%.f}{%.F}", -1.0, -1.0);
	// b[0] = printf("{%3*d}\n", 0, 0);
	// b[1] = printf("%*d\n", 5, 42);
	// b[2] = printf("%*.*d\n", 0, 3, 0);
	// b[3] = printf("{%05.*d}\n", -15, 42);
	// b[4] = printf("{%.*d}\n", -5, 42);
	b[0] = printf("%5.5d| %5.5d| %5.- d| %5.-+0# d|\n", -33812, -33812, -33812, -33812);
	b[1] = printf("%5.4d| %5.4d| %5.4- d| %5.4-+0# d|\n", -33812, -33812, -33812, -33812);
	b[2] = printf("%5.5d| %5.5d| %5.- d| %5.-+0# d|\n", 33812, 33812, 33812, 33812);
	b[3] = printf("%5.4d| %5.4d| %5.4- d| %5.4-+0# d|\n", 33812, 33812, 33812, 33812);
	b[4] = printf("%5.5d|%5.5d|%5. d|%5.+0# d|\n", 0, 0, 0, 0);
	b[5] = printf("%5.5d|%5.4d|%5.4 d|%5.4+0# d|\n", 0, 0, 0, 0);
	b[6] = printf("%5.5d|%5.5d|%5. d|%5.+0# d|\n", 1001, 1001, 1001, 1001);
	b[7] = printf("%5.5d|%5.4d|%5.4 d|%5.4+0# d|\n", -1000, -1000, -1000, -1000);
	b[8] = printf("%5.5d|%5.5d|%5. d|%5.+0# d|\n", 1, 1, 1, 1);
	// b[0] = printf("%.-5d| %.5-d| %.- d| %.-+0# d|\n", -33812, -33812, -33812, -33812);
	// b[1] = printf("%.-4d| %.4-d| %.4- d| %.4-+0# d|\n", -33812, -33812, -33812, -33812);
	// b[2] = printf("%.-5d| %.5-d| %.- d| %.-+0# d|\n", 33812, 33812, 33812, 33812);
	// b[3] = printf("%.-4d| %.4-d| %.4- d| %.4-+0# d|\n", 33812, 33812, 33812, 33812);
	// b[4] = printf("%.-5d|%.5-d|%.- d|%.-+0# d|\n", 0, 0, 0, 0);
	// b[4] = printf("%.-5d\n", 0);
	// b[5] = printf("%.5-d\n", 0);
	// b[6] = printf("%.- d\n", 0);
	// b[7] = printf("%.-+0# d", 0);
	// b[5] = printf("%.-4d|%.4-d|%.4- d|%.4-+0# d|\n", 0, 0, 0, 0);
	// b[6] = printf("%.-5d|%.5-d|%.- d|%.-+0# d|\n", 1001, 1001, 1001, 1001);
	// b[7] = printf("%.-4d|%.4-d|%.4- d|%.4-+0# d|\n", -1000, -1000, -1000, -1000);
	// b[8] = printf("%.-5d|%.5-d|%.- d|%.-+0# d|\n", 1, 1, 1, 1);
	// b[9] = printf("{%+03d}", 0);
	// b[5] = printf("{%.*d}\n", 0, 42);
	// b[6] = printf("{%.*s}", 0, "42");
	// b[7] = printf("\n{%.d}", 42);
	// b[8] = printf("\n{%.u}", 42);
	// b[9] = printf("\n%.d, %.0d", 0, 0);
	// printf("\nLe fichier \x1b[36m%s\x1b[0m contient : \x1b[31m%s\x1b[0m", "xyz", "ABCDEF");
	n = 9;
	i = -1;
	printf("\n");
	while (++i < n)
		if (a[i] != b[i])
			printf("Test %d FAIL: You %d | Lib %d\n", i, a[i], b[i]);
	return (0);
}
