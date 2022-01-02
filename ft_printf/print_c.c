/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:45:10 by jumaison          #+#    #+#             */
/*   Updated: 2021/04/23 03:26:09 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_char(va_list ap, t_flags *flags)
{
	flags->width += 1;
	if (flags->spaces < 0)
	{
		flags->minus = 1;
		flags->spaces *= -1;
	}
	if (flags->minus == 1)
		return (left_justify_char(flags, ap));
	apply_spaces(flags);
	ft_putchar(va_arg(ap, int));
	return (flags->width);
}
