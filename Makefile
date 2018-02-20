SHARED_SRCS = 	check_int.c	\
				swap_stack.c \
				rotate_stack.c \
				reverse_stack.c	\
				utilities.c	\
				presort.c \
				short_sort.c \
				long_sort.c \
				ft_array_helper.c \
				create_list.c \
				check_list.c \
				check_list2.c

CHECKER_SRCS = checker.c
PUSH_SWAP_SRCS = push_swap.c \

vpath %.c ./srcs

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -g
CHECKER = checker
PUSH_SWAP = push_swap
LIBFT = ./libft/libft.a

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(CHECKER_SRCS:.c=.o) $(SHARED_SRCS:.c=.o) $(LIBFT)
	$(CC) -o $(CHECKER) $(CHECKER_SRCS:.c=.o) $(SHARED_SRCS:.c=.o) -L $(dir $(LIBFT)) -lft

$(PUSH_SWAP): $(PUSH_SWAP_SRCS:.c=.o) $(SHARED_SRCS:.c=.o) $(LIBFT)
	$(CC) -o $(PUSH_SWAP) $(PUSH_SWAP_SRCS:.c=.o) $(SHARED_SRCS:.c=.o) -L $(dir $(LIBFT)) -lft

$(LIBFT):
	make -C $(dir $(LIBFT))

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $< -I ./includes/ -I $(addsuffix includes/, $(dir $(LIBFT)))

clean:
	rm -f $(SHARED_SRCS:.c=.o)
	rm -f $(PUSH_SWAP_SRCS:.c=.o)
	rm -f $(CHECKER_SRCS:.c=.o)
	make -C $(dir $(LIBFT)) clean

fclean: clean
	rm -f $(CHECKER)
	rm -f $(PUSH_SWAP)
	make -C $(dir $(LIBFT)) fclean

re: fclean all
