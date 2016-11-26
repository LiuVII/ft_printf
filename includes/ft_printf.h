/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilipch <mfilipch@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 00:04:41 by mfilipch          #+#    #+#             */
/*   Updated: 2016/11/21 00:04:43 by mfilipch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#define FT_PRINTF_H
#define ABS(x) ((x < 0) ? (-x) : (x))

typedef struct 		s_data
{
	int				res;
	int				farr[5];
	int				flag;
	int				width;
	int				prec;
	int				mnum;
	int				tmp;
}					t_data;

void		ft_reset_data(t_data *d);
void		ft_putulnbr(unsigned long long n);
char		*ft_ultoa_base(unsigned long value, unsigned int base, int lc);
int			ft_numlen(long long n);
size_t		ft_wstrlen(wchar_t *wstr, int l);
size_t		ft_wputchar(int c);
size_t		ft_wputstr(wchar_t *ws, int l);
char		*ft_wtochar(wchar_t *wstr);

int			ft_conv_s(t_data *d, va_list ap);
int			ft_conv_cs(t_data *d, va_list ap);
int			ft_conv_cc(t_data *d, va_list ap);
int			ft_conv_c(char fmt, t_data *d, va_list ap);
int			ft_conv_o(t_data *d, va_list ap);
int			ft_conv_co(t_data *d, va_list ap);
int			ft_conv_x(t_data *d, va_list ap, int cs, int base);
int			ft_conv_cx(t_data *d, va_list ap);
int			ft_conv_p(t_data *d, va_list ap);
int			ft_conv_id(t_data *d, va_list ap);
int			ft_conv_cd(t_data *d, va_list ap);
int			ft_conv_u(t_data *d, va_list ap);
int			ft_conv_cu(t_data *d, va_list ap);

#endif