NAME =		megaphone

CPPFLAGS =	-Wall -Werror -Wextra -std=c++98

CPP =		c++

SRCS =		megaphone.cpp

OBJS =		$(SRCS:%.cpp=%.o)

%.o:		%.cpp Makefile
			${CPP} ${CPPFLAGS} -c $< -o $@

$(NAME):	$(OBJS)
			$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re