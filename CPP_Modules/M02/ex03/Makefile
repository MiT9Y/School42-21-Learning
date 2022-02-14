NAME =		bsp

CPPFLAGS =	-Wall -Werror -Wextra -std=c++98

CPP =		c++

SRCS =		main.cpp Fixed.cpp Point.cpp bsp.cpp

HEA =		Fixed.hpp Point.hpp

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