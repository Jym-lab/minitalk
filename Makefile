# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 14:27:36 by yjoo              #+#    #+#              #
#    Updated: 2022/05/27 14:27:36 by yjoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FSANI = -g3 -fsanitize=address
RM = rm -f
SERVER = server
CLIENT = client

LIBFT_FILES = ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_atoi.c
LIB_PATH = ./libft/
LIB_SRCS = $(addprefix $(LIB_PATH), $(LIBFT_FILES))
LIB_OBJS = $(LIB_SRCS:.c=.o)

INCLUDE = -I./include
SRCS_PATH = ./srcs
SERVER_FILES = server.c
CLIENT_FILES = client.c
SERVER_SRCS = $(addprefix $(addsuffix /, $(SRCS_PATH)), $(SERVER_FILES))
SERVER_SRCS_BONUS = $(addprefix $(addsuffix /, $(SRCS_PATH)), $(patsubst %.c, %_bonus.c, $(SERVER_FILES)))
CLIENT_SRCS = $(addprefix $(addsuffix /, $(SRCS_PATH)), $(CLIENT_FILES))
CLIENT_SRCS_BONUS = $(addprefix $(addsuffix /, $(SRCS_PATH)), $(patsubst %.c, %_bonus.c, $(CLIENT_FILES)))
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_SRCS_BONUS:.c=.o)


ifdef WITH_BONUS
	SER_OBJS = $(SERVER_BONUS_OBJS)
	CLI_OBJS = $(CLIENT_BONUS_OBJS)
else
	SER_OBJS = $(SERVER_OBJS)
	CLI_OBJS = $(CLIENT_OBJS)
endif

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIB_OBJS) $(SER_OBJS)
		$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

$(CLIENT): $(LIB_OBJS) $(CLI_OBJS)
		$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

bonus: 
		make WITH_BONUS=1 all

re: fclean all

clean:
		$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS) $(LIB_OBJS)

fclean: clean
		$(RM) $(SERVER) $(CLIENT)

.PHONY: all re clean fclean
