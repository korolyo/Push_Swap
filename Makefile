
NAME	=	push_swap

SOURCES_LIST	= 	main.c\
					operations_one.c\
					operations_two.c\
					checkArgv.c\
					sorting_small.c\
					full_sort.c\
					sorting.c\
					error.c\
					math_util.c\
					rotations.c\
					presorted_array.c\
					pushing_a.c\
					operations_three.c\
					base_operations.c\

CC		= gcc
CFLAGS	=	-Werror -Wall -Wextra -g
LIBRARIES =	-lft\
	-L$(LIBFT_DIRECTORY) \

INCLUDES = -I$(LIBFT_HEADERS) -I$(HEADERS_DIR)

HEADERS_LIST = \
	push_swap.h
HEADERS_DIR	=	./includes/
HEADERS =	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

LIBFT	=	$(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

OBJECTS	=	$(patsubst %.c, %.o, $(SOURCES_LIST))

.PHONY:	all clean fclean re

all	: 	$(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
		@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
		@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
		@$(MAKE) clean -sC $(LIBFT_DIRECTORY)
		@rm -f $(OBJECTS)

fclean:	clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)

re:		fclean all
