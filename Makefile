SRCS	=	$(DIR)/int_list.c \
			$(DIR)/args.c \
			$(DIR)/operations.c \
			$(DIR)/free.c

DIR		=	./srcs

INCLUDE	=	-I .

OBJS	:=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

FSAN	=	-g3 -fsanitize=address

NAME	=	push_swap

LIBFT	=	libft/libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJS) main.c
			@make -C ./libft
			$(CC) $(CFLAGS) -g3 main.c $(OBJS) $(LIBFT) $(INCLUDE) -o $(NAME)

fsan	:	$(OBJS) main.c
			@make -C ./libft
			$(CC) $(CFLAGS) $(FSAN) main.c $(OBJS) $(LIBFT) $(INCLUDE) -o $(NAME)

leaks	:	$(NAME)
			valgrind --tool=memcheck --track-origins=yes --leak-check=full --leak-resolution=high --show-reachable=yes ./$(NAME)

clean	:
			@make clean -C ./libft
			rm -rf $(OBJS)

fclean	:	clean
			@make fclean -C ./libft
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all fsan leaks clean fclean re