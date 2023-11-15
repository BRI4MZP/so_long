# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briveiro <briveiro@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 04:49:40 by briveiro          #+#    #+#              #
#    Updated: 2023/11/08 20:06:47 by briveiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c \
	  ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_strrchr.c ft_itoa.c\
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_split.c\
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  get_next_line_bonus.c get_next_line_utils_bonus.c
	

SRCBONUS =	ft_lstnew.c ft_lstadd_font.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c


CC = gcc


CCFLAGS = -Wall -Wextra


OBJS = $(SRC:.c=.o)

OBJSBONUS = $(SRCBONUS:.c=.o)

CLEAR = rm -f


all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME):
	@gcc -c $(CCFLAGS) $(SRC)
	@ar rcs $(NAME) $(OBJS)
	@echo "Se ha compilado perfectamente ✅"

clean:
	@rm -f $(OBJS) $(OBJSBONUS)
	@echo "Se ha borrado todo :D"


fclean: clean
		@rm -f $(NAME)

bonus:

	@gcc -c $(CCFLAGS) $(SRCBONUS)
	@ar rcs $(NAME) $(OBJSBONUS)
	
re: fclean all

.PHONY: all fclean clean bonus re
