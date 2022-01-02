/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:54:16 by jumaison          #+#    #+#             */
/*   Updated: 2021/04/23 03:29:42 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_u(va_list ap, t_flags *flags)
{
	char	*tmp;
	int		res;

	res = (int)va_arg(ap, int);
	tmp = ft_utoa(res);
	if (res == 0 && flags->precision == 0)
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
