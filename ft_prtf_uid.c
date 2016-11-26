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

int		ft_conv_id(t_data *d, va_list ap)
{
	intmax_t	i;
	intmax_t	sign;
	int			len;
	int			l;

	// if (!d->mnum || d->mnum == 'h' || d->mnum == 2 * 'h')
	// 	i = (va_arg(ap, int));
	(!d->mnum) ? i = (va_arg(ap, int)) : 0;
	(d->mnum == 'h') ? i = (short)(va_arg(ap, int)) : 0;
	(d->mnum == 2 * 'h') ? i = (char)(va_arg(ap, int)) : 0;
	(d->mnum == 'l') ? i = (va_arg(ap, long)) : 0;
	(d->mnum == 2 * 'l') ? i = (va_arg(ap, long long)) : 0;
	(d->mnum == 'j') ? i = (va_arg(ap, intmax_t)) : 0;
	(d->mnum == 'z') ? i = (va_arg(ap, ssize_t)) : 0;
	sign = (i < 0) ? -1 : 1; 
	len = ft_numlen(i * sign) + (i >= 0 && (d->farr[3] || d->farr[4]));;
	(sign < 0 && d->farr[1]) ? ft_putchar('-') : 0;
	(i >= 0 && d->farr[1] && (d->farr[3] || d->farr[4])) ? ft_putchar(32 + 11 * d->farr[4]) : 0;
	if (!d->farr[2])
	{
		l = ((d->prec > len) ? d->prec : len) - 1 - (sign - 1) / 2;
		while (++l < d->width)
			(d->farr[1]) ? ft_putchar('0') : ft_putchar(' ');
	}
	(sign < 0 && !d->farr[1]) ? ft_putchar('-') : 0;
	(i >= 0 && !d->farr[1] && (d->farr[3] || d->farr[4])) ? ft_putchar(32 + 11 * d->farr[4]) : 0;
	l = len - 1;
	while (++l < d->prec)
		ft_putchar('0');
	ft_putulnbr(i * sign);
	if (d->farr[2])
	{
		l = ((d->prec > len) ? d->prec : len) - 1 - (sign - 1) / 2;
		while (++l < d->width)
			ft_putchar(' ');
	}
	d->res += len - (sign - 1) / 2 + ((d->width > len  && d->width >= d->prec) ? (d->width - len + (sign - 1) / 2) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
	return (0);
}

int		ft_conv_cd(t_data *d, va_list ap)
{
	int		len;
	int		l;
	long	lg;
	long	sign;

	lg = va_arg(ap, long);
	sign = (lg < 0) ? -1 : 1; 
	len = ft_numlen(lg * sign) + (lg >= 0 && (d->farr[3] || d->farr[4]));
	l = ((d->prec > len) ? d->prec : len) - 1 - (sign - 1) / 2;
	(sign < 0 && d->farr[1]) ? ft_putchar('-') : 0;
	(lg >= 0 && d->farr[1] && (d->farr[3] || d->farr[4])) ? ft_putchar(32 + 11 * d->farr[4]) : 0;
	while (++l < d->width)
		(d->farr[1]) ? ft_putchar('0') : ft_putchar(' ');
	(sign < 0 && !d->farr[1]) ? ft_putchar('-') : 0;
	(lg >= 0 && !d->farr[1] && (d->farr[3] || d->farr[4])) ? ft_putchar(32 + 11 * d->farr[4]) : 0;
	l = len - 1;
	while (++l < d->prec)
		ft_putchar('0');
	ft_putulnbr(lg * sign);
	d->res += len - (sign - 1) / 2 + ((d->width > len  && d->width >= d->prec) ? (d->width - len + (sign - 1) / 2) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
	return (0);
}

int		ft_conv_u(t_data *d, va_list ap)
{
	int				len;
	unsigned int	ud;
	int				l;

	ud = va_arg(ap, unsigned int);
	len = ft_numlen(ud);
	l = ((d->prec > len) ? d->prec : len) - 1;
	while (++l < d->width)
		(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
	l = len - 1;
	while (++l < d->prec)
		ft_putchar('0');
	ft_putulnbr(ud);
	d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
	return (0);
}

int		ft_conv_cu(t_data *d, va_list ap)
{
	int				len;
	int				l;
	unsigned long	ulg;

	ulg = va_arg(ap, unsigned long);
	len = ft_numlen(ulg);
	l = ((d->prec > len) ? d->prec : len) - 1;
	while (++l < d->width)
		(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
	l = len - 1;
	while (++l < d->prec)
		ft_putchar('0');
	ft_putulnbr(ulg);
	d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
	return (0);
}

