# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/11/19 22:35:11 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIBRARY NAME
LIBRARY			= libft
NAME			= libft.a

# MAIN DIRECTORIES
SRC_DIR			= src
OBJ_DIR			= obj
INC_DIR			= inc

# SOURCE DIRECTORIES
ASCII_DIR		= ascii
GNL_DIR			= gnl
LISTS_DIR		= lists
MEMORY_DIR		= memory
NUMBERS_DIR		= numbers
PRINTING_DIR	= printing
STRINGS_DIR		= strings
VECTORS_DIR		= vectors
ARENA_DIR		= arena

# ASCII
ASCII_FILES	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c ft_isspace.c ft_isnum.c \
			  ft_isstr.c ft_isarr.c ft_isfloat.c ft_strisnum.c \
			  ft_strisfloat.c ft_isleadingzero.c ft_issign.c
ASCII		= $(addprefix $(ASCII_DIR)/, $(ASCII_FILES))

# GNL
GNL_FILES	= gnl.c supergnl.c
GNL			= $(addprefix $(GNL_DIR)/, $(GNL_FILES))

# LISTS
LISTS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			  ft_lstmap.c
LISTS		= $(addprefix $(LISTS_DIR)/, $(LISTS_FILES))

# MEMORY
MEMORY_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			   ft_memcmp.c ft_calloc.c
MEMORY		= $(addprefix $(MEMORY_DIR)/, $(MEMORY_FILES))

# NUMBERS
NUMBERS_FILES = ft_atoi.c ft_atof.c ft_itoa.c ft_digitcount.c ft_power.c \
				ft_sin.c ft_cos.c ft_sqrt.c ft_nan.c ft_naf.c
NUMBERS		= $(addprefix $(NUMBERS_DIR)/, $(NUMBERS_FILES))

# PRINTING
PRINTING_FILES = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putuint.c \
				 ft_puthex.c ft_putptr.c ft_putendl_fd.c ft_putnbr_fd.c \
				 ft_printf.c ft_putchar_fd.c ft_putstr_fd.c
PRINTING	= $(addprefix $(PRINTING_DIR)/, $(PRINTING_FILES))

# STRINGS
STRINGS_FILES = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
				ft_striteri.c ft_strcmp.c ft_strnchr.c
STRINGS		= $(addprefix $(STRINGS_DIR)/, $(STRINGS_FILES))

# VECTORS
VECTORS_FILES = vectors_builders.c vectors_push_pop_get.c vectors_sort.c \
				vectors_insert_remove.c vectors_func_args.c vectors_pend.c \
				vectors_printf.c vectors_destroyers.c vectors_utils.c
VECTORS		= $(addprefix $(VECTORS_DIR)/, $(VECTORS_FILES))

# ARENA
ARENA_FILES = arena_basic_utils.c arena_printing.c
ARENA		= $(addprefix $(ARENA_DIR)/, $(ARENA_FILES))

# SOURCES AND OBJECTS
SRC			= $(addprefix $(SRC_DIR)/, $(ASCII) $(GNL) $(LISTS) $(MEMORY) \
			  $(NUMBERS) $(PRINTING) $(STRINGS) $(VECTORS) $(ARENA))
OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_SUB		= $(sort $(dir $(OBJ)))

# LIBRARY HEADER
HEADER		= $(INC_DIR)/libft.h

# TOOLS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CFAST		= -O3
CDEBUG		= -g -O0
AR			= ar rcs
MKDIR		= mkdir -p
RMFILE		= rm -f
RMDIR		= rm -rf

# <<<<<<< MAIN TARGETS >>>>>>>

all: $(NAME)

$(NAME): $(OBJ)
	@echo "building $(LIBRARY)"
	@$(AR) $(NAME) $(OBJ)
	@echo "$(LIBRARY) compiled"

$(OBJ_SUB):
	@$(MKDIR) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

.SECONDARY	: $(OBJ) 

# <<<<<<< PHONY TARGETS >>>>>>>

clean:
	@echo "Removing $(LIBRARY) object files"
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@echo "Removing $(LIBRARY) static library files"
	@$(RMFILE) $(NAME)

re: fclean all

debug: CFLAGS += $(CDEBUG)
debug: CGENERAL :=
debug: CFAST :=
debug: re

fast: CFLAGS += $(CFAST)
fast: CGENERAL :=
fast: CDEBUG :=
fast: re

.PHONY: all clean fclean re debug fast
