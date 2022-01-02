/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 02:07:55 by jumaison          #+#    #+#             */
/*   Updated: 2021/04/23 03:25:58 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char c, va_list ap, t_flags *flags)
{
	if (c == 'd' || c == 'i')
		return (printf_di(ap, flags));
	else if (c == 's')
		return (printf_string(ap, flags));
	else if (c == 'c')
		return (printf_char(ap, flags));
	else if (c == 'p')
		return (printf_p(ap, flags));
	else if (c == 'u')
		return (printf_u(ap, flags));
	else if (c == 'x' || c == 'X')
		return (printf_x(ap, flags, c));
	return (0);
}
