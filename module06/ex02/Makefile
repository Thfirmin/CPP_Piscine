NAME		= identifyRealType

CPP			= c++

CPPFLAGS	= -std=c++98 -g -Wall -Wextra -Werror

CLASS_SRC	= $(addprefix class/, \
			  	Base.cpp \
			  )

SRCS		= $(addprefix src/, \
			  	main.cpp \
			   )

SRCS		+= $(CLASS_SRC)

OBJS		= $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.cpp.o:
	$(CPP) $(CPPFLAGS) -I include/ -c $< -o $(<:.cpp=.o)

.PHONY:	all clean fclean re
