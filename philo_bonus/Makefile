# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 23:06:59 by aghalmi           #+#    #+#              #
#    Updated: 2025/12/29 23:38:05 by aghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -pthread -I./include

SRCS =  srcs/main_bonus.c \
		srcs/parsing_bonus.c \
		srcs/time_bonus.c \
		srcs/init_bonus.c \
		srcs/processus_bonus.c \
		srcs/routine_bonus.c \
		srcs/routine2_bonus.c \
		srcs/check_bonus.c \
		srcs/free_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus