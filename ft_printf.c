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

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>


static	void	ft_reset_data(t_data *d)
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
	// int				width;
	// int				prec;
	int				l;
	int				len;
	int				i;
	unsigned int	ud;
	long			lg;
	unsigned long	ulg;
	long			sign;
	char			*s;
	// char			c;
	wchar_t			wc;
	wchar_t			*ws;
	t_data			*d;
	// int				res;
	// int				d->farr[5];
	// int				flag;

	d = (t_data*)malloc(sizeof(t_data));
	va_start(ap, fmt);
	d->res = 0;
	ft_reset_data(d);
	// ft_putnbr(d->prec);
	if (!fmt)
		return (-1);
	while (*fmt)
	{
		if (d->width > 0 || d->prec >= 0 || d->flag || (*fmt == '%' && *(fmt++)))
		{
			if (*fmt == 's')
			{
				// write(1,"TEST2\n", 6);
				if ((s = va_arg(ap, char *)) || d->farr[1])
				{
					len = ft_strlen(s);
					len = (d->prec >= 0 && d->prec < len) ? d->prec : len;
					l = len - 1;
					while (++l < d->width)
						(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
					write(1, s, len);
					d->res += len + ((d->width > len) ? (d->width - len) : 0);
				}
				else
				{
					ft_putstr("(null)");
					d->res += 6;
				}
				ft_reset_data(d);
			}
			else if (*fmt == 'S' || (ft_strncmp(fmt, "ls", 2) == 0 && fmt++))
			{
				if ((ws = va_arg(ap, wchar_t *)))
				{
					len = ft_wstrlen(ws);
					len = (d->prec >= 0 && d->prec < len) ? d->prec : len;
					l = len - 1;
					while (++l < d->width)
						(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
					ft_wputstr(ws);
					d->res += len + ((d->width > len) ? (d->width - len) : 0);
				}
				else
				{
					ft_putstr("(null)");
					d->res += 6;
				}
				ft_reset_data(d);
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				(d->prec >= 0) ? d->farr[1] = 0 : 0;
				if (d->prec)
				{
					i = va_arg(ap, int);
					sign = (i < 0) ? -1 : 1; 
					// len = (d->prec >= 0 && ((d->width > 0 && d->prec < d->width) || !d->width)) ? d->prec : strlen(ft_itoa(d));
					len = ft_numlen(i * sign) + (i >= 0 && (d->farr[3] || d->farr[4]));;
					//len = (d->prec >= 0 && d->prec < len) ? d->prec : len;
					l = ((d->prec > len) ? d->prec : len) - 1 - (sign - 1) / 2;
					(sign < 0 && d->farr[1]) ? ft_putchar('-') : 0;
					(i >= 0 && d->farr[1] && (d->farr[3] || d->farr[4])) ? ft_putchar(32 + 11 * d->farr[4]) : 0;
					while (++l < d->width)
						(d->farr[1]) ? ft_putchar('0') : ft_putchar(' ');
					(sign < 0 && !d->farr[1]) ? ft_putchar('-') : 0;
					(i >= 0 && !d->farr[1] && (d->farr[3] || d->farr[4])) ? ft_putchar(32 + 11 * d->farr[4]) : 0;
					l = len - 1;
					while (++l < d->prec)
						ft_putchar('0');
					ft_putulnbr(i * sign);
					d->res += len - (sign - 1) / 2 + ((d->width > len  && d->width >= d->prec) ? (d->width - len + (sign - 1) / 2) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
				}
				ft_reset_data(d);
			}
			else if (*fmt == 'C' || (ft_strncmp(fmt, "lc", 2) == 0 && fmt++))
			{
				l = 0;
				while (++l < d->width)
					ft_putchar(' ');
				wc = (wchar_t)va_arg(ap, int);
				// printf("int wc: %d\n", (int)wc);
				len = ft_wputchar(wc);
				d->res += (d->width > len) ? d->width : len;
				ft_reset_data(d);
			}
			else if (*fmt == 'o')
			{
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
			}
			else if (*fmt == 'u')
			{
				(d->prec >= 0) ? d->farr[1] = 0 : 0;
				if (d->prec)
				{
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
				}
				ft_reset_data(d);
			}
			else if (*fmt == 'D' || ((ft_strncmp(fmt, "ld", 2) == 0
				|| ft_strncmp(fmt, "li", 2) == 0) && fmt++))
			{
				(d->prec >= 0) ? d->farr[1] = 0 : 0;
				if (d->prec)
				{
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
				}
				ft_reset_data(d);
			}
			else if (*fmt == 'O' || ((ft_strncmp(fmt, "lo", 2) == 0
				|| ft_strncmp(fmt, "lO", 2) == 0) && fmt++))
			{
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
			}
			else if (*fmt == 'U' || ((ft_strncmp(fmt, "lu", 2) == 0
				|| ft_strncmp(fmt, "lU", 2) == 0 || ft_strncmp(fmt, "lD", 2) == 0) && fmt++))
			{
				(d->prec >= 0) ? d->farr[1] = 0 : 0;
				if (d->prec)
				{
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
				}
				ft_reset_data(d);
			}
			else if (*fmt == 'x' || (ft_strncmp(fmt, "lx", 2) == 0 && fmt++))
			{
				(d->prec >= 0) ? d->farr[1] = 0 : 0;
				if (d->prec)
				{
					ulg = va_arg(ap, unsigned long);
					s = ft_ultoa_base(ulg, 16, 1);
					len = ft_strlen(s) + ((ulg > 0 && d->farr[0]) ? 2 : 0);
					l = ((d->prec > len) ? d->prec : len) - 1;
					while (++l < d->width)
						(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
					l = len - 1;
					(ulg > 0 && d->farr[0]) ? ft_putstr("0x") : 0;
					while (++l < d->prec)
						ft_putchar('0');
					ft_putstr(s);
					free(s);
					d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
				}
				ft_reset_data(d);
			}
			else if (*fmt == 'X' || (ft_strncmp(fmt, "lX", 2) == 0 && fmt++))
			{
				(d->prec >= 0) ? d->farr[1] = 0 : 0;
				if (d->prec)
				{
					ulg = va_arg(ap, unsigned long);
					s = ft_ultoa_base(ulg, 16, 0);
					len = ft_strlen(s) + ((ulg > 0 && d->farr[0]) ? 2 : 0);;
					l = ((d->prec > len) ? d->prec : len) - 1;
					while (++l < d->width)
						(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
					l = len - 1;
					(ulg > 0 && d->farr[0]) ? ft_putstr("0X") : 0;
					while (++l < d->prec)
						ft_putchar('0');
					ft_putstr(s);
					free(s);
					d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
				}
				ft_reset_data(d);
			}
			else if (*fmt == 'p' || (ft_strncmp(fmt, "lp", 2) == 0 && fmt++))
			{
				(d->prec >= 0) ? d->farr[1] = 0 : 0;
				if (d->prec)
				{
					ulg = va_arg(ap, unsigned long);
					s = ft_ultoa_base(ulg, 16, 1);
					len = ft_strlen(s);
					l = ((d->prec > len) ? d->prec : len) + 1;
					(d->farr[1] && (d->res += 2)) ? ft_putstr("0x") : 0;
					while (++l < d->width && ++(d->res))
						(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
					l = len - 1;
					(!d->farr[1] && (d->res += 2)) ? ft_putstr("0x") : 0;
					while (++l < d->prec && ++(d->res))
						ft_putchar('0');
					ft_putstr(s);
					free(s);
					d->res += len;
					// d->res += len + ((d->width > len  && d->width >= d->prec) ? (d->width - len) : 0) + ((d->prec > len && d->prec > d->width) ? (d->prec - len) : 0);
				}
				else if ((d->res += 2))
					ft_putstr("0x");
				ft_reset_data(d);
			}
			// else if (*fmt == '%')
			// {
			// 	ft_putchar(*fmt);
			// 	ft_reset_data(d);
			// 	d->res++;
			// }
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
				// printf("%s\n", "TEST");
				d->prec = ft_atoi(fmt + 1);
				if (d->prec > 0 || *(fmt + 1) == '0')
					fmt += strlen(ft_itoa(d->prec));
			}
			else if (d->prec == -1 && ft_isdigit(*fmt) && (d->width = ft_atoi(fmt)))
				fmt += strlen(ft_itoa(d->width)) - 1;
			// else if (d->prec == 0)
			// 	ft_reset_data(d);
			else if (*fmt == 'c' || *fmt/* == '%'*/)
			{
				l = 0;
				while (++l < d->width)
					(d->farr[1] == 0) ? ft_putchar(' ') : ft_putchar('0');
				(*fmt == 'c') ? ft_putchar((char)va_arg(ap, int)) : ft_putchar(*fmt);
				d->res += (d->width > 1) ? d->width : 1;
				ft_reset_data(d);
			}
			// else if (*fmt && ++(d->res))
			// {
			// 	ft_putchar(*fmt);
			// 	ft_reset_data(d);
			// }
			// else if (*fmt)
			// {
			// 	// write(1, fmt, 1);
			// 	printf("\nError on %s\n", fmt);
			// 	return (-1);
			// }
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
