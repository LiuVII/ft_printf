/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtochar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:40:56 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/23 22:40:58 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*ft_wtochar(wchar_t *wstr)
{
	size_t	len;
	int		c;
	int		flag;
	char	*str;

	len = ft_wstrlen(wstr, -1);
	str = (char*)malloc(len + 1);
	str[len] = 0;
	len = 0;
	if (wstr)
		while (*wstr)
		{
			c = *wstr++;
			flag = ft_wstrlen(&c, -1);
			str[len + flag - 1] = (flag >= 2) ? (128 + c % 64) : c;
			if (flag >= 2)
			{
				c = c >> 6;
				str[len + flag - 2] = (flag >= 3) ? ((128 + c % 64)) : (192 + c % 32);
			}
			if (flag >= 3)
			{
				c = c >> 6;
				str[len + flag - 3] = (flag >= 4) ? ((128 + c % 64)) : (224 + c);
			}
			if (flag >= 4)
			{
				c = c >> 6;
				str[len + flag - 4] = (240 + c);
			}
			len += flag;
		}
	return (str);
}
