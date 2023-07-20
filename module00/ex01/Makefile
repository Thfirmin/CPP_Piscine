# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 20:52:50 by thfirmin          #+#    #+#              #
#    Updated: 2023/07/16 20:05:44 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

CPP = c++

CPPFLAGS =	-std=c++98 -g -Wall -Wextra -Werror

SRCS = main.cpp \
	   PhoneBook.cpp \
	   Contact.cpp

OBJS = $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm  -rf $(NAME)

re:			fclean all

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

.PHONY: all clean fclean re
