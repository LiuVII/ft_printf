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
#include <unistd.h>
#define FT_PRINTF_H
#define ABS(x) ((x < 0) ? (-x) : (x))

typedef struct 		s_data
{
	int				res;
	int				farr[5];
	int				flag;
	int				width;
	int				prec;
}					t_data;

void		ft_putulnbr(unsigned long long n);
char		*ft_ultoa_base(unsigned long value, unsigned int base, int lc);
int			ft_numlen(long long n);
size_t		ft_wstrlen(wchar_t *wstr);
size_t		ft_wputchar(int c);
size_t		ft_wputstr(wchar_t *s);
char		*ft_wtochar(wchar_t *wstr);

#endif