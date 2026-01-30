# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/11/24 20:05:01 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT NAME
PROJECT		= minishell
NAME		= minishell

# MODE
MODE		= $(if $(filter 1,$(DEBUG)),debug,release)
DEBUG		?= 0

# PROJECT DIRECTORIES
SRC_DIR		= src
OBJ_DIR		= obj/$(MODE)
INC_DIR		= inc
PARSER_DIR	= src/parser
UTILS_DIR	= src/utils

# PROJECT SOURCES: Explicitly states
SRC_FILES	= main.c
SRC_DEV		= $(shell find src -name "*.c")
SRC			= $(SRC_DEV)
# SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# PROJECT HEADER
HEADER		= $(INC_DIR)/minishell.h

# PROJECT OBJECTS
OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_DIRS	= $(sort $(dir $(OBJ)))
DEPS		= $(OBJ:.o=.d)

# MAC COMPATIBILITY (SEE INC AND LIB CODE TOO)
UNAME		= $(shell uname)
ifeq ($(UNAME), Darwin)
	RL_INC	= -I/usr/local/opt/readline/include
	RL_LIB	= -L/usr/local/opt/readline/lib -Wl,-rpath,/usr/local/opt/readline/lib
else
	RL_INC	=
	RL_LIB	=
endif

# TOOLS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
CGENERAL	= -O2
CFAST		= -O3
CDEBUG		= -g -O0 -DDEBUG
MAKE_QUIET	= --no-print-directory
MAKE_LIB	= $(MAKE) -C

# REMOVE
RMFILE = rm -f
RMDIR = rm -rf

# MAKE DIRECTORY
MKDIR		= mkdir -p

# LIBFT LINKING
LIBFT_DIR	= ./libft
LIBFT_H		= $(LIBFT_DIR)/inc/libft.h
LIBFT_A		= $(LIBFT_DIR)/libft.a

# MAC INCLUDE PATHS AND LIBRARIES
INC			= -I. $(RL_INC) -I$(LIBFT_DIR) -I$(LIBFT_DIR)/inc -I$(INC_DIR)
LIBFT		= -L$(LIBFT_DIR) -lft
READLINE	= $(RL_LIB) -lreadline -lncurses
LIBS		= $(LIBFT) $(READLINE)

# MESSAGES
START		= @echo "==== THOMASROFF MAKEFILE =============" \
				&& echo "==== STARTED: $(shell date '+%Y-%m-%d %H:%M:%S') ===="
BUILD_PROJ	= @echo "==== BUILDING $(PROJECT) ==============" \
				&& echo "compiling in $(MODE) mode"
BUILD_LIBFT	= @echo "==== BUILDING LIBFT =================="
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
	@$(MAKE_LIB) $(LIBFT_DIR) $(MAKE_QUIET)
	$(SPACER)

$(OBJ_DIRS):
	@$(MKDIR) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIRS)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

-include $(DEPS)

.SECONDARY: $(OBJ) 

# <<<<<<< PHONY TARGETS >>>>>>>

.PHONY: all clean fclean re run rundebug runval retry redebug reval debug release

debug:
	@$(MAKE) DEBUG=1 re $(MAKE_QUIET)

release:
	@$(MAKE) DEBUG=0 re $(MAKE_QUIET)

clean:
	@echo "Removing object files"
	@$(RMDIR) obj
	@$(MAKE_LIB) libft clean $(MAKE_QUIET)

fclean:
	@echo "Removing object files"
	@$(RMDIR) obj
	@echo "Removing static library files"
	@$(RMFILE) $(NAME)
	@$(MAKE_LIB) libft fclean $(MAKE_QUIET)

re: fclean all

run: $(NAME)
	@echo "Running $(NAME)..."
	@./$(NAME)

rundebug: $(NAME)
	@echo "Running $(NAME) -debug..."
	@./$(NAME) -debug

runval: $(NAME)
	@echo "Running valgrind $(NAME) -debug..."
	@valgrind --leak-check=full --track-fds=yes ./$(NAME) -debug

runempty: $(NAME)
	@echo "Running valgrind env -i $(NAME) -debug -envp..."
	@valgrind --leak-check=full --track-fds=yes env -i ./$(NAME) -debug -envp

runleak: $(NAME)
	@echo "Running valgrind leaks $(NAME) -debug..."
	@valgrind --leak-check=full --show-leak-kinds=yes --track-fds=all ./$(NAME) -debug

runsupp: $(NAME)
	@echo "Running valgrind leaks $(NAME) -debug..."
	@valgrind --leak-check=full --show-leak-kinds=yes --track-fds=all --num-callers=50 --suppressions=readline.supp ./$(NAME) -debug

retry: clean all run

redebug: clean all rundebug

reval: debug runval

reempty: debug runempty

releak: debug runleak

resupp: debug runsupp
