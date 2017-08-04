/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/06/28 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void				calculate_coordinate(t_env *env, int x, int y, int i)
{
	unsigned char	j;
	unsigned int	color;
	int				num;

	j = (i + env->eo) % (env->colors[env->ei].set);
	color = env->colors[env->ei].rgb[j];
	num = (x + ((y * env->bnum) / 4));
	if (num >= 0 && num < (WS * WS))
		env->pix[num] = color;
}

void					run_thru_coordinates(void *thread)
{
	t_pthread	*t;
	t_env		*env;
	int			y;
	int			x;
	int			i;

	t = (t_pthread *)thread;
	env = t->env;
	y = ((WS / NB_T) * t->i) - 1;
	while (++y < (WS / NB_T) * (t->i + 1))
	{
		x = -1;
		while (++x < WS)
		{
			if (env->type < 3)
				i = (env->type == 1 ? mand(env, x, y) : mcub(env, x, y));
			else
				i = (env->type == 3 ? juli(env, x, y) : jcub(env, x, y));
			if (i < env->max_i)
				calculate_coordinate(env, x, y, i);
		}
	}
	free(t);
}
