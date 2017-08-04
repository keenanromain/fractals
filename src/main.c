/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/06/27 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		show_fractals(void)
{
	ft_putendl("\033[01;39m\n		\
			________________________________________________\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8			\
			\u23B8\033[0m");
	ft_putendl("\033[01;39m					\u23B8\033[0m	   \033[01;36m\
	Available Fractol types:\033[0m	\033[0m\033[01;39m\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  ./fractol mandelbrot				\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  ./fractol julia				\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  ./fractol \"mandelbrot cube\"			\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  ./fractol \"julia cube\"			\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8						\u23B8\033[0m");
	ft_putendl("\033[01;39m					\u23B8\033[0m	   \033[01;36m\
	Controls for Fractol:	\033[0m	\033[0m\033[01;39m\u23B8\033[0m");
}

void		show_controls(void)
{
	show_fractals();
	ft_putendl("\033[01;39m		\
			\u23B8  Scroll to zoom in & zoom out			\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  Click to alter iterations			\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  W, A, S & D to move across environment	\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  Left Shitf to change colors			\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  Space to reset the environment		\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  C to freeze the screen for Julia types	\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8  ESC to quit Fractol				\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8						\u23B8\033[0m");
	ft_putendl("\033[01;39m					\u23B8\033[0m  \033[01;36m\
Enjoy!\033[0m					\033[0m\033[01;39m\u23B8\033[0m");
	ft_putendl("\033[01;39m		\
			\u23B8						\u23B8\033[0m");
	ft_putendl("\033[01;39m					\
\u23B8_______________________________________________\u23B8\033[0m");
	ft_putendl("\n");
}

void		show_error(int value, char *s)
{
	if (value == -1)
		ft_putstr_fd("\033[01;31mUsage Error\033[0m \033[01;39m \
~ ./fractol [mandelbrot | mcube | \
julia | jcube]\n\033[0m", 2);
	else if (value == -2)
		ft_putstr_fd("\033[01;31m\nUser Input Error\
\033[0m \033[01;39m ~ Available Fractals:\n - \
mandelbrot\n - mcube\n - \
julia\n - jcube\n\n\033[0m", 2);
	else if (value == -3)
	{
		ft_putstr_fd("Issue using Malloc in ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(". Terminating project.", 2);
	}
	exit(-1);
}

int			check_valid(char *s)
{
	if (ft_strcmp(s, "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(s, "mcube") == 0)
		return (2);
	if (ft_strcmp(s, "julia") == 0)
		return (3);
	if (ft_strcmp(s, "jcube") == 0)
		return (4);
	return (0);
}

int			main(int ac, char **av)
{
	int		type;
	pid_t	pd;
	int		i;

	i = 0;
	if (ac < 2)
		show_error(-1, NULL);
	while (++i < ac)
	{
		if (!(type = check_valid(ft_downcase(av[i]))))
			show_error(-2, NULL);
		if ((pd = fork()) == 0)
			create_project(type);
	}
	show_controls();
	return (0);
}
