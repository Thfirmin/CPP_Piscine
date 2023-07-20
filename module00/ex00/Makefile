# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 14:32:54 by thfirmin          #+#    #+#              #
#    Updated: 2023/07/15 14:49:06 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	megaphone

CPP =	c++

CPPFLAGS =	-std=c++98 -g -Wall -Wextra -Werror

SRC =	megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all:		${NAME}

${NAME}:	$(OBJ)
	${CPP} ${CPPFLAGS} $(OBJ) -o ${NAME}

clean:
ifneq (,$(shell ls ${OBJ} 2> /dev/null))
	rm ${OBJ}
endif

fclean: clean
ifneq (,$(shell ls ${NAME} 2> /dev/null))
	rm ${NAME}
endif

re: fclean all

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

.PHONY: all clean fclean re
