/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:55:07 by jumaison          #+#    #+#             */
/*   Updated: 2021/04/23 17:03:16 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_x(va_list ap, t_flags *flags, char c)
{
	char	*tmp;
	int		x;

	tmp = NULL;
	x = (int)va_arg(ap, int);
	if (c == 'x')
		tmp = ft_itoa_base(x, "0123456789abcdef");
	else if (c == 'X')
		tmp = ft_itoa_base(x, "0123456789ABCDEF");
	if (x == 0 && flags->precision == 0)
		*tmp = '\0';
	flags->width += ft_strlen(tmp);
	set_flags(flags);
	if (flags->minus == 1)
		return (left_justify_di(flags, tmp));
	apply_spaces(flags);
	apply_di_precision(flags, tmp);
	ft_putstr(tmp);
	free(tmp);
	return (flags->width);
}
