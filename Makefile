#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/07/22 18:07:49 by ttshivhu          #+#    #+#             *#
#*   Updated: 2017/07/22 19:49:06 by ttshivhu         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CNAME	= checker
PNAME	= push_swap

CSRC		= cksrc/checker.c cksrc/helpers.c cksrc/operations.c cksrc/init.c \
			  cksrc/extra.c cksrc/operations2.c

PSRC		= pssrc/list.c pssrc/swap.c pssrc/utils.c pssrc/main.c

COBJ		= $(CSRC:.c=.o)

POBJ		= $(PSRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

all: $(CNAME) $(PNAME)

$(CNAME): $(COBJ)
	@make -C libft/ all
	@gcc $(CFLAGS) $(COBJ) -o $(CNAME) -L libft/ -lft

$(PNAME): $(POBJ)
	@gcc $(CFLAGS) $(POBJ) -o $(PNAME) -L libft/ -lft

clean:
	@make -C libft/ clean
	@rm -rf $(COBJ)
	@rm -rf $(POBJ)

fclean: clean
		@rm -rf $(CNAME) $(COBJ)
		@rm -rf $(PNAME) $(POBJ)
		@make -C libft/ fclean

re: fclean $(CNAME) $(PNAME)
