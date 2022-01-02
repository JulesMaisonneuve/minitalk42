/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:34:15 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/03 17:57:13 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision(t_flags *flags, char *tmp)
{
	char	*res;
	char	*to_free;

	to_free = tmp;
	res = ft_substr(tmp, 0, flags->precision);
	flags->width = ft_strlen(res);
	free(to_free);
	return (res);
}

void	apply_di_precision(t_flags *flags, char *tmp)
{
	int	i;

	i = 0;
	i = flags->precision - ft_strlen(tmp);
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}
