/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_check_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 03:15:50 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/03 18:03:18 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(va_list ap, const char *str, t_flags *flags)
{
	if (str[flags->pos] == '%')
	{
		ft_putchar('%');
		flags->width++;
		return (flags->width);
	}
	while ((str[flags->pos] == '0' || str[flags->pos] == '-'
			|| str[flags->pos] == '*') && *str)
	{
		if (str[flags->pos] == '0')
			flags->zero = 1;
		else if (str[flags->pos] == '-')
		{
			flags->zero = 0;
			flags->minus = 1;
		}
		else if (str[flags->pos] == '*')
		{
			flags->star = 1;
			flags->spaces = va_arg(ap, int);
		}
		flags->pos++;
	}
	return (0);
}

void	get_precision(t_flags *flags, const char *str)
{
	char	*tmp;

	tmp = NULL;
	while (ft_isdigit(str[flags->pos]) != 0)
	{
		flags->count++;
		flags->pos++;
	}
	tmp = ft_substr(str, flags->pos - flags->count, flags->count);
	flags->precision = ft_atoi(tmp);
	free(tmp);
}

void	get_spaces(t_flags *flags, const char *str)
{
	char	*tmp;

	tmp = NULL;
	while (ft_isdigit(str[flags->pos]) != 0)
	{
		flags->count++;
		flags->pos++;
	}
	if (flags->star < 1)
	{
		tmp = ft_substr(str, flags->pos - flags->count, flags->count);
		flags->spaces = ft_atoi(tmp);
		free(tmp);
	}
}

void	second_check_flag(va_list ap, const char *str, t_flags *flags)
{
	get_spaces(flags, str);
	if (str[flags->pos] == '.')
	{
		flags->pos++;
		flags->count = 0;
		flags->dot = 1;
		if (str[flags->pos] == '*')
		{
			flags->star = 1;
			flags->precision = va_arg(ap, int);
			flags->pos++;
		}
		else
			get_precision(flags, str);
	}
}

int	reset_check_flags(va_list ap, t_flags *flags, const char *str)
{
	int	bytes_written;

	bytes_written = 0;
	reset_flags(flags);
	bytes_written += check_flag(ap, str, flags);
	second_check_flag(ap, str, flags);
	return (bytes_written);
}
