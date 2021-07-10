/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 00:41:22 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:39:12 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dump_buffer(t_data *s)
{
	write(1, s->buffer, s->counter);
	s->counter = 0;
}

void	add_buffer(t_data *s, char *str, int len)
{
	int	i;

	i = 0;
	s->ret = s->ret + len;
	while (i < len)
	{
		s->buffer[s->counter] = str[i];
		s->counter++;
		if (s->counter == BUFFER_SIZE)
			dump_buffer(s);
		i++;
	}
}

void	printing(t_data *s, char *format)
{
	int	p;

	p = 0;
	while (format[s->index] && format[s->index] != '%')
	{
		s->buffer[s->counter] = format[s->index];
		s->counter++;
		p++;
		if (s->counter == BUFFER_SIZE)
			dump_buffer(s);
		s->index++;
	}
	s->ret = s->ret + p;
	s->index--;
}

int	ft_printf(const char *format, ...)
{
	t_data	s;
	va_list	ap;

	init_struct(&s);
	va_start(ap, format);
	while (format[s.index])
	{
		if (format[s.index] == '%')
		{
			if (format[s.index + 1] == '\0')
				break ;
			if (modifier_type(format[s.index + 1]))
				parse((char *)format, ap, &s);
		}
		else
			printing(&s, (char *)format);
		s.index++;
	}
	va_end(ap);
	dump_buffer(&s);
	return (s.ret);
}
