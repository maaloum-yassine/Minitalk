# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 18:15:01 by ymaaloum          #+#    #+#              #
#    Updated: 2024/05/21 03:41:12 by ymaaloum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: $(CLIENT) $(SERVER)

$(CLIENT) :
		$(CC) $(CFLAGS) src/client.c src/utils.c -o client
$(SERVER) :
		$(CC) $(CFLAGS) src/server.c src/utils.c -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) :
		$(CC) $(CFLAGS) src/client_bonus.c src/utils.c -o client_bonus
$(SERVER_BONUS) :
		$(CC) $(CFLAGS) src/server_bonus.c src/utils.c -o server_bonus
clean:
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
fclean: clean

re: fclean all bonus
.PHONY: clean all re fclean bonus
