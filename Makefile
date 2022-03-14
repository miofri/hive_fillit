# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skesuma <skesuma@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 13:24:52 by skesuma           #+#    #+#              #
#    Updated: 2022/03/09 13:24:54 by skesuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = ./src

LIB_PATH = ./libft

SRC_NAME = fillit.c map.c solution.c block.c checker.c

LIB_NAME = ft_lstiter.c ft_putendl.c ft_striter.c ft_strequ.c\
	ft_lstmap.c ft_putendl_fd.c ft_striteri.c ft_strrchr.c \
	ft_atoi.c ft_lstnew.c ft_putnbr.c ft_strjoin.c ft_strsplit.c \
	ft_bzero.c ft_memalloc.c ft_putnbr_fd.c ft_strlcat.c ft_strstr.c \
	ft_isalnum.c ft_memccpy.c ft_putstr.c ft_strlen.c ft_strsub.c \
	ft_isalpha.c ft_memchr.c ft_putstr_fd.c ft_strmap.c ft_strtrim.c \
	ft_isascii.c ft_memcmp.c ft_strcat.c ft_strmapi.c ft_tolower.c \
	ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strncat.c ft_toupper.c \
	ft_isprint.c ft_memdel.c ft_strclr.c ft_strncmp.c \
	ft_itoa.c ft_memmove.c ft_strcmp.c ft_strncpy.c \
	ft_lstadd.c ft_memset.c ft_strcpy.c ft_strnequ.c \
	ft_lstdel.c ft_putchar.c ft_strdel.c ft_strnew.c \
	ft_lstdelone.c ft_putchar_fd.c ft_strdup.c ft_strnstr.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))

OFILES = $(SRC_NAME:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	@make -C libft/ all
	@$(CC) $(CFLAGS) -g -o $(NAME) $(OFILES) ./libft/libft.a

%.o: $(SRC_PATH)/%.c
	$(CC) -g -c $(CFLAGS) -o $@ $<

clean:
	@make -C libft/ clean
	@rm -rf $(OFILES)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
