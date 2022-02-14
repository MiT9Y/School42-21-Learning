NAME =		abstract

CPPFLAGS =	-Wall -Werror -Wextra -std=c++98

CPP =		c++

SRCS =		main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

HEA =		Animal.hpp Cat.hpp Dog.hpp Brain.hpp

OBJS =		$(SRCS:%.cpp=%.o)

%.o:		%.cpp $(HEA) Makefile
			$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re