# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 11:57:08 by pyathams          #+#    #+#              #
#    Updated: 2024/05/17 18:01:25 by pyathams         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of my program.
NAME    = libft.a

# Include directory
INC     = inc/

# Source and object directories
SRC_DIR = src/
OBJ_DIR = obj/

# The source files.
FTIS_DIR        =   $(SRC_DIR)ft_is/ft_isalnum.c \
                    $(SRC_DIR)ft_is/ft_isalpha.c \
                    $(SRC_DIR)ft_is/ft_isascii.c \
                    $(SRC_DIR)ft_is/ft_isdigit.c \
                    $(SRC_DIR)ft_is/ft_isprint.c 

FTMEM_DIR       =   $(SRC_DIR)ft_mem/ft_bzero.c \
                    $(SRC_DIR)ft_mem/ft_calloc.c \
                    $(SRC_DIR)ft_mem/ft_memchr.c \
                    $(SRC_DIR)ft_mem/ft_memcmp.c \
                    $(SRC_DIR)ft_mem/ft_memmove.c \
                    $(SRC_DIR)ft_mem/ft_memset.c 

FTPUT_DIR       =   $(SRC_DIR)ft_put/ft_putchar_fd.c \
                    $(SRC_DIR)ft_put/ft_putendl_fd.c \
                    $(SRC_DIR)ft_put/ft_putnbr_fd.c \
                    $(SRC_DIR)ft_put/ft_putstr_fd.c 

FTTO_DIR        =   $(SRC_DIR)ft_to/ft_atoi.c \
                    $(SRC_DIR)ft_to/ft_itoa.c \
                    $(SRC_DIR)ft_to/ft_tolower.c \
                    $(SRC_DIR)ft_to/ft_toupper.c

FTSTR_DIR       =   $(SRC_DIR)ft_str/ft_split.c \
                    $(SRC_DIR)ft_str/ft_strchr.c \
                    $(SRC_DIR)ft_str/ft_strdup.c \
                    $(SRC_DIR)ft_str/ft_striteri.c \
                    $(SRC_DIR)ft_str/ft_strjoin.c \
                    $(SRC_DIR)ft_str/ft_strlcat.c \
                    $(SRC_DIR)ft_str/ft_strlcpy.c \
                    $(SRC_DIR)ft_str/ft_strlen.c \
                    $(SRC_DIR)ft_str/ft_strmapi.c \
                    $(SRC_DIR)ft_str/ft_strncmp.c \
                    $(SRC_DIR)ft_str/ft_strnstr.c \
                    $(SRC_DIR)ft_str/ft_strrchr.c \
                    $(SRC_DIR)ft_str/ft_strtrim.c \
                    $(SRC_DIR)ft_str/ft_substr.c 

FTLST_DIR       =   $(SRC_DIR)ft_lst/ft_lstadd_back.c \
                    $(SRC_DIR)ft_lst/ft_lstadd_front.c \
                    $(SRC_DIR)ft_lst/ft_lstclear.c \
                    $(SRC_DIR)ft_lst/ft_lstdelone.c \
                    $(SRC_DIR)ft_lst/ft_lstiter.c \
                    $(SRC_DIR)ft_lst/ft_lstlast.c \
                    $(SRC_DIR)ft_lst/ft_lstmap.c \
                    $(SRC_DIR)ft_lst/ft_lstnew.c \
                    $(SRC_DIR)ft_lst/ft_lstsize.c 

FTPRINTF_DIR    =   $(SRC_DIR)ft_printf/ft_hexadecimal_util.c \
                    $(SRC_DIR)ft_printf/ft_printf_util.c \
                    $(SRC_DIR)ft_printf/ft_printf.c \
                    $(SRC_DIR)ft_printf/ft_putnbr_util.c \
                    $(SRC_DIR)ft_printf/ft_putptr_util.c \
                    $(SRC_DIR)ft_printf/ft_uputnbr_util.c \
                    $(SRC_DIR)ft_printf/print_char.c \

GNL_DIR         =   $(SRC_DIR)get_next_line/get_next_line.c \
                    $(SRC_DIR)get_next_line/get_next_line_utils.c 

SRC             = $(FTIS_DIR) $(FTMEM_DIR) $(FTPUT_DIR) $(FTTO_DIR) $(FTSTR_DIR) $(FTLST_DIR) $(FTPRINTF_DIR) $(GNL_DIR)

# The object files
OBJ             = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

# Compiler and flags
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror -I$(INC)
RM              = rm -f
AR              = ar rcs

# Default rule
all:            $(NAME)

# Rule to create the library
$(NAME):        $(OBJ)
	@echo "Creating library $(NAME)"
	@$(AR) $(NAME) $(OBJ)

# Rule to compile .c files into .o files
$(OBJ_DIR)%.o:  $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	@echo "Cleaning object files"
	@$(RM) -r $(OBJ_DIR)

# Rule to clean object files and the library
fclean: clean
	@echo "Cleaning library $(NAME)"
	@$(RM) $(NAME)

# Rule to rebuild everything
re:             fclean all

# Phony targets
.PHONY:         all clean fclean re