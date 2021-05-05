# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 16:41:37 by tsomeya           #+#    #+#              #
#    Updated: 2021/04/26 11:41:01 by tsomeya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		=	src/ft_utils.c			\
				src/ft_utils2.c			\
				src/ft_utils3.c			\
				src/ft_print_perc.c		\
				src/ft_print_char.c		\
				src/ft_print_int.c		\
				src/ft_print_lowhex.c	\
				src/ft_print_ptr.c		\
				src/ft_print_str.c		\
				src/ft_print_uint.c		\
				src/ft_print_uphex.c	\
				src/ft_printf.c
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
INCLUDES 	= -I./includes
OBJS		= $(SRCS:%.c=%.o)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)

$(NAME) : $(OBJS)
		$(MAKE) libft.a -C ./libft
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)

bonus	:

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)

fclean:		clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean flcean re
