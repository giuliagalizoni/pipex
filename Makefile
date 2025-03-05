NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MANDATORY_DIR = ./mandatory
BONUS_DIR = ./bonus
SRC_DIR = /src

SRCS = \
	$(MANDATORY_DIR)$(SRC_DIR)/pipex.c \
	$(MANDATORY_DIR)$(SRC_DIR)/utils.c \

BONUS_SRCS = \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

all: $(LIBFT) $(NAME)
	@echo "$(GREEN)$(NAME) is ready!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

bonus: $(LIBFT) $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) is ready!$(RESET)"

$(NAME_BONUS): $(BONUS_OBJS)
	@echo "$(YELLOW)Compiling $(NAME_BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT)

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(YELLOW)Full cleaning...$(RESET)"
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
