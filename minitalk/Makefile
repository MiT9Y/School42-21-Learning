#Programm
SNAME = 			server
CNAME = 			client

#Libft
LIBFT_PATH =		libft
LIBFT = 			ft

#Compiler 
CC = 				gcc

#Flags
CFLAGS = 			-Wall -Wextra -Werror

#Include
INC_PATH = 			inc
INC = 				-I${INC_PATH} -I${LIBFT_PATH}

#Headers
HEA_NAME =			minitalk.h minitalk_bonus.h minitalk_lib.h
HEA = 				${addprefix ${INC_PATH}/,${HEA_NAME}}

#Sources
SRC_PATH =			src

SRC_NAME = 			mess.c lst.c

SRC_BASE_SNAME = 	server.c
SRC_BASE_CNAME = 	client.c

SRC_BONUS_SNAME = 	server_bonus.c
SRC_BONUS_CNAME = 	client_bonus.c
					
#Objects
OBJ_PATH = 			obj
OBJ = 				${addprefix ${OBJ_PATH}/,${SRC_NAME:.c=.o}}
OBJ_SBASE = 		${addprefix ${OBJ_PATH}/,${SRC_BASE_SNAME:.c=.o}}
OBJ_CBASE = 		${addprefix ${OBJ_PATH}/,${SRC_BASE_CNAME:.c=.o}}
OBJ_SBONUS = 		${addprefix ${OBJ_PATH}/,${SRC_BONUS_SNAME:.c=.o}}
OBJ_CBONUS = 		${addprefix ${OBJ_PATH}/,${SRC_BONUS_CNAME:.c=.o}}

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c ${HEA} ${LIBFT_PATH}/*.c ${LIBFT_PATH}/*.h
					@mkdir -p $(dir $@)
					${CC} ${CFLAGS} -c $< -o $@ ${INC}

#Rules

all: 				${SNAME} ${CNAME}

bonus:				${OBJ} ${OBJ_SBONUS} ${OBJ_CBONUS}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					${CC} ${CFLAGS} -o ${SNAME} ${OBJ} ${OBJ_SBONUS} -L ${LIBFT_PATH} -l ${LIBFT}
					${CC} ${CFLAGS} -o ${CNAME} ${OBJ} ${OBJ_CBONUS} -L ${LIBFT_PATH} -l ${LIBFT}

${SNAME}:			${OBJ} ${OBJ_SBASE}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					${CC} ${CFLAGS} -o ${SNAME} ${OBJ} ${OBJ_SBASE} -L ${LIBFT_PATH} -l ${LIBFT}

${CNAME}:			${OBJ} ${OBJ_CBASE}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					${CC} ${CFLAGS} -o ${CNAME} ${OBJ} ${OBJ_CBASE} -L ${LIBFT_PATH} -l ${LIBFT}

clean:
					rm -rf ${OBJ_PATH}					
					@make clean -C ${LIBFT_PATH}

fclean: 			clean
					rm -rf ${SNAME}
					rm -rf ${CNAME}
					@make fclean -C ${LIBFT_PATH}

re: 				fclean all

.PHONY: 			all clean fclean re bonus