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
#include <stdio.h>

int			ft_printf(const char *fmt, ...)
{
	va_list 		ap;
	int				width;
	int				prec;
	int				l;
	int				len;
	int				d;
	unsigned int	ud;
	long			lg;
	unsigned long	ulg;
	long			sign;
	char			*s;
	int				res;

	va_start(ap, fmt);
	width = 0;
	prec = -1;
	res = 0;
	if (!fmt)
		return (-1);
	while (*fmt)
	{
		if ((*fmt == '%' && *(fmt++)) || width > 0 || prec >= 0)
		{
			if (*fmt == 's')
			{
				// write(1,"TEST2\n", 6);
				if ((s = va_arg(ap, char *)))
				{
					len = ft_strlen(s);
					len = (prec >= 0 && prec < len) ? prec : len;
					l = len - 1;
					while (++l < width)
						ft_putchar(' ');
					write(1, s, len);
					res += len + ((width > len) ? (width - len) : 0);
				}
				else
				{
					ft_putstr("(null)");
					res += 6;
				}
				prec = -1;
				width = 0;
			}
			// else if (*fmt == 'S')
				//s with widechar flag l
			else if ((*fmt == 'd' || *fmt == 'i') && prec)
			{
				d = va_arg(ap, int);
				sign = (d < 0) ? -1 : 1; 
				// len = (prec >= 0 && ((width > 0 && prec < width) || !width)) ? prec : strlen(ft_itoa(d));
				len = ft_numlen(d * sign);
				//len = (prec >= 0 && prec < len) ? prec : len;
				l = ((prec > len) ? prec : len) - 1 - (sign - 1) / 2;
				while (++l < width)
					ft_putchar(' ');
				(sign < 0) ? ft_putchar('-') : 0;
				l = len - 1;
				while (++l < prec)
					ft_putchar('0');
				ft_putulnbr(d * sign);
				res += len - (sign - 1) / 2 + ((width > len  && width >= prec) ? (width - len + (sign - 1) / 2) : 0) + ((prec > len && prec > width) ? (prec - len) : 0);
				prec = -1;
				width = 0;
			}
			else if (*fmt == 'c')
			{
				l = 0;
				while (++l < width)
					ft_putchar(' ');
				ft_putchar((char)va_arg(ap, int));
				res += (width > 1) ? width : 1;
				width = 0;
			}
			// else if (*fmt == 'C')
				//c with widechar flag l
			// else if (*fmt == 'o')
			// 	ft_putnbr(va_arg(ap, unsigned octal));
			else if (*fmt == 'u' && prec)
			{
				ud = va_arg(ap, unsigned int);
				len = ft_numlen(ud);
				l = ((prec > len) ? prec : len) - 1;
				while (++l < width)
					ft_putchar(' ');
				l = len - 1;
				while (++l < prec)
					ft_putchar('0');
				ft_putulnbr(ud);
				res += len + ((width > len  && width >= prec) ? (width - len) : 0) + ((prec > len && prec > width) ? (prec - len) : 0);
				prec = -1;
				width = 0;
			}
			else if (*fmt == 'D' && prec)
			{
				lg = va_arg(ap, long);
				sign = (lg < 0) ? -1 : 1; 
				len = ft_numlen(lg * sign);
				l = ((prec > len) ? prec : len) - 1 - (sign - 1) / 2;
				while (++l < width)
					ft_putchar(' ');
				(sign < 0) ? ft_putchar('-') : 0;
				l = len - 1;
				while (++l < prec)
					ft_putchar('0');
				ft_putulnbr(lg * sign);
				res += len - (sign - 1) / 2 + ((width > len  && width >= prec) ? (width - len + (sign - 1) / 2) : 0) + ((prec > len && prec > width) ? (prec - len) : 0);
				prec = -1;
				width = 0;
			}
			// else if (*fmt == 'O')
			// 	ft_putnbr(va_arg(ap, unsigned long octal));
			else if (*fmt == 'U' && prec)
			{
				ulg = va_arg(ap, unsigned long);
				len = ft_numlen(ulg);
				l = ((prec > len) ? prec : len) - 1;
				while (++l < width)
					ft_putchar(' ');
				l = len - 1;
				while (++l < prec)
					ft_putchar('0');
				ft_putulnbr(ulg);
				res += len + ((width > len  && width >= prec) ? (width - len) : 0) + ((prec > len && prec > width) ? (prec - len) : 0);
				prec = -1;
				width = 0;
			}
			// else if (*fmt == 'x')
			// 	ft_putnbr(va_arg(ap, hex_lrc));
			// else if (*fmt == 'X')
			// 	ft_putnbr(va_arg(ap, hex_upc));
			// else if (*fmt == 'p')
			// 	pointer printed in hex as if %#x;
			else if (*fmt == '%')
			{
				ft_putchar(*fmt);
				res++;
			}
			else if (*fmt == '.')
			{
				// printf("%s\n", "TEST");
				prec = ft_atoi(fmt + 1);
				if (prec > 0 || *(fmt + 1) == '0')
					fmt += strlen(ft_itoa(prec));
			}
			else if (prec == -1 && ft_isdigit(*fmt) && (width = ft_atoi(fmt)))
				fmt += strlen(ft_itoa(width)) - 1;
			else if (prec == 0)
				prec = -1;
			else
				return (-1);

		}
		else
		{
			ft_putchar(*fmt);
			res++;
		}
		fmt++;
	}
	va_end(ap);
	return (res);
}
