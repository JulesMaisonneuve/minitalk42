/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:52:45 by jumaison          #+#    #+#             */
/*   Updated: 2021/04/23 01:52:59 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_flags(t_flags *flags, char *tmp)
{
	if (flags->negative == 1 && flags->zero == 1)
		ft_putchar('-');
	apply_spaces(flags);
	if (flags->negative == 1 && flags->zero != 1)
		ft_putchar('-');
	if (flags->precision < 0)
		flags->zero = 1;
	apply_di_precision(flags, tmp);
	return (0);
}
