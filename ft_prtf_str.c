/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtf_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:54:07 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/25 18:54:09 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_conv_f(t_data *d, va_list ap)
{
	int		len;
	double	n;
	int		sign;
	int		inc;

	n = va_arg(ap, double);
	sign = (n < 0) ? -1 : 1;
	len = (n || d->prec) ? (ft_numlen((double)sign * n) + (d->prec != 0)) : 0;
	inc = (n >= 0 && (d->farr[3] || d->farr[4])) - (sign - 1) / 2;
	(d->prec < 0 && n) ? (d->prec = 6) : 0;
	(d->prec >= 0) ? len += d->prec : 0;
	(sign < 0 && d->farr[1] && ++d->res) ? ft_putchar('-') : 0;
	if (sign > 0 && d->farr[1] && (d->farr[3] || d->farr[4]) && ++d->res)
		ft_putchar(32 + 11 * d->farr[4]);
	(!d->farr[2]) ? ft_put_blanks(len, d, inc, d->farr[1]) : 0;
	if (sign < 0 && !d->farr[1] && ++d->res)
		ft_putchar('-');
	if (sign > 0 && !d->farr[1] && (d->farr[3] || d->farr[4]) && ++d->res)
		ft_putchar(32 + 11 * d->farr[4]);
	d->res += (d->prec > len) ? d->prec - len : 0;
	if (len)
		ft_putlldbl((n >= 0) ? n : -n, d->prec);
	(d->farr[2]) ? ft_put_blanks(len, d, inc, 0) : 0;
	d->res += len;
	return (0);
}

int		ft_conv_s(t_data *d, va_list ap)
{
	char	*s;
	int		len;
	int		l;

	if ((s = va_arg(ap, char *)) || d->farr[1])
	{
		len = ft_strlen(s);
		len = (d->prec >= 0 && d->prec < len) ? d->prec : len;
		l = len - 1;
		if (!d->farr[2])
			while (++l < d->width)
				(d->farr[1]) ? ft_putchar('0') : ft_putchar(' ');
		write(1, s, len);
		if (d->farr[2])
			while (++l < d->width)
				ft_putchar(' ');
		d->res += len + ((d->width > len) ? (d->width - len) : 0);
	}
	else
	{
		ft_putstr("(null)");
		d->res += 6;
	}
	ft_reset_data(d);
	return (0);
}

int		ft_conv_cs(t_data *d, va_list ap)
{
	wchar_t	*ws;
	int		len;
	int		l;

	if ((ws = va_arg(ap, wchar_t *)))
	{
		len = ft_wstrlen(ws, -1);
		len = (d->prec >= 0 && d->prec < len) ? d->prec : len;
		len = ft_wstrlen(ws, len);
		l = len - 1;
		if (!d->farr[2])
			while (++l < d->width)
				(d->farr[1]) ? ft_putchar('0') : ft_putchar(' ');
		ft_wputstr(ws, len);
		if (d->farr[2])
			while (++l < d->width)
				ft_putchar(' ');
		d->res += len + ((d->width > len) ? (d->width - len) : 0);
	}
	else if ((d->res += 6))
		ft_putstr("(null)");
	ft_reset_data(d);
	return (0);
}

int		ft_conv_cc(t_data *d, va_list ap)
{
	int		len;
	int		l;
	wchar_t	wc;

	l = 0;
	if (!d->farr[2])
		while (++l < d->width)
			(d->farr[1]) ? ft_putchar('0') : ft_putchar(' ');
	wc = (wchar_t)va_arg(ap, int);
	len = ft_wputchar(wc);
	if (d->farr[2])
		while (++l < d->width)
			ft_putchar(' ');
	d->res += (d->width > len) ? d->width : len;
	ft_reset_data(d);
	return (0);
}

int		ft_conv_c(char fmt, t_data *d, va_list ap)
{
	int		l;

	l = 0;
	if (!d->farr[2])
		while (++l < d->width)
			(d->farr[1]) ? ft_putchar('0') : ft_putchar(' ');
	(fmt == 'c') ? ft_putchar((char)va_arg(ap, int)) : ft_putchar(fmt);
	if (d->farr[2])
		while (++l < d->width)
			ft_putchar(' ');
	d->res += (d->width > 1) ? d->width : 1;
	ft_reset_data(d);
	return (0);
}
