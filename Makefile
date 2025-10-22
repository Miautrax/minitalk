# **************************************************************************** #
# Makefile para minitalk
# **************************************************************************** #

NAME_S = server
NAME_C = client

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_S = server.c
SRCS_C = client.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

all: $(LIBFT) $(NAME_S) $(NAME_C)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_S): $(SRCS_S) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -o $(NAME_S) $(SRCS_S) $(LIBFT)

$(NAME_C): $(SRCS_C) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -o $(NAME_C) $(SRCS_C) $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS_S) $(OBJS_C)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
