/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:07:38 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:38:30 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_data *s)
{
	s->counter = 0;
	s->ret = 0;
	s->width = 0;
	s->prec = 0;
	s->prec_w = 0;
	s->conversion = 0;
	s->neg = 0;
	s->zero = 0;
	s->plus = 0;
	s->hash = 0;
	s->space = 0;
	s->padding_len = 0;
	s->is_int = 0;
	s->n = 0;
	s->u = 0;
	s->len = 0;
	s->index = 0;
}

void	set_precision(t_data *s)
{
	s->prec = 1;
	s->prec_w = 0;
}

void	flags_reset(t_data *s)
{
	s->width = 0;
	s->prec = 0;
	s->prec_w = 0;
	s->conversion = 0;
	s->neg = 0;
	s->zero = 0;
	s->plus = 0;
	s->hash = 0;
	s->space = 0;
	s->padding_len = 0;
	s->is_int = 0;
	s->n = 0;
	s->u = 0;
	s->len = 0;
}

size_t	conversion_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

size_t	modifier_type(char c)
{
	return (conversion_type(c) || (c >= '0' && c <= '9') || c == '-'
		|| c == '.' || c == '*' || c == ' ' || c == '+' || c == '#');
}
