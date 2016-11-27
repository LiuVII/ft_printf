/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:41:33 by mfilipch          #+#    #+#             */
/*   Updated: 2016/09/22 22:41:35 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static void	ft_recput(unsigned long long n)
{
	if (n >= 10)
		ft_recput(n / 10);
	ft_putchar(n % 10 + '0');
}

void		ft_putulnbr(unsigned long long n)
{
	if (n > 18446744073709551614ul)
	{
		ft_putstr("18446744073709551615");
		return ;
	}
	ft_recput(n);
}
