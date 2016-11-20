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
	if (argc < 2 && argv[0])
		return (0);
	ft_printf("You:\n");
	// ft_printf("Str %s | Num %%d | Char %c\n", argv[1], atoi(argv[2]), argv[3][0]);
	// ft_printf(":%15s:\n", "Hello, world!");
	// ft_printf(":%.10s:\n", "Hello, world!");
	// ft_printf(":%.15s:\n", "Hello, world!");
	// ft_printf(":%15.10s:\n", "Hello, world!");
	// ft_printf("%5d\n", 42);
	ft_printf("%d", 42);
	ft_printf("%i", 42);
	ft_printf("This is a simple test.");
	ft_printf("%u", -42);
	printf("\nLib:\n");
	// printf("Str %s | Num %%d | Char %c\n", argv[1], atoi(argv[2])/*, argv[3][0]*/);
	// printf(":%15s:\n", "Hello, world!");
	// printf(":%.10s:\n", "Hello, world!");
	// printf(":%.15s:\n", "Hello, world!");
	// printf(":%15.10s:\n", "Hello, world!");
	// printf("%5d\n", 42);
	printf("%d", 42);
	printf("%i", 42);
	printf("This is a simple test.");
	printf("%u", -42);
	return (0);
}
