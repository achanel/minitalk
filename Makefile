NAME	= server

CLIENT	= client

HEADER = minitalk.h

SRC	= src/ft_strlen.c src/ft_strdup.c src/ft_itoa.c src/ft_putchar_fd.c src/ft_putstr_fd.c \
			src/ft_atoi.c src/ft_strjoin.c

CC			= gcc
RM			= rm -f

CFLAGS	= -Wall -Wextra -Werror

$(NAME):
					@$(CC) $(CFLAGS) -I $(HEADER) $(SRC) server.c -o $(NAME) $?
					@$(CC) $(CFLAGS) -I $(HEADER) $(SRC) client.c -o $(CLIENT) $?
		
all:		${NAME}

bonus:
					@$(CC) $(CFLAGS) -I $(HEADER) $(SRC) ./bonus/server_bonus.c -o $(NAME) $?
					@$(CC) $(CFLAGS) -I $(HEADER) $(SRC) ./bonus/client_bonus.c -o $(CLIENT) $?

clean:
					${RM} src/*.o
					${RM} *.o

fclean:		clean
					${RM} ${NAME} ${CLIENT}

re:					fclean all

.PHONY:		all clean fclean re bonus