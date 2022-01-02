# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/27 22:51:16 by jumaison          #+#    #+#              #
#    Updated: 2021/05/04 16:11:21 by jumaison         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \
			ft_printf_utils3.c \
			set_reset.c \
			apply_negative.c \
			apply_precision.c \
			left_justify.c \
			apply_spaces.c \
			reset_check_flags.c \
			check_spaces.c \
			print_c.c \
			print_s.c \
			print_p.c \
			print_di.c \
			print_u.c \
			print_x.c \
			print_arg.c 

OBJ = $(LIST:%.c=%.o)

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(LIST)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
