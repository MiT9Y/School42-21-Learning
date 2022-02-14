/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_mess.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 08:05:34 by msimon            #+#    #+#             */
/*   Updated: 2021/11/16 09:43:21 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MESS_H
# define ERR_MESS_H

# define ERR_USAGE			"Usage: ./so_long MAP_FILE\n"
# define ERR_OPEN_F			"No open file"
# define ERR_TYPE_F			"Incorrect type MAP_FILE\n"
# define ERR_READ_F			"No read file"
# define ERR_MEM			"Memory was allocated incorrectly\n"
# define ERR_MAP_SIZE		"Map parsing: not all lines are of the same length\n"
# define ERR_MAP_BORDER		"Map parsing: the border should consist of walls\n"
# define ERR_MAP_PLAYER		"Map parsing: there should be only \
one player position on the map\n"
# define ERR_MAP_EXIT		"Map parsing: there should be only \
one exit position on the map\n"
# define ERR_MAP_UNKNOWN	"Map parsing: unknown symbol found\n"
# define ERR_MAP_COUNT		"Map parsing: map must have at least \
one exit, one collectible, and one starting position\n"
# define ERR_INT_OVERFLOW	"Overflow for integer\n"
# define ERR_SPRITES_LOAD	"Sprite not found\n"

#endif