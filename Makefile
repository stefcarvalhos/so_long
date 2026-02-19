# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:48:13 by stda-sil          #+#    #+#              #
#    Updated: 2025/04/15 17:46:00 by stda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lm -lmlx -lXext -lX11
LIBFTDIR = Libft
RM = rm -rf
SRCS = checkgame.c \
checkmap.c \
map.c \
so_long.c \
keyboard.c \
render.c \
utils.c


OBJS = $(SRCS:.c=.o)

INCLUDE = -L ./Libft -L mlx

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@make -s -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ${INCLUDE} -lft $(MLXFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make -s -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -s -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
