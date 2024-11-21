NAME =		gnl.a
CC =		cc
CFLAGS =	-Wall -Wextra -Werror -I. -I$(INC_DIR)
SRC_DIR =	src
OBJ_DIR =	obj
INC_DIR =	inc

FILES = get_next_line.c get_next_line_utils.c

BONUS_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
BONUS = $(addprefix $(SRC_DIR)/, $(BONUS_FILES))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
