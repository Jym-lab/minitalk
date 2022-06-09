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

all: lib $(SERVER) $(CLIENT)

$(SERVER): $(SER_OBJS)
		$(CC) $(CFLAGS) $(INCLUDE) $^ libft/libft.a -o $@

$(CLIENT): $(CLI_OBJS)
		$(CC) $(CFLAGS) $(INCLUDE) $^ libft/libft.a -o $@

lib:
	@make -C libft all
	@echo "libft_success"

bonus: 
		make WITH_BONUS=1 all

re: fclean all

clean:
		$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)
		@make clean -C libft

fclean: clean
		$(RM) $(SERVER) $(CLIENT)
		rm -f libft/libft.a

.PHONY: all re clean fclean
