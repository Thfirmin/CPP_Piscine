
# Compiler
CC := c++
# Compiler flags
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g
# Source files
SRCS := main.cpp Date.cpp
# Object files
OBJS := $(SRCS:.cpp=.o)
# Executable name
NAME := myprogram

# Default target
all: $(NAME)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean object files and executable
clean:
	rm -f $(OBJS)

# Clean object files, executable, and dependencies
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re
