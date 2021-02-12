# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 10:44:34 by juasanto          #+#    #+#              #
#    Updated: 2021/02/12 11:28:06 by juasanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	cube3d
LIBFT 		= 	libft.a
LIB_DIR		=	libft/
OBJ_DIR		=	obj/
SRC_DIR		=	sources/
SRC_FILES 	= 	cube3d.c \
				chk_args.c

SRC = $(SRC_FILES:%=$(SRC_DIR)%)
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LFLAGS = -I includes/
FLAGS = -Wall -Wextra -Werror -g
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

all:	$(OBJ_DIR) $(NAME)
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: Cube3D Object directory

$(NAME):	$(OBJ)
		@echo "$(CYAN)=========== Compilando LIBFT.A ==========="
		make -C $(LIB_DIR)
		# @cp $(LIB_DIR)$(LIBFT) ./$(NAME)
		# @$(AR) $(NAME) $(OBJ)
		@echo "$(YELLOW)=========== Compilando $(NAME) ==========="
		$(CC) $(FLAGS) $(LFLAGS) $(LIB_DIR)$(LIBFT) -o $(NAME) $(OBJ)
		@echo "=========== DONE ==========$(RESET)"

$(OBJ): $(SRC)
		@echo "$(GREEN)=========== Compilando Objects de $(NAME) ==========="
		@$(MAKE) $(OBJ_FILES)

		@echo "$(GREEN)=========== DONE ===========$(RESET)"

$(OBJ_FILES):
		$(CC) $(FLAGS) $(LFLAGS) -c -o $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
		@echo "$(GREEN)Compilando $@...$(RESET)"

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
