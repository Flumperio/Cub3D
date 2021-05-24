# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juasanto <juasanto>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 10:44:34 by juasanto          #+#    #+#              #
#    Updated: 2021/05/24 17:30:18 by juasanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		=	cub3D
BONUS_NAME	=	cub3D
LIBFT 		=	libft.a
LIB_DIR		=	libft/
MINI_LIB	=	libmlx.dylib
MINI_DIR	=	minilibx/
SRCS_DIR	=	sources/
BONUS_DIR	=	bonus/
SRCS		= 	cube3d.c \
				utils_file.c \
				chk_args.c \
				chk_file.c \
				chk_rfc.c \
				wrk_map.c \
				cls_map.c \
				raycast_1.c \
				raycast_2.c \
				raycast_3.c \
				raycast_utils.c \
				raycast_print.c \
				key_mng.c \
				move_1.c \
				move_2.c \
				sprite.c \
				merge.c \
				screen_capture.c
BNS			= 	cube3d_bonus.c \
				utils_file_bonus.c \
				chk_args_bonus.c \
				chk_file_bonus.c \
				chk_rfc_bonus.c \
				wrk_map_bonus.c \
				cls_map_bonus.c \
				raycast_1_bonus.c \
				raycast_2_bonus.c \
				raycast_3_bonus.c \
				raycast_utils_bonus.c \
				raycast_print_bonus.c \
				key_mng_bonus.c \
				move_1_bonus.c \
				move_2_bonus.c \
				sprite_bonus.c \
				merge_bonus.c \
				screen_capture_bonus.c

SOURCES = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(SOURCES:.c=.o)
BONUS_SOURCES = $(addprefix $(BONUS_DIR), $(BNS))
BONUS_OBJS = $(BONUS_SOURCES:.c=.o)

LFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror -g -O3
CC = gcc
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

all: $(NAME)

bonus: $(BONUS_OBJS)
		@echo "$(CYAN)=========== Compilando LIBFT.A ==========="
		make -C $(LIB_DIR)
		@echo "=========== DONE ==========$(RESET)"
		@echo "$(BLUE)=========== Compilando minilibX ==========="
		make -C $(MINI_DIR)
		@echo "=========== DONE ==========$(RESET)"
		@echo "$(YELLOW)=========== Compilando Bonus $(NAME) ==========="
		cp $(MINI_DIR)$(MINI_LIB) .
		$(CC) $(CFLAGS) $(LFLAGS) $(LIB_DIR)$(LIBFT) $(MINI_LIB) -o $(BONUS_NAME) $(BONUS_OBJS)
		@echo "=========== DONE ==========$(RESET)"

test: re
		@echo "$(YELLOW)=========== Compilando TEST ==========="
		@$(CC) $(FLAGS) -c sources/main.c -o obj/main.o
		@$(CC) $(FLAGS) -o ft_printf.out $(NAME) obj/main.o
		@echo "$(YELLOW)=========== DONE ===========$(RESET)"
clean:
		@echo "$(PINK)========== CLEAN =========="
		$(RM) $(OBJS)
		$(RM) $(BONUS_OBJS)
		make -C $(LIB_DIR) clean
		make -C $(MINI_DIR) clean
		@echo "$(PINK)=========== DONE ===========$(RESET)"
fclean: clean
		@echo "$(RED)========== FCLEAN =========="
		$(RM) $(NAME)
		$(RM) cub3D
		make -C $(LIB_DIR) fclean
		@echo "$(RED)=========== DONE ===========$(RESET)"
re: fclean all
norm: all
		$(NORM) $(SRC);
.PHONY: all clean fclean re
