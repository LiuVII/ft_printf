/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 10:00:54 by mfilipch          #+#    #+#             */
/*   Updated: 2016/09/25 21:25:15 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

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
			(c >= 0x00000080) ? l-- : 0;
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
