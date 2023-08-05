NAME =	aaaaandOpen

CPP =	c++

CPPFLAGS =	-std=c++98 -g -Wall -Wextra -Werror

SRCS = main.cpp \
	   ClapTrap.cpp

OBJS =	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.cc.o:
	$(CPP) $(CPPFLAGS) -c $< -o $(<.cpp=.o)

.PHONY:	all clean fclean re
