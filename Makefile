# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 14:52:07 by guvascon          #+#    #+#              #
#    Updated: 2025/04/23 17:11:22 by guvascon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/fractol.c srcs/init.c srcs/math_utils.c srcs/render.c \
		srcs/string_utils.c
		
OBJS = $(SRCS:.c=.o)

CC = @cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

# PRINTF_PATH = ./ft_printf
# PRINTF = $(PRINTF_PATH)/libftprintf.a
# LIBFT_PATH = ./Libft
# LIBFT = $(LIBFT_PATH)/libft.a

NAME = fractol

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a 
MLXFLAGS = -lXext -lX11

all : $(NAME) 
$(NAME) : $(OBJS)  $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLXFLAGS) -o $(NAME)

$(MLX):
	@make -s -C ./minilibx-linux
	
clean:
	@$(RM) $(OBJS) 
	@$(RM) $(LIBFT_PATH)/*.o
	@echo "all objects were removed"
	
fclean: clean
	@$(RM) $(NAME)
	clear
	@echo "all files were removed"

re: fclean $(NAME)
	clear
	@echo "bla bla bla"
	
.PHONY: all clean fclean re bonus