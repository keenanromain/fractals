/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/06/28 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			modify_environment(t_env *env)
{
	char y;
	char x;

	x = 1;
	y = 1;
	if (env->keys->right && !env->keys->left)
		env->mid_x += ((env->size * 4) / WS);
	else if (!env->keys->right && env->keys->left)
		env->mid_x -= ((env->size * 4) / WS);
	else
		x = 0;
	if (env->keys->up && !env->keys->down)
		env->mid_y += ((env->size * 4) / WS);
	else if (!env->keys->up && env->keys->down)
		env->mid_y -= ((env->size * 4) / WS);
	else
		y = 0;
	return (x || y ? 1 : 0);
}

void		modify_zoom(t_env *env, int x, int y, bool in)
{
	float	new;
	float	diff;
	float	off_y;
	float	off_x;

	new = ((in == true ? 1.1 : 0.9) * env->size);
	diff = new - env->size;
	off_y = (((float)((WS / 2) - y) / WS) * diff);
	env->mid_y = env->mid_y + off_y;
	off_x = (((float)((WS / 2) - x) / WS) * diff);
	env->mid_x = env->mid_x + off_x;
	env->size = new;
}
