NAME		:= philo
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -pthread

# Directories
SRC_DIRS	:= src
OBJ_DIR		:= build
INCLUDE_DIRS	:= includes
INCLUDES	:= $(foreach dir,$(INCLUDE_DIRS),-I$(dir))

# Colors
GREEN 		:= \033[0;32m
YELLOW		:= \033[0;33m
RED			:= \033[0;31m
BLUE		:= \033[0;34m
RESET		:= \033[0m

# Files
SRC		:= 	src/main.c \
			src/parse.c \
			src/data_init.c \
			src/monitor.c \
			src/routine.c \
			src/thread.c \
			src/time_control.c \
			src/utils.c \
			src/data_cleanup.c
OBJ		:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

$(NAME): $(OBJ)
	@echo "$(YELLOW)🔧 Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lpthread
	@echo "$(GREEN)✅ $(NAME) built successfully$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# rules
all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)🧴 Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🧼 Everything cleaned$(RESET)"

re: fclean all

norminette:
	@echo "$(YELLOW)🧠 Running norminette...$(RESET)"
	@norminette $(SRC) $(INCLUDES) -R CheckForbiddenSourceHeader || true

.PHONY: all clean fclean re norminette