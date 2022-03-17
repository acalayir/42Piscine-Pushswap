NAME	=	push_swap
MAIN	=	main.c
SRCS	=	push_swap_funcs.c short_sort.c utils.c push_swap_utils.c check_nums.c init.c
OBJS	=	$(MAIN:.c=.o) $(SRCS:.c=.o)
CHECKER_OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJS)
	gcc $(CFLAGS) libft/libft.a -o $(NAME) $(OBJS)

checker: fclean $(CHECKER_OBJS)
	 gcc $(CFLAGS) $(SRCS) checker.c libft/libft.a -o checker

bonus:	checker

clean:
	rm -rf $(NAME).a

fclean: clean
	rm -rf $(NAME).a $(OBJS)
	rm -rf push_swap
	rm -rf checker
	rm -rf checker.o

re: fclean all

.PHONY: all, clean, fclean, re, checker
