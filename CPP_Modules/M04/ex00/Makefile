NAME =		polymorphism

CPPFLAGS =	-Wall -Werror -Wextra -std=c++98

CPP =		c++

SRCS =		main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

HEA =		Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

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