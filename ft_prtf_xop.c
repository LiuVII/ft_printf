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

static int	ft_wnp(int len, char *str, t_data *d, int nonz)
{
	int	inc;
	int	l;

	inc = (nonz && d->farr[0]) ? ft_strlen(str) : 0;
	if (d->farr[1] && inc && (d->res += inc))
		ft_putstr(str);
	(d->farr[2]) ? 0 : ft_put_blanks(len, d, inc, d->farr[1]);
	l = len - 1;
	if (!d->farr[1] && inc && (d->res += inc))
		ft_putstr(str);
	d->res += (d->prec > l + 1) ? d->prec - l - 1 : 0;
	while (++l < d->prec)
		ft_putchar('0');
	return (inc);
}

int			ft_conv_p(t_data *d, va_list ap)
{
	char			*s;
	int				len;
	unsigned long	ud;
	int				inc;

	d->farr[0] = 1;
	ud = va_arg(ap, unsigned long);
	s = ft_ultoa_base(ud, 16, 1);
	len = (ud > 0 || d->prec) ? ft_strlen(s) : 0;
	inc = ft_wnp(len, "0x", d, 1);
	(ud > 0 || d->prec) ? ft_putstr(s) : 0;
	free(s);
	(d->farr[2]) ? ft_put_blanks(len, d, inc, 0) : 0;
	d->res += len;
	return (0);
}

int			ft_conv_xcxou(t_data *d, va_list ap, int cs, int base)
{
	char			*s;
	int				len;
	uintmax_t		ud;
	int				inc;

	(!d->modn) ? ud = (va_arg(ap, unsigned int)) : 0;
	(d->modn == 'h') ? ud = (unsigned short)(va_arg(ap, unsigned int)) : 0;
	(d->modn == 2 * 'h') ? ud = (unsigned char)(va_arg(ap, unsigned int)) : 0;
	(d->modn == 'l') ? ud = (va_arg(ap, unsigned long)) : 0;
	(d->modn == 2 * 'l') ? ud = (va_arg(ap, unsigned long long)) : 0;
	(d->modn == 'j') ? ud = (va_arg(ap, uintmax_t)) : 0;
	(d->modn == 'z') ? ud = (va_arg(ap, size_t)) : 0;
	s = ft_ultoa_base(ud, base, cs);
	len = (ud > 0 || d->prec || (base == 8 && d->farr[0])) ? ft_strlen(s) : 0;
	if (base == 16)
		inc = ft_wnp(len, (cs == 1) ? "0x" : "0X", d, (ud > 0));
	else if (base == 8)
		inc = ft_wnp(len, (d->prec > len) ? "" : "0", d, (ud > 0));
	else if (base == 10)
		inc = ft_wnp(len, "", d, (ud > 0));
	(ud > 0 || d->prec || (base == 8 && d->farr[0])) ? ft_putstr(s) : 0;
	free(s);
	(d->farr[2]) ? ft_put_blanks(len, d, inc, 0) : 0;
	d->res += len;
	return (0);
}

int			ft_conv_co(t_data *d, va_list ap)
{
	char			*s;
	int				len;
	int				inc;
	unsigned long	ulg;

	ulg = (va_arg(ap, unsigned long));
	s = ft_ultoa_base(ulg, 8, 0);
	len = (ulg > 0 || d->prec || d->farr[0]) ? ft_strlen(s) : 0;
	inc = ft_wnp(len, (d->prec > 0 && d->farr[0]) ? "" : "0", d, (ulg > 0));
	(ulg > 0 || d->prec || d->farr[0]) ? ft_putstr(s) : 0;
	free(s);
	(d->farr[2]) ? ft_put_blanks(len, d, inc, 0) : 0;
	d->res += len;
	return (0);
}

int			ft_conv_cu(t_data *d, va_list ap)
{
	char			*s;
	int				len;
	int				inc;
	unsigned long	ulg;

	ulg = (va_arg(ap, unsigned long));
	s = ft_ultoa_base(ulg, 10, 0);
	len = (ulg > 0 || d->prec) ? ft_strlen(s) : 0;
	inc = ft_wnp(len, "", d, (ulg > 0));
	(ulg > 0 || d->prec) ? ft_putstr(s) : 0;
	free(s);
	(d->farr[2]) ? ft_put_blanks(len, d, inc, 0) : 0;
	d->res += len;
	return (0);
}
