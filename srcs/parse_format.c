/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:38:10 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:38:53 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_more_flags(char *format, t_data *s)
{
	if (format[s->index] == '.')
		set_precision(s);
	if (format[s->index] == ' ')
		s->space = 1;
	if (format[s->index] == '+')
		s->plus = 1;
	if (format[s->index] == '#')
		s->hash = 1;
}

void	check_flags(char *format, va_list ap, t_data *s)
{
	if (format[s->index] == '*')
	{
		if (s->prec)
			s->prec_w = va_arg(ap, int);
		else
			s->width = va_arg(ap, int);
	}
	if (format[s->index] == '0' && !s->neg && !s->prec)
		s->zero = 1;
	if (format[s->index] > '0' && format[s->index] <= '9' && !s->prec)
		s->width = atoi_printf(format, &s->index);
	if (format[s->index] >= '0' && format[s->index] <= '9' && s->prec)
		s->prec_w = atoi_printf(format, &s->index);
	if (format[s->index] == '-')
	{
		s->zero = 0;
		s->neg = 1;
	}
	check_more_flags(format, s);
}

int	parse_further(char *format, va_list ap, t_data *s)
{
	while (!conversion_type(format[s->index]))
	{
		check_flags(format, ap, s);
		if (format[s->index + 1] == '\0')
			return (0);
		if (!modifier_type(format[s->index + 1]))
			return (0);
		s->index++;
	}
	return (1);
}

void	parse(char *format, va_list ap, t_data *s)
{
	s->index++;
	flags_reset(s);
	if (!parse_further(format, ap, s))
		return ;
	if (s->width < 0)
	{
		s->neg = 1;
		s->zero = 0;
		s->width = -s->width;
	}
	if (s->prec_w < 0)
		s->prec = 0;
	if (s->prec && s->prec_w >= 0)
		s->zero = 0;
	s->conversion = format[s->index];
	process_conversion(format, ap, s);
}
