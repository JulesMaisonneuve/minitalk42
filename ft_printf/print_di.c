/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:49:41 by jumaison          #+#    #+#             */
/*   Updated: 2021/04/23 17:41:21 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_di(va_list ap, t_flags *flags)
{
	char	*tmp;
	int		len;
	int		res;
	char	*to_free;

	res = va_arg(ap, int);
	tmp = ft_itoa(res);
	if (res == 0 && flags->precision == 0)
		*tmp = '\0';
	if (res < 0)
		flags->negative = 1;
	flags->width += ft_strlen(tmp);
	len = ft_strlen(tmp) - flags->negative;
	to_free = tmp;
	tmp = ft_substr(tmp, flags->negative, len);
	free(to_free);
	set_flags(flags);
	if (flags->minus == 1)
		return (left_justify_di(flags, tmp));
	apply_flags(flags, tmp);
	ft_putstr(tmp);
	free(tmp);
	return (flags->width);
}
