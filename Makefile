CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c client.c
BONUS_SRCS = server_bonus.c client_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = minitalk

all: $(NAME)

bonus: server_bonus client_bonus

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

server_bonus: server_bonus.o libft/libft.a
	$(CC) -o $@ $< -Llibft -lft

client_bonus: client_bonus.o libft/libft.a
	$(CC) -o $@ $< -Llibft -lft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) bonus -C libft

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f server client
	rm -f server_bonus client_bonus
	$(MAKE) -C libft fclean

re: fclean all

$(NAME): server client

.PHONY: all bonus libft clean fclean re