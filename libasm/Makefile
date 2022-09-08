# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:15:54 by msimon            #+#    #+#              #
#    Updated: 2022/09/06 17:31:45 by msimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Library
NAME = 				libasm.a

#Compiler 
CC = 				gcc
ASS =				/opt/local/bin/nasm

#Flags
CFLAGS = 			-Wall -Wextra -Werror
SFLAGS = 			-f macho64

#Headers
HEA_PATH = 			.
HEA_NAME = 			libasm.h
HEA =				${addprefix ${HEA_PATH}/,${HEA_NAME}}

#Sources
SRC_NAME = 			ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

#Bonus
BONUS_NAME = 		ft_atoi_base_bonus.s ft_list_push_front_bonus.s ft_list_size_bonus.s\
					ft_list_sort_bonus.s ft_list_remove_if_bonus.s

#Objects
OBJ_PATH = 			.
OBJ_NAME = 			${SRC_NAME:.s=.o}
OBJ_BONUS_NAME =	${BONUS_NAME:.s=.o}
OBJ = 				${addprefix ${OBJ_PATH}/,${OBJ_NAME}}
OBJ_BONUS =			${addprefix ${OBJ_PATH}/,${OBJ_BONUS_NAME}}

%.o: 				%.s
					${ASS} ${SFLAGS} $<
					
${NAME}: 			${OBJ} Makefile
					@rm -rf libasm.a
					ar rc ${NAME} ${OBJ}

all: 				${NAME}

bonus:				${OBJ} ${OBJ_BONUS}
					@rm -rf libasm.a
					ar rc ${NAME} ${OBJ} ${OBJ_BONUS}

clean:
					@rm -rf ${OBJ} ${OBJ_BONUS}

fclean: 			clean
					@rm -rf ${NAME} 

re: 				fclean all

.PHONY: 			all clean fclean re bonus