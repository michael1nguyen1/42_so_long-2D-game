# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 15:46:54 by linhnguy          #+#    #+#              #
#    Updated: 2024/02/27 15:41:29 by linhnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBMLX = MLX42
HEADERS	= -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
LIBFT = libft.a
LIBFTDIR = libft

CC = cc -g3
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
DEBUG_CFLAGS = -fsanitize=address -g3
SRCS =	so_long.c game.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: libmlx $(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) $(LIBFTDIR)/$(LIBFT) -o $(NAME)
	@echo "Program Made"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4;

debug: re
	$(CC) $(OBJS) $(LIBS) $(HEADERS) $(DEBUG_CFLAGS) $(LIBFTDIR)/$(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean
	@echo "Cleaned object files"

fclean: clean
	$(RM) $(NAME)
	rm -rf $(LIBMLX)/build/libmlx42.a
	@make -C $(LIBFTDIR) fclean
	@echo "Fully Cleaned"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, debug
