# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 19:06:20 by vfurmane          #+#    #+#              #
#    Updated: 2020/12/30 19:06:21 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(addprefix test/tests/, ft_atoi_test.c)
OBJS		= $(SRCS:.c=.o)
EXEC		= $(OBJS:.o=.out)
INCL		= test/includes
LIBFT		= ../libft # Change this value according to the libft directory
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -I $(INCL) -o $@

%.out:		%.o
			mkdir -p outs
			$(CC) $(CFLAGS) $< test/unity/unity.c -I $(INCL) -L$(LIBFT) -lft -o outs/$(notdir $@)

all:		$(EXEC)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) -r logs outs

re:			fclean all

.PHONY:		all clean fclean re
.SECONDARY:	$(OBJS)
