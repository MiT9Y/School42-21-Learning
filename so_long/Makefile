#Programm
NAME = 				so_long

#Libft
LIBFT_PATH =		libft
LIBFT = 			ft

#MinilibX
MLIBX_PATH =		minilibx
MLIBX = 			mlx

#Compiler 
CC = 				gcc

#Flags
CFLAGS = 			-Wall -Wextra -Werror

#Include
INC_PATH = 			inc
INC = 				-I${INC_PATH} -I${LIBFT_PATH} -I${MLIBX_PATH}

#Headers
HEA_NAME =			so_long_base.h so_long_main.h so_long_bonus.h err_mess.h screen_setings.h
HEA = 				${addprefix ${INC_PATH}/,${HEA_NAME}}

#Sources
SRC_PATH =			src

SRC_NAME_BASE = 	b_mess.c b_utils_scr.c b_utils_map.c b_utils_info.c b_utils_sp_wall.c b_utils_player.c b_utils_player_move.c b_utils_coll_exit.c b_utils_player_render.c
SRC_NAME_MAIN =		main.c utils_map.c service.c
SRC_NAME_BONUS =	main_bonus.c utils_map_bonus.c service_bonus.c utils_enemy_bonus.c utils_enemy_render_bonus.c

#Objects
OBJ_PATH = 			obj
OBJ_BASE = 			${addprefix ${OBJ_PATH}/,${SRC_NAME_BASE:.c=.o}}
OBJ_MAIN = 			${addprefix ${OBJ_PATH}/,${SRC_NAME_MAIN:.c=.o}}
OBJ_BONUS = 		${addprefix ${OBJ_PATH}/,${SRC_NAME_BONUS:.c=.o}}

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c ${HEA} ${LIBFT_PATH}/*.c ${LIBFT_PATH}/*.h
					@mkdir -p $(dir $@)
					${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}:			${OBJ_BASE} ${OBJ_MAIN}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					@$(MAKE) -C ${MLIBX_PATH}
					${CC} ${CFLAGS} -o ${NAME} ${OBJ_BASE} ${OBJ_MAIN} -L ${LIBFT_PATH} -l ${LIBFT} -L ${MLIBX_PATH} -l ${MLIBX} -framework OpenGL -framework AppKit

#Rules

all: 				${NAME}

bonus:				${OBJ_BASE} ${OBJ_BONUS}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					@$(MAKE) -C ${MLIBX_PATH}
					${CC} ${CFLAGS} -o ${NAME} ${OBJ_BASE} ${OBJ_BONUS} -L ${LIBFT_PATH} -l ${LIBFT} -L ${MLIBX_PATH} -l ${MLIBX} -framework OpenGL -framework AppKit

clean:
					rm -rf ${OBJ_PATH}					
					@make clean -C ${LIBFT_PATH}
					@make clean -C ${MLIBX_PATH}

fclean: 			clean
					rm -rf ${NAME}
					@make fclean -C ${LIBFT_PATH}

re: 				fclean all

norm:				fclean
					norminette ./src
					norminette ./inc
					norminette ./libft

.PHONY: 			all clean fclean re bonus norm