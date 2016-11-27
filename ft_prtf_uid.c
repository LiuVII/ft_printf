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

void		ft_put_blanks(int len, t_data *d, int inc, int check)
{
	int	l;

	l = ((d->prec > len) ? d->prec : len) - 1 + inc;
	d->res += (d->width > l + 1) ? d->width - l - 1 : 0;
	while (++l < d->width)
		(check) ? ft_putchar('0') : ft_putchar(' ');
}

static void	ft_swnp(int len, int sign, t_data *d)
{
	int	l;

	if (sign < 0 && d->farr[1] && ++d->res)
		ft_putchar('-');
	if (sign > 0 && d->farr[1] && (d->farr[3] || d->farr[4]))
		ft_putchar(32 + 11 * d->farr[4]);
	(!d->farr[2]) ? ft_put_blanks(len, d, -(sign - 1) / 2, d->farr[1]) : 0;
	if (sign < 0 && !d->farr[1] && ++d->res)
		ft_putchar('-');
	if (sign > 0 && !d->farr[1] && (d->farr[3] || d->farr[4]))
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

	(!d->modn) ? i = (va_arg(ap, int)) : 0;
	(d->modn == 'h') ? i = (short)(va_arg(ap, int)) : 0;
	(d->modn == 2 * 'h') ? i = (char)(va_arg(ap, int)) : 0;
	(d->modn == 'l') ? i = (va_arg(ap, long)) : 0;
	(d->modn == 2 * 'l') ? i = (va_arg(ap, long long)) : 0;
	(d->modn == 'j') ? i = (va_arg(ap, intmax_t)) : 0;
	(d->modn == 'z') ? i = (va_arg(ap, ssize_t)) : 0;
	sign = (i < 0) ? -1 : 1;
	len = ft_numlen((i < 0) ? -i : i) + (i >= 0 && (d->farr[3] || d->farr[4]));
	ft_swnp(len, sign, d);
	ft_putulnbr(i * sign);
	(d->farr[2]) ? ft_put_blanks(len, d, -(sign - 1) / 2, 0) : 0;
	d->res += len;
	return (0);
}

int			ft_conv_cd(t_data *d, va_list ap)
{
	int		len;
	long	lg;
	int		sign;

	lg = va_arg(ap, long);
	sign = (lg < 0) ? -1 : 1;
	len = ft_numlen((lg < 0) ? -lg : lg)
	+ (lg >= 0 && (d->farr[3] || d->farr[4]));
	ft_swnp(len, sign, d);
	ft_putulnbr(lg * sign);
	(d->farr[2]) ? ft_put_blanks(len, d, -(sign - 1) / 2, 0) : 0;
	d->res += len;
	return (0);
}
