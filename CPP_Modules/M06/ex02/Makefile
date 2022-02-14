NAME =		 identify

CPPFLAGS =	-Wall -Werror -Wextra -std=c++98

CPP =		c++

SRCS =		main.cpp Base.cpp A.cpp B.cpp C.cpp

HEA =		Base.hpp A.hpp B.hpp C.hpp

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