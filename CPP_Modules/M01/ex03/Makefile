NAME =		prog

CPPFLAGS =	-Wall -Werror -Wextra -std=c++98

CPP =		c++

SRCS =		main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

HEA =		Weapon.hpp HumanA.hpp HumanB.hpp

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