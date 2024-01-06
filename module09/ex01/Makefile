NAME	= RPN

CPP		= c++

CPPFLAGS	= -std=c++98 -g -Wall -Wextra -Werror

SRCS		= \
			  main.cpp \
			  Rpn.cpp

OBJS		= $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
