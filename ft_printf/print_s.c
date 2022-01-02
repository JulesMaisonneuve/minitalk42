/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:46:39 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/03 17:53:31 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_string(va_list ap, t_flags *flags)
{
	char	*tmp;
	char	*res;

	tmp = NULL;
	res = va_arg(ap, char *);
	flags->zero = 0;
	if (res == NULL)
	{
		tmp = ft_strdup("(null)");
		if (flags->precision < 6 && flags->precision > 0 && flags->dot == 1)
			*tmp = '\0';
	}
	else
		tmp = ft_strdup(res);
	flags->width += ft_strlen(tmp);
	check_spaces(flags);
	if (flags->minus == 1)
		return (left_justify(flags, tmp));
	if (flags->precision < flags->width
		&& flags->precision > -1 && flags->dot > 0)
		tmp = apply_precision(flags, tmp);
	apply_spaces(flags);
	ft_putstr(tmp);
	free(tmp);
	return (flags->width);
}
