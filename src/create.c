/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/06/27 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		init_hooks(t_env *env)
{
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_hook(env->p, 2, 0, key_press_hook, env);
	mlx_hook(env->p, 3, 0, key_release_hook, env);
	mlx_hook(env->p, 4, 0, mouse_press_hook, env);
	mlx_hook(env->p, 5, 0, mouse_release_hook, env);
	if (env->type > 2)
		mlx_hook(env->p, 6, 0, motion_hook, env);
	mlx_hook(env->p, 12, 0, expose_hook, env);
	mlx_hook(env->p, 17, 0, exit_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
}

void		redraw_func(t_env *env)
{
	int			i;
	pthread_t	x[NB_T];

	i = -1;
	while (++i < NB_T)
		x[i] = handle_threads(env, i);
	i = -1;
	while (++i < NB_T)
		pthread_join(x[i], NULL);
	mlx_put_image_to_window(env->mlx, env->p, env->ptr, 0, 0);
	mlx_destroy_image(env->mlx, env->ptr);
	env->ptr = mlx_new_image(env->mlx, WS, WS);
	env->pix = (unsigned int *)mlx_get_data_addr(env->ptr, \
			&(env->bits), &(env->bnum), &(env->endian));
}

void		reset_func(t_env *env)
{
	env->max_i = (env->type < 3 ? 24 : 32);
	env->size = (env->type < 3 ? 2.8 : 3.0);
	env->mid_y = 0.0;
	env->mid_x = (env->type < 3 ? -0.0 : 0.0);
	if (env->type == 1)
		env->mid_x -= 0.65;
	env->ei = (env->type > 2 ? 0 : 9);
	if (env->type == 1)
		env->ei -= 5;
	env->eo = (env->type % 2 ? 0 : 9);
	if (env->type == 4)
		env->eo -= 1;
}

t_env		*init_env(int type)
{
	t_env		*env;
	char		**s;
	char const	*str;

	str = "Mandelbrot,Mandelbrot Cube,Julia,Julia Cube";
	s = ft_strsplit(str, ',');
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		show_error(-3, "init_env");
	ft_memset(env, 0, sizeof(env));
	env->mlx = mlx_init();
	env->p = mlx_new_window(env->mlx, WS, WS - 4, s[type - 1]);
	env->type = type;
	reset_func(env);
	env->colors = handle_colors();
	env->keys = handle_keys();
	env->mouse = handle_mouse();
	env->ptr = mlx_new_image(env->mlx, WS, WS);
	env->pix = (unsigned int *)mlx_get_data_addr(env->ptr, \
			&(env->bits), &(env->bnum), &(env->endian));
	env->status = true;
	return (env);
}

void		create_project(int type)
{
	t_env *env;

	env = init_env(type);
	env->reset_func = reset_func;
	env->redraw_func = redraw_func;
	init_hooks(env);
	mlx_loop(env->mlx);
}
