/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/06/27 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_color		*handle_colors(void)
{
	t_color		*c;

	if (!(c = (t_color *)malloc(sizeof(t_color) * NB_C)))
		show_error(-3, "handle_colors");
	ft_memset(c, 0, sizeof(c));
	return (c0(c1(c2(c3(c4(c5(c6(c7(c8(c9(c)))))))))));
}

t_key		*handle_keys(void)
{
	t_key		*keys;

	if (!(keys = (t_key *)malloc(sizeof(t_key))))
		show_error(-3, "handle_keys");
	ft_memset(keys, 0, sizeof(keys));
	return (keys);
}

t_mouse		*handle_mouse(void)
{
	t_mouse		*mouse;

	if (!(mouse = (t_mouse *)malloc(sizeof(t_mouse))))
		show_error(-3, "handle_mouse");
	ft_memset(mouse, 0, sizeof(mouse));
	return (mouse);
}

pthread_t	handle_threads(t_env *env, int i)
{
	pthread_t	pthread;
	t_pthread	*t;
	void		*func;

	if (!(t = (t_pthread *)malloc(sizeof(t_pthread))))
		show_error(-3, "handle_threads");
	t->env = env;
	t->ti = i;
	func = (void *)run_thru_coordinates;
	pthread_create(&pthread, NULL, func, t);
	return (pthread);
}
