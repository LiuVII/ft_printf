/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtf_uid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:42:55 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/25 19:42:57 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		ft_wildcard(t_data *d, int num)
{
	if (d->prec == -1)
	{
		d->width = ABS(num);
		d->flag = 1;
		(num < 0) ? (d->farr[2] = 1) : 0;
	}
	else if (d->prec >= 0)
	{
		d->flag = 1;
		d->prec = (num >= 0) ? num : -1;
	}
}

void		ft_put_blanks(int len, t_data *d, int inc, int check)
{
	int	l;

	l = ((d->prec > len) ? d->prec : len) - 1 + inc;
	d->res += (d->width > l + 1) ? d->width - l - 1 : 0;
	while (++l < d->width)
		(check) ? ft_putchar('0') : ft_putchar(' ');
}

static void	ft_swnp(int len, int sign, t_data *d, int inc)
{
	int	l;

	if (sign < 0 && d->farr[1] && ++d->res)
		ft_putchar('-');
	if (sign > 0 && d->farr[1] && (d->farr[3] || d->farr[4]) && ++d->res)
		ft_putchar(32 + 11 * d->farr[4]);
	(!d->farr[2]) ? ft_put_blanks(len, d, inc, d->farr[1]) : 0;
	if (sign < 0 && !d->farr[1] && ++d->res)
		ft_putchar('-');
	if (sign > 0 && !d->farr[1] && (d->farr[3] || d->farr[4]) && ++d->res)
		ft_putchar(32 + 11 * d->farr[4]);
	l = len - 1;
	d->res += (d->prec > l + 1) ? d->prec - l - 1 : 0;
	while (++l < d->prec)
		ft_putchar('0');
}

int			ft_conv_id(t_data *d, va_list ap)
{
	intmax_t	i;
	int			sign;
	int			len;
	int			inc;

	(!d->modn) ? i = (va_arg(ap, int)) : 0;
	(d->modn == 'h') ? i = (short)(va_arg(ap, int)) : 0;
	(d->modn == 2 * 'h') ? i = (char)(va_arg(ap, int)) : 0;
	(d->modn == 'l') ? i = (va_arg(ap, long)) : 0;
	(d->modn == 2 * 'l') ? i = (va_arg(ap, long long)) : 0;
	(d->modn == 'j') ? i = (va_arg(ap, intmax_t)) : 0;
	(d->modn == 'z') ? i = (va_arg(ap, ssize_t)) : 0;
	sign = (i < 0) ? -1 : 1;
	len = 0;
	if (i || d->prec)
		len = ft_numlen((i < 0) ? -i : i);
	inc = (i >= 0 && (d->farr[3] || d->farr[4])) - (sign - 1) / 2;
	ft_swnp(len, sign, d, inc);
	(i || d->prec) ? ft_putulnbr(i * sign) : 0;
	(d->farr[2]) ? ft_put_blanks(len, d, inc, 0) : 0;
	d->res += len;
	return (0);
}

int			ft_conv_cd(t_data *d, va_list ap)
{
	int		len;
	long	lg;
	long	sign;
	int		inc;

	lg = va_arg(ap, long);
	sign = (lg < 0) ? -1 : 1;
	len = (lg || d->prec) ? ft_numlen(lg * sign) : 0;
	inc = (lg >= 0 && (d->farr[3] || d->farr[4])) - (sign - 1) / 2;
	ft_swnp(len, sign, d, inc);
	(lg || d->prec) ? ft_putulnbr(lg * sign) : 0;
	(d->farr[2]) ? ft_put_blanks(len, d, inc, 0) : 0;
	d->res += len;
	return (0);
}
