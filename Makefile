# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2026/01/30 14:58:57 by thblack-         ###   ########.fr        #
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

# REMOVE
RMFILE = rm -f
RMDIR = rm -rf

# MAKE DIRECTORY
MKDIR		= mkdir -p

# LIBFT LINKING
LIBFT_DIR	= ./libft
LIBFT_H		= $(LIBFT_DIR)/inc/libft.h
LIBFT_A		= $(LIBFT_DIR)/libft.a

# INCLUDE PATHS AND LIBRARIES
INC			= -I$(INC_DIR) -I$(LIBFT_DIR)/inc
LIBS		= $(LIBFT) -lm

# MESSAGES
START		= @echo "==== THOMASROFF MAKEFILE =============" \
			  && echo "==== STARTED: $(shell date '+%Y-%m-%d %H:%M:%S') ===="
BUILD_PROJ	= @echo "==== BUILDING $(PROJECT) ===============" \
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

$(NAME): $(OBJ) $(LIBFT_A)
	$(START)
	$(BUILD_PROJ)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)
	$(COMPILED)
	$(FINISH)

$(LIBFT_A):
	@compiledb make -C $(LIBFT_DIR) $(MAKE_QUIET)
	$(SPACER)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@$(MKDIR) $(dir $@)
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
	@$(RMDIR) obj
	@make -C libft clean $(MAKE_QUIET)

fclean:
	@echo "Removing object files"
	@$(RMDIR) obj
	@echo "Removing static library files"
	@$(RMFILE) $(NAME)
	@make -C libft fclean $(MAKE_QUIET)

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
