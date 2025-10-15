NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

all: $(LIBFT) server client

$(LIBFT):
	make -C $(LIBFT_DIR)

server: $(OBJS_SERVER) minitalk.h $(LIBFT)
	$(CC) $(CFLAGS) -o server $(OBJS_SERVER) $(LIBFT)

client: $(OBJS_CLIENT) minitalk.h $(LIBFT)
	$(CC) $(CFLAGS) -o client $(OBJS_CLIENT) $(LIBFT)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
