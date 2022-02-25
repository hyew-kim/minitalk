CC = gcc
CFLAGS = -g
CFLAGS2 = -Wall -Wextra -Werror
SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

NAME = minitalk

all: $(NAME)

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) bonus -C libft

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f server client
	$(MAKE) -C libft fclean

re: fclean all

$(NAME): server client

.PHONY: all libft clean fclean re