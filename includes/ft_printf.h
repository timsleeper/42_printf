/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:51:06 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/07/10 15:39:48 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_data
{
	char				buffer[BUFFER_SIZE + 1];
	int					counter;
	int					ret;
	int					width;
	int					prec;
	int					prec_w;
	int					conversion;
	int					neg;
	int					zero;
	int					plus;
	int					space;
	int					hash;
	int					len;
	int					padding_len;
	int					index;
	int					is_int;

	long long			n;
	unsigned long long	u;
}				t_data;

void			flags_reset(t_data *s);
void			init_struct(t_data *s);

void			parse(char *format, va_list ap, t_data *s);

size_t			conversion_type(char c);
size_t			modifier_type(char c);

void			process_conversion(char *format, va_list ap, t_data *s);

void			process_char(va_list ap, t_data *s);
void			process_string(va_list ap, t_data *s);
void			process_ptr(va_list ap, t_data *s);
void			process_hex(va_list ap, t_data *s);
void			process_int(va_list ap, t_data *s);
void			process_uint(va_list ap, t_data *s);

void			set_precision(t_data *s);

char			*add_padding(t_data *s);
char			*char_to_str(char c);
char			*strdup_p(char *str, t_data *s);
char			*itoa_printf(long long n);
char			*itoa_base(unsigned long long n, char *base);
char			*uitoa_printf(unsigned long long n);
char			*prec_num(char *str, t_data *s);

int				atoi_printf(char *format, int *index);
int				integer_len(long long n);
int				uinteger_len(unsigned long long n);

size_t			ft_strlen(const char *s);

void			*ft_calloc(size_t count, size_t size);

char			*ft_strdup(const char *s1);

void			concat(char *str, char *sp, t_data *s);
void			dump_buffer(t_data *s);
void			add_buffer(t_data *s, char *str, int len);

int				ft_printf(const char *format, ...);

#endif