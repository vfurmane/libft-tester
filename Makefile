# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 19:06:20 by vfurmane          #+#    #+#              #
#    Updated: 2021/01/01 22:07:27 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(wildcard test/tests/ft_*_test.c)
OBJS		= $(SRCS:.c=.o)
EXEC		= $(OBJS:.o=.out)
INCL		= test/includes
LIBFT		= ../libft
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CP			= cp -f
RM			= rm -f

%.o:		%.c
			$(CP) $(LIBFT)/libft.h $(INCL)
			$(CC) $(CFLAGS) -c $< -I $(INCL) -o $@

%.out:		%.o
			mkdir -p outs
			$(CC) $(CFLAGS) $< test/unity/unity.c -I $(INCL) -L$(LIBFT) -lft -o outs/$(notdir $@)

all:		$(EXEC)

clean:
			$(RM) $(OBJS)
			$(RM) $(INCL)/libft.h

fclean:		clean
			$(RM) -r logs outs

re:			fclean all

checkfile:
			ls $(LIBFT)/$(FILE)

.PHONY:		all clean fclean re
.SECONDARY:	$(OBJS)
