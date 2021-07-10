/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:40:45 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:37:58 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	atoi_printf(char *format, int *index)
{
	int	nbr;

	nbr = 0;
	while (format[*index] >= '0' && format[*index] <= '9')
	{
		nbr = nbr * 10 + format[*index] - 48;
		(*index)++;
	}
	(*index)--;
	return (nbr);
}
