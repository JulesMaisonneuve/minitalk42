/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 03:47:51 by jumaison          #+#    #+#             */
/*   Updated: 2021/04/23 03:48:10 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_spaces(t_flags *flags)
{
	if (flags->spaces < 0)
	{
		flags->minus = 1;
		flags->spaces *= -1;
	}
}
