/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtf_xop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:24:56 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/25 19:25:10 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_p(t_data *d, va_list ap)
{
	char			*s;
	int				len;
	int				l;
	unsigned long	ulg;

	(d->prec >= 0) ? d->farr[1] = 0 : 0;
	if (d->prec)
	{
		ulg = va_arg(ap, unsigned long);
		s = ft_ultoa_base(ulg, 16, 1);
		len = ft_strlen(s);
		(d->farr[1] && (d->res += 2)) ? ft_putstr("0x") : 0;
		if (!d->farr[2])
		{
			l = ((d->prec > len) ? d->prec : len) + 1;
			while (++l < d->width && ++(d->res))
				(d->farr[1]) ? ft_putchar('0') : ft_putchar(' ');
		}
		l = len - 1;
		(!d->farr[1] && (d->res += 2)) ? ft_putstr("0x") : 0;
		while (++l < d->prec && ++(d->res))
			ft_putchar('0');
		ft_putstr(s);
		free(s);
		if (d->farr[2])
		{
			l = ((d->prec > len) ? d->prec : len) + 1;
			while (++l < d->width && ++(d->res))
				ft_putchar(' ');
		}
		d->res += len;
		// d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
	}
	else if ((d->res += 2))
		ft_putstr("0x");
	ft_reset_data(d);
	return (0);
}

int		ft_conv_x(t_data *d, va_list ap)
{
	char			*s;
	int				len;
	int				l;
	unsigned long	ulg;

	(d->prec >= 0) ? d->farr[1] = 0 : 0;
	if (d->prec)
	{
		ulg = va_arg(ap, unsigned long);
		s = ft_ultoa_base(ulg, 16, 1);
		len = ft_strlen(s);
		(d->farr[1] && ulg > 0 && d->farr[0] && (d->res += 2)) ? ft_putstr("0x") : 0;
		if (!d->farr[2])
		{
			l = ((d->prec > len) ? d->prec : len) - 1;
			while (++l < d->width && ++(d->res))
				(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
		}
		l = len - 1;
		(!d->farr[1] && ulg > 0 && d->farr[0] && (d->res += 2)) ? ft_putstr("0x") : 0;
		while (++l < d->prec && ++(d->res))
			ft_putchar('0');
		ft_putstr(s);
		free(s);
		if (d->farr[2])
		{
			l = ((d->prec > len) ? d->prec : len) - 1;
			while (++l < d->width && ++(d->res))
				ft_putchar(' ');
		}
		d->res += len;
		// d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
	}
	ft_reset_data(d);
	return (0);
}

int		ft_conv_cx(t_data *d, va_list ap)
{
	char			*s;
	int				len;
	int				l;
	unsigned long	ulg;

	(d->prec >= 0) ? d->farr[1] = 0 : 0;
	if (d->prec)
	{
		ulg = va_arg(ap, unsigned long);
		s = ft_ultoa_base(ulg, 16, 0);
		len = ft_strlen(s);
		(d->farr[1] && ulg > 0 && d->farr[0] && (d->res += 2)) ? ft_putstr("0X") : 0;
		if (!d->farr[2])
		{
			l = ((d->prec > len) ? d->prec : len) - 1;
			while (++l < d->width && ++(d->res))
				(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
		}
		l = len - 1;
		(!d->farr[1] && ulg > 0 && d->farr[0] && (d->res += 2)) ? ft_putstr("0X") : 0;
		while (++l < d->prec && ++(d->res))
			ft_putchar('0');
		ft_putstr(s);
		free(s);
		if (d->farr[2])
		{
			l = ((d->prec > len) ? d->prec : len) - 1;
			while (++l < d->width && ++(d->res))
				ft_putchar(' ');
		}
		d->res += len;
		// d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
	}
	ft_reset_data(d);
	return (0);
}

int		ft_conv_o(t_data *d, va_list ap)
{
	char			*s;
	int				len;
	int				l;
	unsigned int	ud;

	(d->prec >= 0) ? d->farr[1] = 0 : 0;
	if (d->prec)
	{
		ud = va_arg(ap, unsigned int);
		s = ft_ultoa_base(ud, 8, 0);
		len = ft_strlen(s) + (ud > 0 && d->farr[0]);
		l = ((d->prec > len) ? d->prec : len) - 1;
		while (++l < d->width)
			(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
		l = len - 1;
		(ud > 0 && d->farr[0]) ? ft_putchar('0') : 0;
		while (++l < d->prec)
			ft_putchar('0');
		ft_putstr(s);
		free(s);
		d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
	}
	else if (d->flag && ++(d->res))
		ft_putstr("0");
	ft_reset_data(d);
	return (0);
}

int		ft_conv_co(t_data *d, va_list ap)
{
	char			*s;
	int				len;
	int				l;
	unsigned long	ulg;

	(d->prec >= 0) ? d->farr[1] = 0 : 0;
	if (d->prec)
	{
		ulg = va_arg(ap, unsigned long);
		s = ft_ultoa_base(ulg, 8, 0);
		len = ft_strlen(s) + (ulg > 0 && d->farr[0]);
		l = ((d->prec > len) ? d->prec : len) - 1;
		while (++l < d->width)
			(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
		l = len - 1;
		(ulg > 0 && d->farr[0]) ? ft_putchar('0') : 0;
		while (++l < d->prec)
			ft_putchar('0');
		ft_putstr(s);
		free(s);
		d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
	}
	else if (d->flag && ++(d->res))
		ft_putstr("0");
	ft_reset_data(d);
	return (0);
}
