# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 19:06:20 by vfurmane          #+#    #+#              #
#    Updated: 2021/01/10 21:48:01 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(wildcard test/tests/ft_*_test.c)
BON_SRCS		= $(wildcard test/tests/bonus/ft_*_test.c)
OBJS			= $(SRCS:.c=.o)
BON_OBJS		= $(BON_SRCS:.c=.o)
EXEC			= $(patsubst test/tests/%, outs/%, $(OBJS:.o=.out))
BON_EXEC		= $(patsubst test/tests/bonus/%, outs/%, $(BON_OBJS:.o=.out))
INCL			= test/includes
LIBFT			= ../libft
CC				= clang
CFLAGS			= -Wall -Wextra -Werror
CP				= cp -f
RM				= rm -f
MKDIR			= mkdir -p

%.o:			%.c
				$(CP) $(LIBFT)/libft.h $(INCL)
				$(CC) $(CFLAGS) -c $< -I $(INCL) -o $@

outs/%.out:		test/tests/%.o
				$(CC) $(CFLAGS) $< test/unity/unity.c -I $(INCL) -lbsd -L$(LIBFT) -lft -o outs/$(notdir $@)

outs/%.out:		test/tests/bonus/%.o
				$(CC) $(CFLAGS) $< test/unity/unity.c -I $(INCL) -L$(LIBFT) -lft -o outs/$(notdir $@)

all:			make_out $(EXEC)

bonus:			make_out $(BON_EXEC)

make_out:
				$(MKDIR) outs/

clean:
				$(RM) $(OBJS)
				$(RM) $(INCL)/libft.h

fclean:			clean
				$(RM) -r logs outs

re:				fclean all

checkfile:
				ls $(LIBFT)/$(FILE)

libft:
				cd $(LIBFT) && make

bon_libft:
				cd $(LIBFT) && make bonus

.PHONY:			all clean fclean re checkfile
.SECONDARY:		$(OBJS)
