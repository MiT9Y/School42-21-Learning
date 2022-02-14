#Programm
NAME = 				philo

#Compiler 
CC = 				gcc

#Flags
CFLAGS = 			-Wall -Wextra -Werror

#Include
INC_PATH = 			inc
INC = 				-I${INC_PATH}

#Headers
HEA_NAME =			philo.h
HEA = 				${addprefix ${INC_PATH}/,${HEA_NAME}}

#Sources
SRC_PATH =			src

SRC_NAME =			main.c init_utils.c service.c run_philos.c life_cycle_philo.c life_cycle_philo_utils.c ft_atoi.c

#Objects
OBJ_PATH = 			obj
OBJ_NAME = 			${addprefix ${OBJ_PATH}/,${SRC_NAME:.c=.o}}

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c ${HEA}
					@mkdir -p $(dir $@)
					${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}:			${OBJ_NAME}
					${CC} ${CFLAGS} -o ${NAME} ${OBJ_NAME}

#Rules

all: 				${NAME}

clean:
					rm -rf ${OBJ_PATH}					

fclean: 			clean
					rm -rf ${NAME}

re: 				fclean all

norm:				fclean
					norminette ./src
					norminette ./inc

.PHONY: 			all clean fclean re norm