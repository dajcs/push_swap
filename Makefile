# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 16:21:27 by anemet            #+#    #+#              #
#    Updated: 2025/07/14 11:14:11 by anemet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable names
NAME = push_swap
BONUS_NAME = checker

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -g 
# for debugging with AddressSanitizer, add -g -fsanitize=address,leak -fno-omit-frame-pointer

# Directories
OBJ_DIR = obj
LIBFT_DIR = libft

# Source files shared by both push_swap and checker
SRCS_COMMON = 00_parsing.c \
              01_stack_init.c \
              02_operations_push.c \
              03_operations_swap.c \
              04_operations_rotate.c \
              05_operations_rev_rotate.c \
              09_utils_positions.c \
              10_utils_free.c

# Files only for the main push_swap program
SRCS_MAIN = main.c \
              06_sort_small.c \
              07_sort_large.c \
              08_cost.c

# Files only for the `checker` program
SRCS_BONUS = 11_checker_bonus.c

# Full source lists for each target
SRCS       = $(SRCS_COMMON) $(SRCS_MAIN)
BONUS_SRCS = $(SRCS_COMMON) $(SRCS_BONUS)

# --------- OBJECT FILES -----------
# Create object file lists, placing them in OBJ_DIR
OBJS       = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
BONUS_OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(BONUS_SRCS))

# ---------- LIBRARIES -------------
LIBFT      = $(LIBFT_DIR)/libft.a
INCLUDES   = -I. -I$(LIBFT_DIR)


# ---------- RULES -----------------

all: $(NAME)

bonus: $(BONUS_NAME)

# Rule to build the main push_swap executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

# Rule to build the bonus checker executable
$(BONUS_NAME) :$(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BONUS_NAME) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft

# Rule to build the libft library
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Generic rule to compile any .c file into an object file in ./obj
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
