/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:14:19 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/03 17:55:28 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*init_tflags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->precision = -1;
	flags->zero = -1;
	flags->pos = 0;
	flags->count = 0;
	flags->spaces = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->star = 0;
	flags->dot = 0;
	flags->negative = 0;
	flags->null_ptr = 0;
	return (flags);
}

int	ft_printf(const char *str, ...)
{
	t_flags	*flags;
	va_list	ap;
	int		bytes_written;

	bytes_written = 0;
	flags = init_tflags();
	va_start(ap, str);
	while (str[flags->pos] != '\0')
	{
		if (str[flags->pos] != '%')
		{
			ft_putchar(str[flags->pos]);
			bytes_written++;
		}
		if (str[flags->pos] == '%')
		{
			flags->pos++;
			bytes_written += reset_check_flags(ap, flags, str);
			bytes_written += print_arg(str[flags->pos], ap, flags);
		}
		flags->pos++;
	}
	va_end(ap);
	free(flags);
	return (bytes_written);
}
