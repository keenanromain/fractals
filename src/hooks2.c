/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/06/27 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			loop_hook(t_env *env)
{
	if (env->keys->shift)
	{
		env->eo == 0 ? (env->eo = env->colors[env->ei].set - 1) : env->eo--;
		env->status = true;
	}
	if (modify_environment(env))
		env->status = true;
	if (env->status)
		redraw_func(env);
	return (0);
}

int			expose_hook(t_env *env)
{
	if (env->status)
		redraw_func(env);
	return (0);
}

void		delete_color(t_color *colors)
{
	int i;

	i = -1;
	while (++i < NB_C)
		if (colors[i].rgb)
			free(colors[i].rgb);
}

int			exit_hook(t_env *env)
{
	if (env)
	{
		if (env->mlx && env->p)
			mlx_destroy_window(env->mlx, env->p);
		if (env->colors)
			delete_color(env->colors);
		if (env->mouse)
			free(env->mouse);
		if (env->keys)
			free(env->keys);
		ft_memset(env, 0, sizeof(env));
		mlx_destroy_image(env->mlx, env->ptr);
		free(env);
		env = NULL;
	}
	exit(0);
}
