# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2026/02/02 11:47:57 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT NAME
PROJECT		= miniRT
NAME		= miniRT

# MODE
MODE		= $(if $(filter 1,$(DEBUG)),debug,release)
DEBUG		?= 0

# PROJECT DIRECTORIES
SRC_DIR		= src
OBJ_DIR		= obj/$(MODE)
INC_DIR		= inc

# PROJECT SOURCES: Explicitly states
# SRC_FILES	= miniRT.c
SRC_DEV		= $(shell find src -name "*.c")
SRC			= $(SRC_DEV)
# SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# PROJECT HEADER
HDR_DEV		= $(shell find inc -name "*.h")
HEADERS		= $(HDR_DEV)
# HEADERS		= $(INC_DIR)/miniRT.h

# PROJECT OBJECTS
OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_DIRS	= $(sort $(dir $(OBJ)))
DEPS		= $(OBJ:.o=.d)


# TOOLS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CGENERAL	= -O2
CDEBUG		= -g3 -O0
MAKE_QUIET	= --no-print-directory

# LIBFT LINKING
LIBFT_DIR	= ./libft
LIBFT_H		= $(LIBFT_DIR)/inc/libft.h
LIBFT_A		= $(LIBFT_DIR)/libft.a

# MLX42 LINKING
MLX42_DIR	= MLX42
MLX42_OBJ	= ./MLX42
MLX42_H		= $(MLX42_DIR)/include/MLX42/MLX42.h
MLX42_A		= $(MLX42_DIR)/build/libmlx42.a
MLX42_CLONE	= git clone https://github.com/codam-coding-college/MLX42.git

# INCLUDE PATHS AND LIBRARIES
INC			= -I$(INC_DIR) -I$(LIBFT_DIR)/inc -I$(MLX42_DIR)/include/MLX42
LIBFT		= -L$(LIBFT_DIR) -lft
MLX42		= -L$(MLX42_DIR)/build -lmlx42
LIBS		= $(LIBFT) $(MLX42) -lm -lglfw

# MESSAGES
START		= @echo "==== THOMASROFF MAKEFILE =============" \
			  && echo "==== STARTED: $(shell date '+%Y-%m-%d %H:%M:%S') ===="
BUILD_PROJ	= @echo "==== BUILDING $(PROJECT) =================" \
				&& echo "compiling in $(MODE) mode"
COMPILED	= @echo "$(PROJECT) compiled successfully"
FINISH		= @echo "==== BUILD COMPLETE ==================" \
			  && echo "==== FINISHED: $(shell date '+%Y-%m-%d %H:%M:%S') ==="
SPACER		= @echo ""

ifeq ($(DEBUG),1)
CFLAGS		+= $(CDEBUG)
else
CFLAGS		+= $(CGENERAL)
endif

# <<<<<<< MAIN TARGETS >>>>>>>

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(MLX42_A)
	$(START)
	$(BUILD_PROJ)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)
	$(COMPILED)
	$(FINISH)

$(MLX42_A):
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		echo "==== CLONING MLX42 =========="; \
		$(MLX42_CLONE) $(SHELL_QUIET); \
		echo "MLX42 cloned"; \
	fi
	@echo "==== BUILDING MLX42_FT ======"
	@cmake -S $(MLX42_OBJ) -B $(MLX42_OBJ)/build $(SHELL_QUIET)
	@cmake --build $(MLX42_OBJ)/build -j4 $(SHELL_QUIET)
	@echo "MLX42 compiled"

$(LIBFT_A):
	@compiledb make -C $(LIBFT_DIR) $(MAKE_QUIET)
	$(SPACER)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

-include $(DEPS)

.SECONDARY: $(OBJ) 

# <<<<<<< MAIN PHONY TARGETS >>>>>>>

debug:
	@$(MAKE) DEBUG=1 all $(MAKE_QUIET)

release:
	@$(MAKE) DEBUG=0 all $(MAKE_QUIET)
clean:
	@echo "Removing object files"
	@rm -rf obj
	@make -C libft clean $(MAKE_QUIET)
	@if [ -d "$(MLX42_OBJ)/build" ]; then \
		cmake --build $(MLX42_OBJ)/build --target clean $(SHELL_QUIET); \
	fi

fclean:
	@echo "Removing object files"
	@rm -rf obj
	@echo "Removing static library files"
	@rm -f $(NAME)
	@make -C libft fclean $(MAKE_QUIET)
	@rm -rf $(MLX42_DIR)

re: fclean all

# <<<<<<< EXTRA PHONY TARGETS >>>>>>>

run: $(NAME)
	@echo "Running $(NAME)..."
	@./$(NAME)

val: $(NAME)
	@echo "Running valgrind $(NAME)..."
	@valgrind --leak-check=full -- show-leak-kinds=yes --suppressions=s.supp ./$(NAME)

retry: clean all run

reval: clean debug val

.PHONY: all clean fclean re debug release run val retry reval
