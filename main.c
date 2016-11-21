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

int	ft_printf(const char *fmt, ...);

int main(int argc, char const **argv)
{
	int a[10];
	int	b[10];
	int	n;
	int	i;

	if (argc < 2 && argv[0])
		return (0);
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
	a[0] = ft_printf("%.4d", 42);
	a[1] = ft_printf("%.4d", 424242);
	a[2] = ft_printf("%4.15d\n", 42);
	a[3] = ft_printf("%15.4d\n", 42);
	a[4] = ft_printf("%4.15d\n", -42);
	a[5] = ft_printf("%15.4d\n", -42);
	// a[1] = ft_printf("%.4s", "42");
	// a[2] = ft_printf("%4.15s", "42 is the answer");
	// a[3] = ft_printf("%4.s", "42");
	ft_printf("\n");
	// a[0] = ft_printf("%d", 42);
	// a[1] = ft_printf("%i", 42);
	// a[2] = ft_printf("This is a simple test.");
	// a[3] = ft_printf("%u", -42);
	// printf("\nLib:\n");
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
	b[0] = printf("%.4d", 42);
	b[1] = printf("%.4d", 424242);
	b[2] = printf("%4.15d\n", 42);
	b[3] = printf("%15.4d\n", 42);
	b[4] = printf("%4.15d\n", -42);
	b[5] = printf("%15.4d\n", -42);
	// b[0] = printf("%d", 42);
	// b[1] = printf("%i", 42);
	// b[2] = printf("This is a simple test.");
	// b[3] = printf("%u", -42);
	n = 6;
	i = -1;
	printf("\n");
	while (++i < n)
		if (a[i] != b[i])
			printf("Test %d FAIL: You %d | Lib %d\n", i, a[i], b[i]);
	return (0);
}
