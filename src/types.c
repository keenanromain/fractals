/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/07/28 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			mcub(t_env *env, double re, double im)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	i = -1;
	x = 0.0;
	y = 0.0;
	re = ((re / WS) * env->size) + env->mid_x - (env->size * 0.5);
	im = ((im / WS) * env->size) + env->mid_y - (env->size * 0.5);
	while ((++i < env->max_i) && ((x * x) + (y * y) < 4))
	{
		tmp = (x * x * x) - (y * x * y) - (2 * x * y * y) + re;
		y = (3 * x * x * y) - (y * y * y) + im;
		x = tmp;
	}
	return (i);
}

int			jcub(t_env *env, double x, double y)
{
	int		i;
	double	tmp;
	double	re;
	double	im;

	i = -1;
	x = ((x / WS) * env->size) + env->mid_x - (env->size * 0.5);
	y = ((y / WS) * env->size) + env->mid_y - (env->size * 0.5);
	re = (((double)env->mouse->horz - (double)(WS / 2)) / (double)WS);
	im = (((double)env->mouse->vert - (double)(WS / 2)) / (double)WS);
	while ((++i < env->max_i) && ((x * x) + (y * y) < 4))
	{
		tmp = (x * x * x) - (y * y * x) - (2 * x * y * y) + re;
		y = (3 * x * x * y) - (y * y * y) + im;
		x = tmp;
	}
	return (i);
}

int			mand(t_env *env, double re, double im)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	i = -1;
	x = 0.0;
	y = 0.0;
	re = ((re / WS) * env->size) + env->mid_x - (env->size * 0.5);
	im = ((im / WS) * env->size) + env->mid_y - (env->size * 0.5);
	while ((++i < env->max_i) && ((x * x) + (y * y) < 4))
	{
		tmp = (x * x) - (y * y) + re;
		y = (2 * x * y) + im;
		x = tmp;
	}
	return (i);
}

int			juli(t_env *env, double x, double y)
{
	int		i;
	double	tmp;
	double	re;
	double	im;

	i = -1;
	x = ((x / WS) * env->size) + env->mid_x - (env->size * 0.5);
	y = ((y / WS) * env->size) + env->mid_y - (env->size * 0.5);
	re = (((double)env->mouse->horz - (double)(WS / 2)) / (double)WS);
	im = (((double)env->mouse->vert - (double)(WS / 2)) / (double)WS);
	while ((++i < env->max_i) && ((x * x) + (y * y) < 4))
	{
		tmp = (x * x) - (y * y) + re;
		y = (2 * x * y) + im;
		x = tmp;
	}
	return (i);
}
