NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
	ft_toupper.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c \
	ft_printf.c ft_putstr_cnt.c ft_putlong_cnt.c ft_puthex_cnt.c ft_putuint_cnt.c \
	get_next_line.c get_next_line_utils.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
            ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

FLAGS = -Wall -Wextra -g -Werror

CC = cc

CLEAN = rm -f

OBJ := $(SRCS:.c=.o)

OBJ_BONUS := $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	$(CC) -g $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rsc $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

$(OBJ_BONUS): %.o: %.c
	$(CC) -g $(FLAGS) -c $< -o $@

clean:
	@$(CLEAN) $(OBJ) $(OBJ_BONUS)
	@echo "Clean: objetos eliminados"

fclean: clean
	@$(CLEAN) $(NAME)
	@echo "Fclean: $(NAME) eliminado"

re: fclean all

.PHONY: all clean fclean re bonus