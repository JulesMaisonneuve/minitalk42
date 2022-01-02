/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:11:09 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/03 17:56:38 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_flags
{
	int	zero;
	int	precision;
	int	star;
	int	dot;
	int	spaces;
	int	width;
	int	count;
	int	pos;
	int	null_ptr;
	int	minus;
	int	negative;
	int	bytes_written;
}				t_flags;

void			ft_putchar(char c);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
char			*ft_itoa_base_uint(unsigned long int value, char *base);
char			*ft_itoa_base(unsigned int value, char *base);
int				ft_putstr(char *s);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_utoa(unsigned int nb);
char			*ft_itoa(int nb);
int				apply_spaces(t_flags *flags);
char			*apply_precision(t_flags *flags, char *tmp);
void			apply_di_precision(t_flags *flags, char *tmp);
void			set_flags(t_flags *flags);
void			reset_flags(t_flags *flags);
int				left_justify_char(t_flags *flags, va_list ap);
int				left_justify_di(t_flags *flags, char *tmp);
int				left_justify(t_flags *flags, char *tmp);
int				apply_flags(t_flags *flags, char *tmp);
int				reset_check_flags(va_list ap, t_flags *flags, const char *str);
void			check_spaces(t_flags *flags);
int				print_arg(char c, va_list ap, t_flags *flags);
int				printf_char(va_list ap, t_flags *flags);
int				printf_string(va_list ap, t_flags *flags);
int				printf_p(va_list ap, t_flags *flags);
int				printf_di(va_list ap, t_flags *flags);
int				printf_u(va_list ap, t_flags *flags);
int				printf_x(va_list ap, t_flags *flags, char c);
int				ft_printf(const char *str, ...);

#endif
