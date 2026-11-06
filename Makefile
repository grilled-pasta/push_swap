#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/01 01:55:11 by alkonsta          #+#    #+#              #
#    Updated: 2026/11/02 05:47:34 by alla             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF_DIR = libftprintf
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -I$(PRINTF_DIR)

SRCS = push_swap.c \
       stack.c \
       stack_utils.c \
       operations/push.c \
       operations/swap.c \
       operations/rotate.c \
       operations/reverse_rotate.c \
       sorters/simple.c \
       sorters/medium.c \
       sorters/complex.c \
       parser.c \
       utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
