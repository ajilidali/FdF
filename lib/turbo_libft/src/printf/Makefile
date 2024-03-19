# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 16:39:32 by moajili           #+#    #+#              #
#    Updated: 2024/03/19 16:20:59 by moajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = @cc
AR = ar

CFLAGS = -Werror -Wall -Wextra
ARFLAGS = rcs

OBJFILES = $(SRCFILES:.c=.o)
OBJS = $(OBJFILES)

SRCFILES = ft_printf.c \
ft_put.c \
ft_puthexa.c \
ft_putpointer.c \
ft_put_unsigned.c

all : $(NAME)

$(NAME) : $(OBJFILES)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)

clean :
	@rm -rf $(OBJFILES)

fclean : clean
	@rm -rf *.a

re : fclean all
