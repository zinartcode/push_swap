# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 20:45:15 by azinnatu          #+#    #+#              #
#    Updated: 2018/01/23 21:58:36 by azinnatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS =	push_swap.o 			

LIBFT= libft/libft.a
LIBS = $(LIBFT)

HEADERS = ft_ls.h ./libft/includes/libft.h

CFLAGS += -Wall -Wextra -Werror -g

NAME = push_swap

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ): $(HEADERS)

clean: 
	@make -C libft/ fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all