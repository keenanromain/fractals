/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/06/27 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		motion_hook(int x, int y, t_env *env)
{
	if (!(env->keys->c))
	{
		env->mouse->vert = y;
		env->mouse->horz = x;
		env->status = true;
	}
	return (0);
}

int		mouse_release_hook(int button, int x, int y, t_env *env)
{
	(void)env;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_press_hook(int button, int x, int y, t_env *env)
{
	env->status = true;
	if (button == L_CLICK || button == R_CLICK)
		button == L_CLICK ? env->max_i++ : env->max_i--;
	else if (button == S_UP || button == S_DOWN)
		button == S_UP ? modify_zoom(env, x, y, true) \
				: modify_zoom(env, x, y, false);
	else
		env->status = false;
	return (0);
}

int		key_release_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_SHIFT_LEFT)
		;
	else if (keycode == KEY_W)
		env->keys->down = 0;
	else if (keycode == KEY_A)
		env->keys->left = 0;
	else if (keycode == KEY_S)
		env->keys->up = 0;
	else if (keycode == KEY_D)
		env->keys->right = 0;
	return (0);
}

int		key_press_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE)
		exit_hook(env);
	if (keycode == KEY_SPACEBAR)
	{
		reset_func(env);
		redraw_func(env);
	}
	else if (keycode == KEY_SHIFT_LEFT)
	{
		(env->ei == 0 ? (env->ei = NB_C - 1) : env->ei--);
		env->status = true;
	}
	else if (keycode == KEY_W)
		env->keys->down = 1;
	else if (keycode == KEY_A)
		env->keys->left = 1;
	else if (keycode == KEY_S)
		env->keys->up = 1;
	else if (keycode == KEY_D)
		env->keys->right = 1;
	else if (keycode == KEY_C)
		env->keys->c = !(env->keys->c);
	return (0);
}
