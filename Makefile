PUSH_SWAP	= push_swap

SRC			= push_swap.c parse_arguments.c sort.c utils.c ft_isint.c ft_emalloc.c normalization.c operations.c sort_big_stack.c

OBJ			= $(SRC:.c=.o)

HDR			= push_swap.h

INCLUDES	= .

CC			= gcc
FLAGS		= -Wall -Werror -Wextra

LIB	 		= -L./libft -lft
LIBFT		= libft.a

all : $(LIBFT) $(PUSH_SWAP)

$(LIBFT):
	make -C libft

$(PUSH_SWAP): $(OBJ) $(HDR)
	$(CC) $(OBJ) $(LIB) -o $@

%.o: %.c $(HDR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(PUSH_SWAP)

re: fclean all