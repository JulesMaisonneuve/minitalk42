/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 03:22:23 by jumaison          #+#    #+#             */
/*   Updated: 2021/06/07 17:15:15 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	substr = malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	while (s[start] != '\0' && len > 0)
	{
		substr[i] = s[start];
		start++;
		len--;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;
	int	i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		nb *= 10;
		nb += ((int)str[i] - '0');
		i++;
	}
	return (nb * sign);
}

static int	nblen(unsigned int n)
{
	int			len;

	len = 0;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

char	*ft_utoa(unsigned int nb)
{
	char		*res;
	int			pos;
	int			sign;
	long int	n;

	n = nb;
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n < 0)
		n *= -1;
	pos = nblen(n) + sign;
	res = (char *)malloc(sizeof(char) * (pos + 1));
	if (n == 0)
		res[0] = '0';
	res[pos] = '\0';
	while (n != 0)
	{
		res[pos-- - 1] = (char)(n % 10) + 48;
		n /= 10;
	}
	if (sign == 1)
		res[pos - 1] = '-';
	return (res);
}

char	*ft_itoa(int nb)
{
	char		*res;
	int			pos;
	int			sign;
	long int	n;

	n = nb;
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n < 0)
		n *= -1;
	pos = nblen(n) + sign;
	res = (char *)malloc(sizeof(char) * (pos + 1));
	if (n == 0)
		res[0] = '0';
	res[pos] = '\0';
	while (n != 0)
	{
		res[pos-- - 1] = (char)(n % 10) + 48;
		n /= 10;
	}
	if (sign == 1)
		res[pos - 1] = '-';
	return (res);
}
