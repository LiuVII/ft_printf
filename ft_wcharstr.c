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

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

size_t	ft_wputchar(int c)
{
	char	wc[4];
	size_t	flag;

	flag = 0;
	wc[3] = (c >= 0x000000FF && ++flag) ? (128 + c % 64) : c;
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
	write(1, &wc[3 - flag], flag + 1);
	return (flag + 1);
}

size_t	ft_wputstr(wchar_t *ws, int l)
{
	size_t	len;
	int		c;
	int		flag;

	len = 0;
	flag = (l < 0) ? 0 : 1;
	if (ws)
		while (*ws)
		{
			c = *ws;
			l--;
			(c >= 0x000000FF) ? l-- : 0;
			c = c >> 6;
			(c >= 0x00000040) ? l-- : 0;
			c = c >> 6;
			(c >= 0x00000010) ? l-- : 0;
			if (flag && l < 0)
				return (len);
			len += ft_wputchar(*ws++);
		}
	return (len);
}

size_t	ft_wstrlen(wchar_t *wstr, int l)
{
	size_t	len;
	int		c;
	size_t	ltmp;
	int		flag;

	len = 0;
	flag = (l < 0) ? 0 : 1;
	if (wstr)
		while (*wstr)
		{
			ltmp = 1;
			c = *(wstr++);
			(c >= 0x000000FF) ? ltmp++ : 0;
			c = c >> 6;
			(c >= 0x00000040) ? ltmp++ : 0;
			c = c >> 6;
			(c >= 0x00000010) ? ltmp++ : 0;
			l -= ltmp;
			if (flag && l < 0)
				return (len);
			len += ltmp;
		}
	return (len);
}
