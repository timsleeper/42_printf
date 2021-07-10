/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:50:23 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:36:30 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen_base(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	baselen;

	len = 1;
	baselen = ft_strlen(base);
	while (n >= baselen)
	{
		n = n / baselen;
		len++;
	}
	return (len);
}

char	*itoa_base(unsigned long long n, char *base)
{
	char	*str;
	int		numlen;
	int		baselen;

	numlen = ft_intlen_base(n, base);
	baselen = ft_strlen(base);
	str = ft_calloc((numlen + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (numlen)
	{
		numlen = numlen - 1;
		str[numlen] = base[n % baselen];
		n = n / baselen;
	}
	return (str);
}
