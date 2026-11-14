#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/01 01:55:11 by alkonsta          #+#    #+#              #
#    Updated: 2026/11/02 05:47:34 by alkonsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

PRINTF_DIR = libftprintf
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude -I$(PRINTF_DIR)
BONUS_CPPFLAGS = -Isrc/checker/get_next_line

COMMON_SRCS = src/common/stack.c \
	       src/common/stack_utils.c \
	       src/common/operations/push.c \
	       src/common/operations/swap.c \
	       src/common/operations/rotate.c \
	       src/common/operations/reverse_rotate.c \
	       src/common/utils.c \
	       src/common/parse_stack.c

SRCS = src/push_swap/push_swap.c \
	src/push_swap/parser.c \
	src/push_swap/sorters/simple.c \
	src/push_swap/sorters/medium.c \
	src/push_swap/sorters/complex.c \
	src/push_swap/sorters/sorter_utils.c \
	src/push_swap/benchmark.c

BONUS_SRCS = src/checker/checker.c \
	      src/checker/parse_operation.c \
	      src/checker/get_next_line/get_next_line.c \
	      src/checker/get_next_line/get_next_line_utils.c

COMMON_OBJS = $(COMMON_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
$(BONUS_OBJS): CPPFLAGS += $(BONUS_CPPFLAGS)

$(NAME): $(OBJS) $(COMMON_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(COMMON_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(BONUS_CPPFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS) $(COMMON_OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean:	clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re:	fclean all

re_bonus:	fclean
			$(MAKE) bonus

.PHONY: all bonus clean fclean re re_bonus
