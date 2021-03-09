# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 10:44:34 by juasanto          #+#    #+#              #
#    Updated: 2021/03/08 17:41:39 by jcsantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = %.o obj

NAME 		= 	cub3D
LIBFT 		= 	libft.a
LIB_DIR		=	libft/
OBJ_DIR		=	obj/
SRCS_DIR	=	sources/
SRCS		= 	cube3d.c \
				utils_file.c \
				chk_args.c \
				chk_file.c \
				chk_textures.c \
				chk_rfc.c \
				chk_value.c \
				structs.c

SOURCES = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(SOURCES:.c=.o)

LFLAGS = -I includes/
CFLAGS = -g #-Wall -Wextra -Werror -g
CC = cc
RM = rm -rf
AR = ar rc
RANLIB = ranlib
NORM = /usr/bin/norminette

RESET = \033[0m
YELLOW = \033[33m
CYAN = \033[36m
GREEN = \033[32m
PINK = \033[35m
RED = \033[31m

all: $(OBJ_DIR) $(NAME)
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: Cube3D Object directory

$(NAME): $(OBJS)
		@echo "$(CYAN)=========== Compilando LIBFT.A ==========="
		make -C $(LIB_DIR)
		@echo "=========== DONE ==========$(RESET)"

		@echo "$(YELLOW)=========== Compilando $(NAME) ==========="
		$(CC) $(CFLAGS) $(LFLAGS) $(LIB_DIR)$(LIBFT) -o $(NAME) $(OBJS)
		@echo "=========== DONE ==========$(RESET)"


test: re
		@echo "$(YELLOW)=========== Compilando TEST ==========="
		@$(CC) $(FLAGS) -c sources/main.c -o obj/main.o
		@$(CC) $(FLAGS) -o ft_printf.out $(NAME) obj/main.o
		@echo "$(YELLOW)=========== DONE ===========$(RESET)"
clean:
		@echo "$(PINK)========== CLEAN =========="
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		make -C $(LIB_DIR) clean
		@echo "$(PINK)=========== DONE ===========$(RESET)"
fclean: clean
		@echo "$(RED)========== FCLEAN =========="
		$(RM) $(NAME)
		$(RM) ft_printf.out
		make -C $(LIB_DIR) fclean
		@echo "$(RED)=========== DONE ===========$(RESET)"
re: fclean all
norm: all
		$(NORM) $(SRC);
.PHONY: all clean fclean re
