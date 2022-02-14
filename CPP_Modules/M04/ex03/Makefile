NAME =		interface_test

CPPFLAGS =	-Wall -Werror -Wextra -std=c++98

CPP =		c++

SRCS =		main.cpp AMateria.cpp Ice.cpp Cure.cpp MateriaSource.cpp Character.cpp

HEA =		AMateria.hpp ICharacter.hpp Ice.hpp IMateriaSource.hpp Cure.hpp MateriaSource.hpp Character.hpp

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