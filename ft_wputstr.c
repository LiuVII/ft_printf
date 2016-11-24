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

size_t	ft_wputstr(wchar_t *s)
{
	size_t len;

	len = 0;
	if (s)
		while (*s)
			len += ft_wputchar(*s++);
	return (len);
}
