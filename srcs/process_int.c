/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:59:36 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:37:54 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_int(va_list ap, t_data *s)
{
	char	*str;
	char	*padding;

	s->is_int = 1;
	s->n = (long long)va_arg(ap, int);
	str = itoa_printf(s->n);
	s->len = integer_len(s->n);
	str = prec_num(str, s);
	s->len = ft_strlen(str);
	if (s->n < 0)
		s->len++;
	if ((s->n >= 0) && (s->plus || s->space))
		s->len++;
	if (s->n == 0 && s->prec && s->prec_w == 0 && !s->width)
	{
		free(str);
		return ;
	}
	if (s->n == 0 && s->prec && s->prec_w == 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	padding = add_padding(s);
	concat(str, padding, s);
}

void	process_uint(va_list ap, t_data *s)
{
	char	*str;
	char	*padding;

	s->is_int = 1;
	s->u = (unsigned long long)va_arg(ap, unsigned int);
	str = uitoa_printf(s->u);
	s->len = ft_strlen(str);
	str = prec_num(str, s);
	s->len = ft_strlen(str);
	if (s->u == 0 && s->prec && s->prec_w == 0 && !s->width)
	{
		free(str);
		return ;
	}
	if (s->u == 0 && s->prec && s->prec_w == 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	padding = add_padding(s);
	concat(str, padding, s);
}
