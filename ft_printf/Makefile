#Library
NAME = 				libftprintf.a

#Libft
LIBFT_PATH =		libft
LIBFT = 			libft/libft.a

#Compiler 
CC = 				gcc

#Flags
CFLAGS = 			-Wall -Wextra -Werror

#Include
INC_PATH = 			inc
INC = 				-I${INC_PATH} -I${LIBFT_PATH}

#Headers
HEA_NAME =			ft_printf.h ft_print_fr_str.h ft_print_fr_str_bonus.h
HEA = 				${addprefix ${INC_PATH}/,${HEA_NAME}}

#Sources
SRC_PATH =			src

SRC_NAME = 			ft_get_nmb.c ft_printf.c ft_hex_str.c \
					ft_set_flag.c ft_init_flag.c ft_nmb_str.c

SRC_BASE_NAME = 	ft_print_fr_str.c ft_print_pnt.c ft_init_var.c \
					ft_print_chr.c ft_print_nmb.c ft_print_hex.c \
					ft_print_str.c

SRC_BONUS_NAME = 	ft_print_fr_str_bonus.c ft_print_pnt_bonus.c ft_init_var_bonus.c \
					ft_print_chr_bonus.c ft_print_nmb_bonus.c ft_print_hex_bonus.c \
					ft_print_str_bonus.c
					
#Objects
OBJ_PATH = 			obj
OBJ = 				${addprefix ${OBJ_PATH}/,${SRC_NAME:.c=.o}}
OBJ_BASE = 			${addprefix ${OBJ_PATH}/,${SRC_BASE_NAME:.c=.o}}
OBJ_BONUS = 		${addprefix ${OBJ_PATH}/,${SRC_BONUS_NAME:.c=.o}}

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c ${HEA} ${LIBFT_PATH}/*.c ${LIBFT_PATH}/*.h
					@mkdir -p $(dir $@)
					${CC} ${CFLAGS} -c $< -o $@ ${INC} ${INC_LIBFT}

#Rules
${NAME}: 			${OBJ} ${OBJ_BASE}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					@cp ${LIBFT} ${NAME}
					@ar rc ${NAME} ${OBJ} ${OBJ_BASE}

bonus:				${OBJ} ${OBJ_BONUS}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					@cp ${LIBFT} ${NAME}
					@ar rc ${NAME} ${OBJ} ${OBJ_BONUS}

all: 				${NAME}

clean:
					rm -rf ${OBJ_PATH}					
					@make clean -C ${LIBFT_PATH}

fclean: 			clean
					rm -rf ${NAME}
					@make fclean -C ${LIBFT_PATH}

re: 				fclean all

norm:				fclean
					norminette ./inc/*.*
					norminette ./src/*.*
					norminette ./libft/*.*

.PHONY: 			all clean fclean re bonus