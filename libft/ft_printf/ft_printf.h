/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstepina <mstepina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:52:04 by mstepina          #+#    #+#             */
/*   Updated: 2019/09/30 15:10:42 by mstepina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <math.h>
# include "../libft.h"

# define LLONG_MIN -9223372036854775807
# define LLONG_MAX 9223372036854775807
# define SHRT_MAX 32767
# define SHRT_MIN -32767
# define SCHAR_MAX 127
# define SCHAR_MIN -127
# define INT_MAX 2147483647
# define INT_MIN -2147483647
# define LONG_MIN -9223372036854775808
# define LONG_MAX 9223372036854775807

typedef	struct	s_flags
{
	char	hash;
	char	plus;
	char	minus;
	char	space;
	char	zero;
}				t_flags;

typedef struct	s_params
{
	t_flags	flags;
	int		width;
	int		precision;
	int		size;
}				t_params;

typedef int		t_dispatcher(t_params params, va_list ap);

t_params		get_params(char **format, va_list ap);

char			*printer_dioux(t_params params, char *str);
char			*ft_strjoin_free(char *s1, char *s2, int indx);
char			*ft_itoa_long_long(intmax_t n);
int				ft_putstr_all(char *s);
int				colors(char *format);
char			*rounding_nine(char *str, int len);
char			*make_whole(long long whole);
char			*make_dec(t_params params, long double n);
char			*printer_zero(t_params params, char *str, int len, int neg);
char			*n_whole_dec(long double n, t_params params, int len);
int				ft_printf(char *format, ...);
int				s_spec(t_params params, va_list ap);
int				c_spec(t_params params, va_list ap);
int				percent_spec(t_params params, va_list ap);
int				p_spec (t_params params, va_list ap);
int				d_spec(t_params params, va_list ap);
int				o_spec(t_params params, va_list ap);
int				u_spec(t_params params, va_list ap);
int				x_spec(t_params params, va_list ap);
int				xx_spec(t_params params, va_list ap);
int				f_spec(t_params params, va_list ap);
char			*long_itoa(long long n);

#endif
