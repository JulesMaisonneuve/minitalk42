/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 03:21:02 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/07 17:06:53 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	digit_count(unsigned long int nb, int base_length)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base_length;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_uint(unsigned long int value, char *base)
{
	char	*ret;
	int		taille;
	int		i;
	int		base_length;

	base_length = ft_strlen(base);
	if (base_length < 2 || base_length > 16)
		return (0);
	if (value == 0)
		return ("0");
	taille = digit_count(value, base_length);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	while (value != 0)
	{
		ret[taille - i++] = base[value % base_length];
		value /= base_length;
	}
	ret[taille] = '\0';
	return (ret);
}

char	*ft_itoa_base(unsigned int value, char *base)
{
	char	*ret;
	int		taille;
	int		i;
	int		base_length;

	base_length = ft_strlen(base);
	if (base_length < 2 || base_length > 16)
		return (0);
	if (value == 0)
		return (ft_strdup("0"));
	taille = digit_count(value, base_length);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	while (value != 0)
	{
		ret[taille - i++] = base[value % base_length];
		value /= base_length;
	}
	ret[taille] = '\0';
	return (ret);
}
