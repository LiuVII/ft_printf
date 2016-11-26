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
	else
	{
		ft_putstr("(null)");
		d->res += 6;
	}
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
	// printf("int wc: %d\n", (int)wc);
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
	// int		len;
	int		l;
	// char	c;

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
