NAME = minitalk

SERVER = server
CLIENT = client

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj

SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC = $(SRC_DIR)/client.c

SERVER_OBJ = $(OBJ_DIR)/server.o
CLIENT_OBJ = $(OBJ_DIR)/client.o

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I$(LIBFT_DIR)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $< $(LIBFT) -o $@

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $< $(LIBFT) -o $@

# //$(NAME): $(OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
