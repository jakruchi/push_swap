NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

HEADER		= push_swap.h

SRCS		= push_swap.c cleaning.c compute_moves.c init_list.c \
		instructions.c list.c rotate.c safety.c stats.c utils.c

OBJS		= $(SRCS:.c=.o)

$(NAME)		: $(OBJS) $(HEADER)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o			: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

all			: $(NAME)

clean		:
		rm -f $(OBJS)

fclean		: clean
		rm -f $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
