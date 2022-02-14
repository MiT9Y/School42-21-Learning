#Programm
PWNAME = 			push_swap
CHNAME = 			checker

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
HEA_NAME =			push_swap.h checker.h base.h
HEA = 				${addprefix ${INC_PATH}/,${HEA_NAME}}

#Sources
SRC_PATH =			src

SRC_NAME = 			b_init_arr.c b_lst.c b_mess.c b_operations.c b_str.c b_execute.c
SRC_BASE_PSNAME = 	push_swap.c ps_operations.c	ps_fast_sort.c ps_bf_sort.c ps_compress_str.c ps_copy_restore.c ps_fs_lib.c
SRC_BASE_CHNAME = 	checker.c ch_get_next_line.c

#Objects
OBJ_PATH = 			obj
OBJ = 				${addprefix ${OBJ_PATH}/,${SRC_NAME:.c=.o}}
OBJ_PSNAME = 		${addprefix ${OBJ_PATH}/,${SRC_BASE_PSNAME:.c=.o}}
OBJ_CHNAME = 		${addprefix ${OBJ_PATH}/,${SRC_BASE_CHNAME:.c=.o}}

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c ${HEA} ${LIBFT_PATH}/*.c ${LIBFT_PATH}/*.h
					@mkdir -p $(dir $@)
					${CC} ${CFLAGS} -c $< -o $@ ${INC}

#Rules

all: 				${PWNAME} ${CHNAME}

${PWNAME}:			${OBJ} ${OBJ_PSNAME}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					${CC} ${CFLAGS} -o ${PWNAME} ${OBJ} ${OBJ_PSNAME} -L ${LIBFT_PATH} -l ${LIBFT}

${CHNAME}:			${OBJ} ${OBJ_CHNAME}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					${CC} ${CFLAGS} -o ${CHNAME} ${OBJ} ${OBJ_CHNAME} -L ${LIBFT_PATH} -l ${LIBFT}

clean:
					rm -rf ${OBJ_PATH}					
					@make clean -C ${LIBFT_PATH}

fclean: 			clean
					rm -rf ${PWNAME}
					rm -rf ${CHNAME}
					@make fclean -C ${LIBFT_PATH}

re: 				fclean all

norm:				fclean
					norminette ./src
					norminette ./inc
					norminette ./libft

.PHONY: 			all clean fclean re norm