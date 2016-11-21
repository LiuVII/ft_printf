/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 00:28:48 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/21 00:28:49 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_numlen(unsigned long long n)
{
	unsigned long long	num;
	int	len;

	len = 1;
	num = n;
	while ((num /= 10) >= 1)
		len++;
	return (len);
}