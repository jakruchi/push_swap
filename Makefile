NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= push_swap.c instructions.c list_functions.c

HEADER		= push_swap.h

$(NAME)		: $(SRCS) $(HEADER)
		@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
		@echo "Compilation complete"

all			: $(NAME)

clean		:
		@echo "Nothing to clean."

fclean		:
		@rm -f $(NAME)
		@echo "Cleaned up"

re			: fclean all
		@echo "Recompiled"

.PHONY		: all clean fclean re
