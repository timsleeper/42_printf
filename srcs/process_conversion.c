/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:58:45 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:37:46 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_conversion(char *format, va_list ap, t_data *s)
{
	if (format[s->index] == 'c')
		process_char(ap, s);
	if (format[s->index] == 's')
		process_string(ap, s);
	if (format[s->index] == 'p')
		process_ptr(ap, s);
	if (format[s->index] == 'd' || format[s->index] == 'i')
		process_int(ap, s);
	if (format[s->index] == 'u')
		process_uint(ap, s);
	if (format[s->index] == 'x' || format[s->index] == 'X')
		process_hex(ap, s);
	if (format[s->index] == '%')
		process_char(ap, s);
}
