/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 09:05:19 by exam              #+#    #+#             */
/*   Updated: 2016/10/18 09:33:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_ultoa_base(unsigned long value, unsigned int base, int lc)
{
	const char		*basestr[2] = {"0123456789ABCDEF", "0123456789abcdef"};
	unsigned long	num;
	char			*str;
	int				i;

	i = 1;
	(lc != 0) ? (lc = 1) : 0;
	num = value;
	while ((num /= base) >= 1)
		i++;
	str = (char*)malloc(i + 1);
	str[i] = '\0';
	num = value;
	while (i--)
	{
		str[i] = basestr[lc][(num % base)];
		num /= base;
	}
	return (str);
}
