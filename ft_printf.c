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

void		ft_reset_data(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 5)
		d->farr[i] = 0;
	d->width = 0;
	d->prec = -1;
	d->flag = 0;
	d->modn = 0;
}

static int	ft_check_flags(t_data *d, const char *fmt, int sh)
{
	if ((*fmt == '#' && (d->flag = 1))
		|| (*fmt == '0' && (d->flag = 2))
		|| (*fmt == '-' && (d->flag = 3))
		|| (*fmt == ' ' && (d->flag = 4))
		|| (*fmt == '+' && (d->flag = 5)))
	{
		// printf("flags TEST %s| fl %d\n", fmt, flag);
		if (d->farr[d->flag - 1] == 0)
			d->farr[d->flag - 1] = 1;
		(d->farr[4] == 1) ? (d->farr[3] = 0) : 0;
		sh = 0;
	}
	else if ((*fmt == 'l' || *fmt == 'j' || *fmt == 'z' || *fmt == 'h' ||
	((!ft_strncmp(fmt, "hh", 2) || !ft_strncmp(fmt, "ll", 2)) && ++sh))
		&& (d->modn += (int)(*fmt) * (sh + 2)))
		sh++;
	else if (d->prec == -1 && *fmt == '.')
	{
		sh = 0;
		d->prec = ft_atoi(fmt + 1);
		// printf("prec TEST %s| prec %d\n", fmt, d->prec);
		if (d->prec < 0)
		{
			// sh += ft_numlen(-(d->prec)) + 1;
			d->prec = 0;
		}
		if (d->prec > 0 || *(fmt + 1) == '0')
			sh += ft_numlen(d->prec);
	}
	// else if (d->prec == -1 && ft_isdigit(*fmt) && (d->width = ft_atoi(fmt)))
	// 	sh = ft_numlen(d->width) - 1;
	else if (ft_isdigit(*fmt) && (d->width = ft_atoi(fmt)))
		sh = ft_numlen(d->width) - 1;
	return (sh);
}

static int	ft_check_num(t_data *d, const char *fmt, va_list *ap, int sh)
{
	if (d->prec >= 0 && (d->tmp = d->farr[1] + 1))
		d->farr[1] = 0;
	if ((*fmt == 'd' || *fmt == 'i') && sh++)
		ft_conv_id(d, *ap);
	else if (*fmt == 'D' && sh++)
		ft_conv_cd(d, *ap);
	else if (*fmt == 'U' && sh++)
		ft_conv_cu(d, *ap);
	else if (*fmt == 'O' && sh++)
		ft_conv_co(d, *ap);
	else if ((*fmt == 'f' || *fmt == 'F') && sh++)
		ft_conv_f(d, *ap);
	else if ((*fmt == 'x' || *fmt == 'X' || *fmt == 'o' || *fmt == 'u') && sh++)
	{
		if (*fmt != 'o')
			ft_conv_xcxou(d, *ap, (*fmt == 'x'), (*fmt == 'u') ? 10 : 16);
		else
			ft_conv_xcxou(d, *ap, 0, 8);
	}
	else if (*fmt == 'p' && sh++)
		ft_conv_p(d, *ap);
	(sh >= 0) ? ft_reset_data(d) : (d->prec >= 0 && (d->farr[1] = d->tmp - 1));
	return (sh);
}

static int	ft_prtf_loop(t_data *d, const char *fmt, va_list *ap, int sh)
{
	while (*fmt)
	{
		if (d->width > 0 || d->prec >= 0 || d->flag
			|| d->modn || (*fmt == '%' && *fmt++))
		{
			if (*fmt == 's')
				ft_conv_s(d, *ap);
			else if (*fmt == 'S' || (!ft_strncmp(fmt, "ls", 2) && fmt++))
				ft_conv_cs(d, *ap);
			else if (*fmt == 'C' || (!ft_strncmp(fmt, "lc", 2) && fmt++))
				ft_conv_cc(d, *ap);
			else if ((sh = ft_check_num(d, fmt, ap, -1)) >= 0 ||
				(sh = ft_check_flags(d, fmt, -1)) >= 0)
			{
				// printf("fnn TEST %s\n", fmt);
				fmt += sh;
			}
			else if (*fmt == '*')
				ft_wildcard(d, va_arg(*ap, int));
			else if (*fmt)
				ft_conv_c(*fmt, d, *ap);
		}
		else if (++(d->res))
			ft_putchar(*fmt);
		(*fmt) ? fmt++ : 0;
	}
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_data	*d;

	d = (t_data*)malloc(sizeof(t_data));
	va_start(ap, fmt);
	d->res = 0;
	ft_reset_data(d);
	if (!fmt)
		return (-1);
	ft_prtf_loop(d, fmt, &ap, 0);
	free(d);
	va_end(ap);
	return (d->res);
}
