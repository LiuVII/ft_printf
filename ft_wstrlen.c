/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 09:57:15 by mfilipch          #+#    #+#             */
/*   Updated: 2016/09/22 09:57:17 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_wstrlen(wchar_t *wstr, int l)
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
			(c >= 0x00000080) ? ltmp++ : 0;
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
