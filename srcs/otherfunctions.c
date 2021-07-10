/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otherfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 02:04:43 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:38:56 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_to_str(char c)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	s[0] = c;
	return (s);
}

void	add_prefix(t_data *s)
{
	if (s->conversion == 'x')
	{
		add_buffer(s, "0x", 2);
		s->len = s->len - 2;
	}
	if (s->conversion == 'X')
	{
		add_buffer(s, "0X", 2);
		s->len = s->len - 2;
	}
}

void	add_sign(t_data *s)
{
	if (s->n < 0)
	{
		s->len--;
		add_buffer(s, "-", 1);
	}
	else if (s->plus && (s->n >= 0))
	{
		s->len--;
		add_buffer(s, "+", 1);
	}
	else if (s->space && !s->plus && (s->n >= 0))
	{
		s->len--;
		add_buffer(s, " ", 1);
	}
}

void	concat(char *str, char *padding, t_data *s)
{
	if (s->is_int && s->zero)
		add_sign(s);
	if (s->zero && s->conversion == 'p')
	{
		add_buffer(s, "0x", 2);
		s->len = s->len - 2;
	}
	if (s->hash && s->u && s->zero && s->prec_w < s->len)
		add_prefix(s);
	if (padding && !s->neg)
		add_buffer(s, padding, s->padding_len);
	if (!s->zero && s->conversion == 'p')
	{
		add_buffer(s, "0x", 2);
		s->len = s->len - 2;
	}
	if (s->hash && s-> u && !s->zero && s->prec_w < s->len)
		add_prefix(s);
	if (s->is_int && !s->zero)
		add_sign(s);
	add_buffer(s, str, s->len);
	if (padding && s->neg)
		add_buffer(s, padding, s->padding_len);
	free(str);
	free(padding);
}

char	*strdup_p(char *str, t_data *s)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (s->prec && s->prec_w < len)
		len = s->prec_w;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
