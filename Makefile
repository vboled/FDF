# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 16:11:47 by bdong             #+#    #+#              #
#    Updated: 2019/11/19 20:30:55 by bdong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = includes
all: $(NAME)
$(NAME): $(OBJ) $(INC)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): %.o : src/%.c
	gcc -Wall -Werror -Wextra -I $(INC) -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
