# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfilipch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 09:34:02 by mfilipch          #+#    #+#              #
#    Updated: 2016/10/09 23:56:07 by mfilipch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

FUNCS		+=	ft_printf.c\
				ft_putulnbr.c\
				ft_putlldbl.c\
				ft_numlen.c\
				ft_ultoa_base.c\
				ft_wcharstr.c\
				ft_prtf_str.c\
				ft_prtf_xop.c\
				ft_prtf_uid.c\
				ft_putstr.c\
				ft_strlen.c\
				ft_putchar.c\
				ft_atoi.c\
				ft_strncmp.c\
				ft_isdigit.c

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(addprefix $(OBJS_DIR), $(FUNCS:.c=.o))

INC_DIR		=	./includes/
OBJS_DIR	=	./build/

.PHONY: all clean fclean re

all: $(NAME)

build:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# $(OBJS_DIR)%.o: %.c | build
# 	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): build $(OBJS)
	@ar rcs $@ $(OBJS)

clean:
	@/bin/rm -rf $(OBJS_DIR)
	@/bin/rm -f *.out
	@/bin/rm -f *.o
	@/bin/rm -f ._*
	@/bin/rm -f .DS*

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
