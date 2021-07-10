# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftadeu-d <ftadeu-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 14:06:22 by ftadeu-d          #+#    #+#              #
#    Updated: 2021/07/10 14:52:44 by ftadeu-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libftprintf.a

SRCS_LIST				= ft_printf.c \
							parse_format.c \
							process_conversion.c \
							process_int.c process_char.c \
							process_output.c \
							atoi_printf.c \
							itoa_printf.c itoa_base.c \
							utils.c otherfunctions.c \
							libft_functions.c							

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@ar -rcs ${NAME} ${OBJS}

bonus:			${NAME}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all

.PHONY: 		all fclean clean re