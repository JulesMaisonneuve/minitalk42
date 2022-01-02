/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:48:39 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/03 17:56:52 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_p(t_flags *flags, va_list ap)
{
	void				*ptr;
	unsigned long int	p;
	char				*tmp;

	tmp = NULL;
	ptr = (void *)va_arg(ap, void *);
	p = (unsigned long int)ptr;
	if (p == 0)
		flags->null_ptr = 1;
	tmp = ft_itoa_base_uint(p, "0123456789abcdef");
	flags->width += ft_strlen(tmp) + 2;
	return (tmp);
}

int	printf_p(va_list ap, t_flags *flags)
{
	char	*res;

	res = NULL;
	flags->zero = 0;
	flags->dot = 0;
	res = conv_p(flags, ap);
	check_spaces(flags);
	if (flags->minus == 1)
	{
		if (flags->negative == 0)
			ft_putstr("0x");
		return (left_justify(flags, res));
	}
	apply_spaces(flags);
	if (flags->negative == 0)
		ft_putstr("0x");
	ft_putstr(res);
	if (flags->null_ptr != 1)
		free(res);
	return (flags->width);
}
