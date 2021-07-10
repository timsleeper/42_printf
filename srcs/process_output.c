/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:17:15 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:38:37 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_padding(t_data *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s->width < s->len)
		return (NULL);
	str = ft_calloc((s->width - s->len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (s->prec && s->prec_w > s->len)
		s->zero = 0;
	while (i < s->width - s->len)
	{
		if (s->zero)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	s->padding_len = i;
	return (str);
}

char	*prec_num(char *str, t_data *s)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s->prec || s->prec_w < s->len)
		return (str);
	temp = ft_calloc(s->prec_w + s->len + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (i < s->prec_w - s->len)
	{
		temp[i] = '0';
		i++;
	}
	while (str[j])
	{
		temp[i + j] = str[j];
		j++;
	}
	free(str);
	return (temp);
}
