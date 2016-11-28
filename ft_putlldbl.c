/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlldbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:15:57 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/27 17:15:59 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

long double	ft_round(long double n, int prec)
{
	long double inc;
	long double	tmp;

	prec++;
	inc = 1;
	tmp = n - (long long)n;
	while (prec--)
	{
		tmp *= 10;
		inc /= 10;
	}
	tmp = ABS((long long)tmp % 10);
	if (ABS(tmp) >= 5)
		inc *= (10 - tmp);
	else
		inc *= -tmp;
	return (n + inc);
}

void		ft_putlldbl(long double n, int prec)
{
	long long	ival;

	ival = n;
	ft_putulnbr(ival);
	n = ft_round(n - ival, prec);
	if (prec)
		ft_putchar('.');
	while (prec--)
	{
		n = n * 10.0;
		ft_putchar((long long)n % 10 + '0');
	}
}
