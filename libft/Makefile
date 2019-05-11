#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malavent <malavent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:46:05 by malavent          #+#    #+#              #
#    Updated: 2019/05/11 12:21:00 by mybenzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADERS = libft.h

SRCS =	ft_bzero.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_toupper.c\
		ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_strdup.c\
		ft_strlen.c ft_strnew.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c\
		ft_strlcat.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl_fd.c\
		ft_putendl_fd.c ft_putendl.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strdel.c ft_putstr_fd.c\
		ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_isdigit.c\
		ft_strmap.c ft_strmapi.c  ft_strncmp.c ft_atoi.c ft_isalpha.c\
		ft_strnequ.c ft_strnew.c ft_strrchr.c ft_strsplit.c ft_isascii.c\
		ft_strstr.c ft_strnstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
		ft_isalnum.c ft_isprint.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
		ft_lstadd.c ft_lstmap.c ft_lstiter.c ft_power.c ft_atoi_base.c\
		ft_strnlen.c ft_lstsort.c ft_lstswap_content.c ft_lst_pushback.c\
		ft_lstsize.c ft_itoabase.c ft_convert_itoc.c ft_numlen_base.c\
		ft_convert_dec.c ft_intsize.c ft_strjoin_free.c ft_swap.c ft_strrev.c\
		ft_putnstr.c ft_strupper.c print_nchar.c ft_dftoa.c\

OBJS =  ft_bzero.o ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o\
		ft_memcpy.o ft_memdel.o ft_memmove.o ft_strlen.o ft_strnew.o ft_isascii.o\
		ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strncat.o ft_strlcat.o\
		ft_strcat.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl_fd.o\
		ft_putendl_fd.o ft_putendl.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o\
		ft_strchr.o ft_strclr.o ft_strcmp.o  ft_strdel.o ft_strdup.o ft_isalpha.o\
		ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_putstr_fd.o\
		ft_strlen.o ft_strmap.o ft_strmapi.o  ft_strncmp.o ft_atoi.o ft_toupper.o\
		ft_strnequ.o ft_strnew.o ft_strrchr.o ft_strsplit.o ft_isdigit.o\
		ft_strstr.o ft_strsub.o ft_strtrim.o ft_strnstr.o ft_tolower.o\
		ft_isalnum.o ft_isprint.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o\
		ft_lstadd.o ft_lstmap.o ft_lstiter.o ft_power.o ft_atoi_base.o\
		ft_strnlen.o ft_lstsort.o ft_lstswap_content.o ft_lst_pushback.o\
		ft_lstsize.o ft_itoabase.o ft_convert_itoc.o ft_numlen_base.o\
		ft_convert_dec.o ft_intsize.o ft_strjoin_free.o ft_swap.o ft_strrev.o\
		ft_putnstr.o ft_strupper.o print_nchar.o ft_dftoa.o\

all : $(NAME)

$(NAME) :
	$(CC) -c $(FLAGS) $(SRCS) -I $(HEADERS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
