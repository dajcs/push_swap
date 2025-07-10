# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 16:21:27 by anemet            #+#    #+#              #
#    Updated: 2025/07/10 16:38:07 by anemet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -g
# for debugging with AddressSanitizer, add -g -fsanitize=address

# Directories
SRC_DIR = .
OBJ_DIR = obj
LIBFT_DIR = libft

# Source files
SRCS = main.c \
            00_parsing.c \
            01_stack_init.c \
            02_operations_push.c \
            03_operations_swap.c \
            04_operations_rotate.c \
            05_operations_rev_rotate.c \
            06_sort_small.c \
            07_sort_large.c \
            08_cost.c \
            09_utils_positions.c \
            10_utils_free.c \

# prepend source directory to source files
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))

# Object files (place them in obj/ directory)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Libft archive
LIBFT = $(LIBFT_DIR)/libft.a

# Default rule
all: $(NAME)

# Link the program
$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

# compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Clean object files
clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

# rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re

