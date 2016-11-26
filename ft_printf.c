/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 00:00:12 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/20 00:00:14 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	ft_reset_data(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 5)
		d->farr[i] = 0;
	d->width = 0;
	d->prec = -1;
	d->flag = 0;

}

int			ft_printf(const char *fmt, ...)
{
	va_list 		ap;
	t_data			*d;

	d = (t_data*)malloc(sizeof(t_data));
	va_start(ap, fmt);
	d->res = 0;
	ft_reset_data(d);
	if (!fmt)
		return (-1);
	while (*fmt)
	{
		if (d->width > 0 || d->prec >= 0 || d->flag || (*fmt == '%' && *(fmt++)))
		{
			if (*fmt == 's')
				ft_conv_s(d, ap);
			else if (*fmt == 'S' || (ft_strncmp(fmt, "ls", 2) == 0 && fmt++))
				ft_conv_cs(d, ap);
			else if (*fmt == 'd' || *fmt == 'i')
				ft_conv_id(d, ap);
			else if (*fmt == 'C' || (ft_strncmp(fmt, "lc", 2) == 0 && fmt++))
				ft_conv_cc(d, ap);
			else if (*fmt == 'o')
				ft_conv_o(d, ap);
			else if (*fmt == 'u')
				ft_conv_u(d, ap);
			else if (*fmt == 'D' || ((ft_strncmp(fmt, "ld", 2) == 0
				|| ft_strncmp(fmt, "li", 2) == 0) && fmt++))
				ft_conv_cd(d, ap);
			else if (*fmt == 'O' || ((ft_strncmp(fmt, "lo", 2) == 0
				|| ft_strncmp(fmt, "lO", 2) == 0) && fmt++))
				ft_conv_co(d, ap);
			else if (*fmt == 'U' || ((ft_strncmp(fmt, "lu", 2) == 0
				|| ft_strncmp(fmt, "lU", 2) == 0 || ft_strncmp(fmt, "lD", 2) == 0) && fmt++))
				ft_conv_cu(d, ap);
			else if (*fmt == 'x' || (ft_strncmp(fmt, "lx", 2) == 0 && fmt++))
				ft_conv_x(d, ap);
			else if (*fmt == 'X' || (ft_strncmp(fmt, "lX", 2) == 0 && fmt++))
				ft_conv_cx(d, ap);
			else if (*fmt == 'p' || (ft_strncmp(fmt, "lp", 2) == 0 && fmt++))
				ft_conv_p(d, ap);
			else if ((*fmt == '#' && (d->flag = 1)) || (*fmt == '0' && (d->flag = 2)) || (*fmt == '-' && (d->flag = 3))
				|| (*fmt == ' ' && (d->flag = 4)) || (*fmt == '+' && (d->flag = 5)))
			{
				if (d->farr[d->flag - 1] == 0)
					d->farr[d->flag - 1] = 1;
				else
					return (-1);
				if (d->farr[4] == 1)
					d->farr[3] = 0;
			}
			else if (d->prec == -1 && *fmt == '.')
			{
				d->prec = ft_atoi(fmt + 1);
				if (d->prec > 0 || *(fmt + 1) == '0')
					fmt += strlen(ft_itoa(d->prec));
			}
			else if (d->prec == -1 && ft_isdigit(*fmt) && (d->width = ft_atoi(fmt)))
				fmt += strlen(ft_itoa(d->width)) - 1;
			else if (*fmt)
				ft_conv_c(*fmt, d, ap);
		}
		else
		{
			ft_putchar(*fmt);
			d->res++;
		}
		(*fmt) ? fmt++ : 0;
	}
	free(d);
	va_end(ap);
	return (d->res);
}
