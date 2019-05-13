# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 14:33:11 by mybenzar          #+#    #+#              #
#    Updated: 2019/05/13 15:17:47 by mybenzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc 

ifdef FLAGS
	ifeq ($(FLAGS), no)
	CFLAGS=
endif

ifeq ($(FLAGS), debug)
	CFLAGS= -Wall -Wextra -Werror -ansi -pedantic -g
endif

else
	CFLAGS = -Wall -Wextra -Werror
endif

TSTDIR = ./tests/
TEST = test.out
MAIN = main.c
#MAIN = main_test.c

LFTDIR = ./libft/
LFT = libft.a
HEADERS = ft_printf.h

SOURCES =	print_utils.c args_conv.c ft_printf.c print_float.c get_flags.c\
			parsing_utils.c get_size.c free_functions.c fill_padding.c\
			print_nb.c print_char.c print_str.c print_nb_padding.c get_res.c\
			get_res_l.c ft_frexp.c ft_ldftoa.c ft_frexpl.c ft_bintowhole.c\
			ft_bintodec.c vlq_pow.c get_exp.c get_exp_l.c float_converter.c\
			ft_round.c vlq_sum.c vlq_initialize.c vlq_conv.c vlq_shift.c\
			vlq_mult.c vlq_calc_info.c

OBJECTS = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(LFTDIR)$(LFT) $(OBJECTS)
	@echo "\033[92mCopy libftprintf.a in libft \033[0m"
	cp $< ./$@
	@echo "\033[92mCompilation\033[0m"
	$(CC) -c $(CFLAGS) $(SOURCES) -I $(HEADERS)
	ar -r $@ $(OBJECTS)
	ranlib $@
	@echo "\033[92mName Created \033[0m"

$(LFTDIR)$(LFT):
	@echo "\033[92mLibft Make \033[0m"
	cd $(LFTDIR) && (MAKE)

clean:
	@echo "\033[92mClean Objects & Libft Objects\033[0m"
	cd $(LFTDIR) && (MAKE)
	rm -fv $(OBJECTS)
	@rm -f $(TSTDIR)$(MAIN:.c=.o)
	$(MAKE) -C $(LFTDIR) clean

fclean: clean
	@echo "\033[92mClean Objects & Names V\033[0m"
	rm -fv $(NAME)
	#rm -f libftprintf.a
	cd $(LFTDIR) && rm -f libft.a

re:	fclean all

test: $(NAME)
	@echo "\033[92mRecompiling for test\033[0m"
	$(CC) $(CFLAGS) -c $(TSTDIR)$(MAIN) -o $(TSTDIR)$(MAIN:.c=.o)
	$(CC) $(OBJECTS) $(TSTDIR)$(MAIN:.c=.o) -lftprintf -L./ -o $(TEST)
	@echo "\033[92mDone!\033[0m"

.PHONY: clean fclean

