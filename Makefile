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

SRC_DIR = src
COMMON_DIR = $(SRC_DIR)/common
PUSH_SWAP_DIR = $(SRC_DIR)/push_swap
CHECKER_DIR = $(SRC_DIR)/checker

PRINTF_DIR = libftprintf
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPFLAGS = -MMD -MP
CPPFLAGS = -Iinclude -I$(PRINTF_DIR)
BONUS_CPPFLAGS = -I$(CHECKER_DIR)/get_next_line

COMMON_FILES = stack.c \
	       stack_utils.c \
	       operations/push.c \
	       operations/swap.c \
	       operations/rotate.c \
	       operations/reverse_rotate.c \
	       utils.c \
	       parse_stack.c
COMMON_SRCS = $(addprefix $(COMMON_DIR)/,$(COMMON_FILES))

FILES = push_swap.c \
	parser.c \
	sorters/simple.c \
	sorters/medium.c \
	sorters/complex.c \
	sorters/sorter_utils.c \
	benchmark.c
SRCS = $(addprefix $(PUSH_SWAP_DIR)/,$(FILES))

BONUS_FILES = checker.c \
	      parse_operation.c \
	      get_next_line/get_next_line.c \
	      get_next_line/get_next_line_utils.c
BONUS_SRCS = $(addprefix $(CHECKER_DIR)/,$(BONUS_FILES))

COMMON_OBJS = $(COMMON_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
$(BONUS_OBJS): CPPFLAGS += $(BONUS_CPPFLAGS)

DEPS =	$(OBJS:.o=.d) \
	$(COMMON_OBJS:.o=.d) \
	$(BONUS_OBJS:.o=.d)

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS) $(COMMON_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(COMMON_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(BONUS_CPPFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(CPPFLAGS) -c $< -o $@

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS) $(COMMON_OBJS) $(BONUS_OBJS) $(DEPS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re:	fclean all

re_bonus:	fclean
		$(MAKE) bonus

.PHONY: all bonus clean fclean re re_bonus
.DEFAULT_GOAL := all
