/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_justify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:37:47 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/03 17:55:42 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	left_justify_char(t_flags *flags, va_list ap)
{
	ft_putchar(va_arg(ap, int));
	apply_spaces(flags);
	return (flags->width);
}

int	left_justify_di(t_flags *flags, char *tmp)
{
	if (flags->minus == 1)
	{
		flags->zero = 0;
		if (flags->negative == 1)
		{
			ft_putchar('-');
		}
		apply_di_precision(flags, tmp);
		ft_putstr(tmp);
		apply_spaces(flags);
		free(tmp);
		return (flags->width);
	}
	return (0);
}

int	left_justify(t_flags *flags, char *tmp)
{
	if (flags->minus == 1)
	{
		if (flags->precision < flags->width
			&& flags->dot == 1 && flags->precision > -1)
			tmp = apply_precision(flags, tmp);
		ft_putstr(tmp);
		apply_spaces(flags);
		if (flags->null_ptr != 1)
			free(tmp);
		return (flags->width);
	}
	return (0);
}
