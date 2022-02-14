#Programm
NAME = 				cub3D
NAME_BONUS = 		cub3D_bonus

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
HEA_NAME =			cub3D.h
HEA = 				${addprefix ${INC_PATH}/,${HEA_NAME}}

#Sources
SRC_PATH =			src

SRC_NAME_MAIN = 	main.c init_utils.c messages.c event_utils.c close_app.c render.c ray_render.c arr_utils.c\
					parser_map.c check_map.c string_utils.c parser_cmd.c parser_texs.c set_map.c set_unmapped_el.c\
					mechanics.c horizontal_point.c vertical_point.c player_move.c check_door_opening.c mechanics_utils.c\
					check_map_utils.c other_move.c graph_utils.c draw_mini_map.c graph_utils2.c render_init_sprites.c\
					set_el_map.c

SRC_NAME_BONUS =	main.c init_utils.c messages.c event_utils.c close_app.c render.c ray_render.c arr_utils.c\
					parser_map_bonus.c check_map.c string_utils.c parser_cmd.c parser_texs.c set_map.c set_unmapped_el.c\
					mechanics.c horizontal_point.c vertical_point.c player_move.c check_door_opening.c mechanics_utils.c\
					check_map_utils.c other_move.c graph_utils.c draw_mini_map.c graph_utils2.c render_init_sprites.c\
					set_el_map.c

#Objects
OBJ_PATH = 			obj
OBJ_MAIN = 			${addprefix ${OBJ_PATH}/,${SRC_NAME_MAIN:.c=.o}}
OBJ_BONUS = 		${addprefix ${OBJ_PATH}/,${SRC_NAME_BONUS:.c=.o}}

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c ${HEA} ${LIBFT_PATH}/*.c ${LIBFT_PATH}/*.h ${LIBFT_PATH}/Makefile ${MLIBX_PATH}/*.c ${MLIBX_PATH}/*.h ${MLIBX_PATH}/Makefile Makefile
					@mkdir -p $(dir $@)
					${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}:			${OBJ_MAIN}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					@$(MAKE) -C ${MLIBX_PATH}
					${CC} ${CFLAGS} -o ${NAME} ${OBJ_MAIN} -L ${LIBFT_PATH} -l ${LIBFT} -L ${MLIBX_PATH} -l ${MLIBX} -framework OpenGL -framework AppKit

${NAME_BONUS}:		${OBJ_BONUS}
					@$(MAKE) bonus -C ${LIBFT_PATH}
					@$(MAKE) -C ${MLIBX_PATH}
					${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJ_BONUS} -L ${LIBFT_PATH} -l ${LIBFT} -L ${MLIBX_PATH} -l ${MLIBX} -framework OpenGL -framework AppKit

#Rules

all: 				${NAME}

bonus:				${NAME_BONUS}

clean:
					rm -rf ${OBJ_PATH}					
					@make clean -C ${LIBFT_PATH}
					@make clean -C ${MLIBX_PATH}

fclean: 			clean
					rm -rf ${NAME} ${NAME_BONUS}
					@make fclean -C ${LIBFT_PATH}

re: 				fclean all

norm:				fclean
					norminette ./src
					norminette ./inc
					norminette ./libft

.PHONY: 			all clean fclean re bonus norm