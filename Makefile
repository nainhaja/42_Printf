# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 22:20:13 by nainhaja          #+#    #+#              #
#    Updated: 2019/10/23 00:59:42 by nainhaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc 

SRC = ft_printf.c ft_isdigit.c ft_hexconv2.c ft_globalinit.c ft_checkprec.c ft_printzero2.c \
ft_strcmp.c ft_checkk.c ft_printremaining.c ft_init.c ft_flagwid.c ft_prectime.c \
ft_convert.c ft_width.c ft_printspace.c ft_putstrr.c ft_strjoin.c ft_printzero.c \
ft_memset.c ft_toupper.c ft_hexconv.c ft_itoa.c ft_atoi.c ft_putchar.c ft_unta.c \
ft_putnbr.c ft_strdup.c ft_strlen.c ft_substr.c \

FLAGS = -Wall -Wextra -Werror
ARG = -c

OUT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
	$(CC) $(FLAGS) $(ARG) $(SRC)
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)

clean:
	rm -f $(OUT)

fclean: clean	
	rm -f $(NAME)

re : fclean all