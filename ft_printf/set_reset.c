/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:51:25 by jumaison          #+#    #+#             */
/*   Updated: 2021/05/07 19:22:38 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(t_flags *flags)
{
	flags->star = 0;
	flags->dot = 0;
	flags->precision = -1;
	flags->zero = -1;
	flags->count = 0;
	flags->spaces = 0;
	flags->width = 0;
	flags->negative = 0;
	flags->minus = 0;
	flags->null_ptr = 0;
}

void	set_flags(t_flags *flags)
{
	if (flags->spaces < 0)
	{
		flags->minus = 1;
		flags->spaces *= -1;
	}
	if (flags->precision < 0)
		flags->dot = 0;
	if (flags->dot > 0 || flags->minus == 1)
		flags->zero = 0;
	if (flags->precision >= flags->width)
		flags->width = flags->precision + flags->negative;
}
