/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:26:44 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:36:37 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uinteger_len(unsigned long long n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	integer_len(long long n)
{
	size_t	len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*itoa_printf(long long n)
{
	char	*str;
	size_t	intlen;

	intlen = integer_len(n);
	str = ft_calloc((intlen + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (intlen)
	{
		if (n < 0)
		{
			intlen = intlen - 1;
			str[intlen] = -(n % 10) + 48;
			n = n / 10;
			n = -n;
		}
		else
		{
			intlen = intlen - 1;
			str[intlen] = n % 10 + 48;
			n = n / 10;
		}
	}
	return (str);
}

char	*uitoa_printf(unsigned long long n)
{
	char	*str;
	size_t	uintlen;

	uintlen = uinteger_len(n);
	str = ft_calloc((uintlen + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (uintlen)
	{
		uintlen = uintlen - 1;
		str[uintlen] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
