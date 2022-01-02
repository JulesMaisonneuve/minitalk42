NAMES = server client

OBJS = *.o

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: server client

client: client.o ft_printf
	$(CC) $(CFLAGS) -o client client.o -L./ft_printf -lftprintf

server: server.o ft_printf
	$(CC) $(CFLAGS) -o server server.o -L./ft_printf -lftprintf

ft_printf:
	make -C ft_printf

clean:
	$(RM) $(OBJS)
	make -C ft_printf clean

fclean: clean
	$(RM) $(NAMES) ft_printf/libftprintf.a

re: fclean all

.PHONY: all ft_printf clean fclean re