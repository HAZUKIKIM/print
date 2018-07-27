# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 10:53:12 by hmiyake           #+#    #+#              #
#    Updated: 2018/07/25 22:50:25 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

SRCO = *.o

INCLUDES = ft_printf.h

all: $(NAME)

$(NAME):
	@gcc -c $(SRCS) -I$(INCLUDES)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
