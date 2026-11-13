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
BONUS_NAME = checker

PRINTF_DIR = libftprintf
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -I$(PRINTF_DIR)

BONUS_SRCS = get_next_line/get_next_line.c \
	     get_next_line/get_next_line_utils.c \
	     checker.c

COMMON_SRCS = stack.c \
	      stack_utils.c \
	      operations/push.c \
	      operations/swap.c \
	      operations/rotate.c \
	      operations/reverse_rotate.c \
	      utils.c \
	      parser.c \
	      parser_utils.c


SRCS = push_swap.c \
       sorters/simple.c \
       sorters/medium.c \
       sorters/complex.c \
       sorters/sorter_utils.c \
       benchmark.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
COMMON_OBJS = $(COMMON_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

DEPS =	$(OBJS:.o=.d) \
	$(COMMON_OBJS:.o=.d) \
	$(BONUS_OBJS:.o=.d)

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS) $(COMMON_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(COMMON_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS) $(COMMON_OBJS) $(BONUS_OBJS) $(DEPS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re:	fclean all

.PHONY: all bonus clean fclean re
