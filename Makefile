# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 14:52:07 by guvascon          #+#    #+#              #
#    Updated: 2025/04/25 14:28:22 by guvascon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fractol.c init.c math_utils.c render.c \
		string_utils.c events.c
		
OBJS = $(SRCS:.c=.o)

CC = @cc
CFLAGS = -g -Wall -Wextra -Werror -g -O3 -march=native -flto -ftree-vectorize -funroll-loops -ffast-math
MLXFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -f

# PRINTF_PATH = ./ft_printf
# PRINTF = $(PRINTF_PATH)/libftprintf.a
# LIBFT_PATH = ./Libft
# LIBFT = $(LIBFT_PATH)/libft.a

NAME = fract_ol

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a 
# MLXFLAGS = -lXext -lX11

all : $(NAME) 
$(NAME) : $(OBJS)  $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLXFLAGS) -o $(NAME)

$(MLX):
	@make -s -C ./minilibx-linux
	
clean:
	@$(RM) $(OBJS) 
	# @$(RM) $(MLX_DIR)/*.o
	@echo "all objects were removed"
	
fclean: clean
	@$(RM) $(NAME)
	clear
	@echo "all files were removed"

re: fclean $(NAME)
	clear
	@echo "bla bla bla"
	
.PHONY: all clean fclean re bonus