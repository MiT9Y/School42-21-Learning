/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 07:41:16 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 08:19:06 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_new_val(t_main_data *md, t_fpoint nn, t_sprite *el)
{
	float	a;

	el->size = md->scale / el->r;
	a = asinf(nn.y / el->r);
	if (nn.x < 0.0)
	{
		if (a < 0.0)
			a = (WIDTH / (FOV * PI / 180)) * (FOV * PI / 360 + (-PI - a));
		else
			a = (WIDTH / (FOV * PI / 180)) * (FOV * PI / 360 + (PI - a));
	}
	else
		a = (WIDTH / (FOV * PI / 180)) * (FOV * PI / 360 + a);
	el->xb = (int)(a - (0.5 * el->size));
	el->xe = (int)(a + (0.5 * el->size));
	el->r = fabsf(nn.x);
	el->size = md->scale / el->r;
}

void	init_sprites(t_main_data *md)
{
	int			i;
	t_fpoint	n;
	t_fpoint	nn;

	i = -1;
	while (md->sprs[++i])
	{
		n.x = md->sprs[i]->x - md->player.posx;
		n.y = md->sprs[i]->y - md->player.posy;
		md->sprs[i]->r = sqrtf((n.x * n.x) + (n.y * n.y));
		nn.x = n.x * cosf(md->player.posa) - n.y * sinf(md->player.posa);
		nn.y = n.x * sinf(md->player.posa) + n.y * cosf(md->player.posa);
		md->sprs[i]->xb = -1;
		md->sprs[i]->xe = -1;
		if (md->sprs[i]->r > WALL)
			set_new_val(md, nn, md->sprs[i]);
	}
}
