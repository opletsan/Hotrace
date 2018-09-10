#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 19:03:18 by akokoshk          #+#    #+#              #
#    Updated: 2017/10/02 19:03:22 by akokoshk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = hotrace

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo "hotrace compiled"

clean:
	@rm -f $(OBJECTS)
	@echo "cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "fcleaned"

re:	fclean all
