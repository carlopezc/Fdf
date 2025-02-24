# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 15:49:58 by carlopez          #+#    #+#              #
#    Updated: 2025/02/24 10:25:40 by carlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -g -ldl -lglfw -lm -pthread
NAME = fdf

LIB = lib/fdf.h
PRINTFDIR = printf
MLXDIR = MLX42
BUILD = $(MLXDIR)/build
PRINTF = printf/libftprintf.a
MAIN = main/main.c
MLX = $(BUILD)/libmlx42.a

#COLOURS AND TEXT FORMAT
LIGHT_YELLOW	= \033[1;33m
BOLD_GREEN    = \033[1;32m
BOLD_PURPLE   = \033[1;35m
BOLD_CYAN     = \033[1;36m
PINK_LIGHT= \033[38;5;217m
RED_BRIGHT     = \033[38;2;255;0;0m
PINK_FUCHSIA    = \033[38;2;255;20;147m

RESET  = \033[0m

SRC = src/ft_build_map.c src/ft_check_format.c src/ft_int_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c src/utils_check_format.c src/ft_draw.c
OBJ = $(SRC:.c=.o)

all:
	@echo "$(PINK_FUCHSIA)\n MAKING FDF \n$(RESET)"
	@$(MAKE) --no-print-directory $(NAME)	

$(NAME): $(MAIN) $(OBJ) $(PRINTF) $(MLX)
	@echo "$(BOLD_CYAN)\nCompiling program...$(RESET)"
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "$(BOLD_CYAN)\n!Compilation completed, $(LIGHT_YELLOW)fdf🚀$(BOLD_CYAN) ready to be used!\n$(RESET)"

%.o: %.c $(LIB) Makefile
	@echo "$(PINK_LIGHT)🡲 Creating object...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	@echo "$(BOLD_PURPLE)\nCompiling printf...$(RESET)"
	@$(MAKE) --silent -C $(PRINTFDIR)

$(BUILD):
	@if [ ! -d $(MLX_\DIR)/build ]; then \
	cmake $(MLXDIR) -B $(MLXDIR)/build > /dev/null 2>&1&& \
	make -C $(MLXDIR)/build -j4 > /dev/null 2>&1; \
	fi

$(MLX): $(BUILD)
	@$(MAKE) -C $(BUILD)

clean:
	@echo "$(RED_BRIGHT)\nThrowing object files of Fdf to 🗑️$(RESET)"
	rm -f $(OBJ)
	@echo "$(RED_BRIGHT)\nThrowing object files of Printf to 🗑️$(RESET)"
	@$(MAKE) -C $(PRINTFDIR) clean --silent
	rm -rf $(BUILD)

fclean: clean
	@echo "$(RED_BRIGHT)\nDestroying printf 💥$(RESET)"
	@$(MAKE) -C $(PRINTFDIR) fclean --silent
	@echo "$(RED_BRIGHT)\nDestroying program 💥$(RESET)"
	@$(MAKE) clean --silent
	rm -f $(NAME)
	@echo "\n$(BOLD_GREEN) Bye bye 👋 $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
