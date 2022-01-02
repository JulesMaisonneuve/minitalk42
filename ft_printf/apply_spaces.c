/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:42:07 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/03 17:52:49 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_spaces(t_flags *flags)
{
	int	i;

	i = flags->spaces - flags->width;
	if (i > 0)
	{
		while (flags->spaces > flags->width)
		{
			if (flags->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			flags->spaces--;
		}
		flags->width += i;
		return (i);
	}
	return (0);
}
