# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I . -I ft_printf -I get_next_line
REMOVE = rm -f

SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

BONUS_SRCS  = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

PRINTF_DIR = ft_printf
PRINTF_SRCS = $(PRINTF_DIR)/ft_printf.c \
			$(PRINTF_DIR)/ft_putchar.c \
			$(PRINTF_DIR)/ft_putstr.c \
			$(PRINTF_DIR)/ft_putnbr.c \
			$(PRINTF_DIR)/ft_putuint.c \
			$(PRINTF_DIR)/ft_puthex.c \
			$(PRINTF_DIR)/ft_putpntr.c

GNL_DIR = get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

# Rules
all: $(NAME) bonus

$(NAME): $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

bonus: $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(REMOVE) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
