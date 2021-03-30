# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juasanto <juasanto>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 10:44:34 by juasanto          #+#    #+#              #
#    Updated: 2021/03/30 19:05:09 by juasanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = %.o obj

NAME 		= 	cub3D
LIBFT 		= 	libft.a
LIB_DIR		=	libft/
MINI_LIB	=	libmlx.dylib
MINI_DIR	=	minilibx/
OBJ_DIR		=	obj/
SRCS_DIR	=	sources/
SRCS		= 	cube3d.c \
				utils_file.c \
				chk_args.c \
				chk_file.c \
				chk_rfc.c \
				wrk_map.c \
				cls_map.c

SOURCES = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(SOURCES:.c=.o)

LFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror -g
CC = cc
RM = rm -rf
AR = ar rc
RANLIB = ranlib
NORM = /usr/bin/norminette

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m



all: $(OBJ_DIR) $(NAME)
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: Cube3D Object directory

$(NAME): $(OBJS)
		@echo "$(CYAN)=========== Compilando LIBFT.A ==========="
		make -C $(LIB_DIR)
		@echo "=========== DONE ==========$(RESET)"
		@echo "$(BLUE)=========== Compilando minilibX ==========="
		make -C $(MINI_DIR)
		@echo "=========== DONE ==========$(RESET)"

		@echo "$(YELLOW)=========== Compilando $(NAME) ==========="
		cp $(MINI_DIR)$(MINI_LIB) .
		$(CC) $(CFLAGS) $(LFLAGS) $(LIB_DIR)$(LIBFT) $(MINI_LIB) -o $(NAME) $(OBJS)
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
		make -C $(MINI_DIR) clean
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
