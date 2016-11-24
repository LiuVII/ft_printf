/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 09:59:08 by mfilipch          #+#    #+#             */
/*   Updated: 2016/09/22 10:00:38 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include <locale.h>

size_t	ft_wputchar(int c)
{
	// int	wc;
	char	wc[4];
	// char happy[] = { 0xe2, 0x98, 0xba };
	size_t	flag;
	// wchar_t			wc;
	
	// printf("c: %d", c);
	// setlocale(LC_ALL, "");
	flag = 0;
	wc[3] = (c >= 0x00000080 && ++flag) ? (128 + c % 64) : c;
	if (flag == 1)
	{
		c = c >> 6;
		wc[2] = (c >= 0x00000040 && ++flag) ? ((128 + c % 64)) : (192 + c % 32);
	}
	if (flag == 2)
	{
		c = c >> 6;
		wc[1] = (c >= 0x00000010 && ++flag) ? ((128 + c % 64)) : (224 + c);
	}
	if (flag == 3)
	{
		c = c >> 6;
		wc[0] = (240 + c);
	}
	// wc = c;
	// if (c >= 0x00000080 && c < 0x000007FF)
	// {
	// 	wc[0] = 128 + (c) % 64;
	// 	c = c >> 6;
	// 	wc[1] = (192 + c) << 8;
	// 	flag = 1;
	// }
	// else if (c >= 0x000007FF && c < 0x0000FFFF)
	// {
	// 	wc = 128 + c % 64;
	// 	c = c >> 6;
	// 	wc += (128 + c % 64) << 8;
	// 	c = c >> 6;
	// 	wc = (224 + c) << 16;
	// 	flag = 2;
	// }
	// else if (c >= 0x0000FFFF && c < 0x001FFFFF)
	// {
	// 	wc = 128 + c % 64;
	// 	c = c >> 6;
	// 	wc += (128 + c % 64) << 8;
	// 	c = c >> 6;
	// 	wc += (128 + c % 64) << 16;
	// 	c = c >> 6;
	// 	wc = (240 + c) << 24;
	// 	flag = 3;
	// }	
	// printf("wc: %d\n", wc);
	write(1, &wc[3 - flag], flag + 1);
	return (flag + 1);
	// write(1, "\n", 1);
	// write(1, happy, 3);
}
