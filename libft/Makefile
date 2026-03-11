NAME = libft.a

LIBFT_DIR = basics
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
OBJ_DIR = obj

LIBFT_SRC = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
		ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c \
		ft_strncmp.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c \
		ft_memset.c ft_memmove.c ft_strlcpy.c ft_itoa.c ft_strjoin.c \
		ft_split.c ft_striteri.c ft_strmapi.c \
		ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c  ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_atol.c

PRINTF_SRC = ft_printf.c print_str.c print_arg.c print_int.c test.c

GNL_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

SRC = $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC)) \
	$(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC)) \
	$(addprefix $(GNL_DIR)/, $(GNL_SRC))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = cc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I. -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(LIBFT_DIR)

all:	$(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
