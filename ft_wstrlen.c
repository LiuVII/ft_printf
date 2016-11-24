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

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t	len;
	int		c;

	len = 0;
	// printf("%S ", wstr);
	if (wstr)
		while (*wstr)
		{
			c = *(wstr++);
			len++;
			(c >= 0x00000080) ? len++ : 0;
			c = c >> 6;
			(c >= 0x00000040)?  len++ : 0;
			c = c >> 6;
			(c >= 0x00000010) ? len++ : 0;
		}
	// printf("%zu\n", len);
	return (len);
}
