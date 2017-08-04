/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:58:02 by kromain           #+#    #+#             */
/*   Updated: 2017/06/19 15:01:37 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WS 1024
# define NB_C 10
# define NB_T 20
# define L_CLICK 1
# define R_CLICK 2
# define S_UP 4
# define S_DOWN 5

# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_keys_macos.h"
# include "../libft/libft.h"
# include <pthread.h>

typedef struct		s_color
{
	unsigned char	set;
	unsigned int	*rgb;
}					t_color;

typedef struct		s_key
{
	char			up;
	char			left;
	char			down;
	char			right;
	char			shift;
	char			c;
	char			space;
}					t_key;

typedef struct		s_mouse
{
	char			left;
	char			right;
	char			up;
	char			down;
	int				horz;
	int				vert;
}					t_mouse;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*p;
	void			*ptr;
	unsigned int	*pix;
	int				bits;
	int				bnum;
	int				endian;
	float			size;
	float			mid_x;
	float			mid_y;
	int				max_i;
	unsigned char	ei;
	unsigned char	eo;
	t_color			*colors;
	t_key			*keys;
	t_mouse			*mouse;
	void			*reset_func;
	void			*redraw_func;
	int				type;
	bool			status:true;
}					t_env;

typedef struct		s_pthread
{
	t_env			*env;
	int				i;
}					t_pthread;

int					main(int ac, char **av);
void				show_fractals(void);
void				show_controls(void);
void				show_error(int value, char *s);
int					check_valid(char *s);
void				create_project(int type);
t_env				*init_env(int type);
void				init_hooks(t_env *env);
void				reset_func(t_env *env);
void				redraw_func(t_env *env);
pthread_t			handle_threads(t_env *env, int i);
t_mouse				*handle_mouse(void);
t_key				*handle_keys(void);
t_color				*handle_colors(void);
t_color				*c0(t_color *c);
t_color				*c1(t_color *c);
t_color				*c2(t_color *c);
t_color				*c3(t_color *c);
t_color				*c4(t_color *c);
t_color				*c5(t_color *c);
t_color				*c6(t_color *c);
t_color				*c7(t_color *c);
t_color				*c8(t_color *c);
t_color				*c9(t_color *c);
void				run_thru_coordinates(void *thread);
int					mand(t_env *env, double re, double im);
int					mcub(t_env *env, double re, double im);
int					juli(t_env *env, double x, double y);
int					jcub(t_env *env, double x, double y);
int					key_press_hook(int keycode, t_env *env);
int					key_release_hook(int keycode, t_env *env);
int					mouse_press_hook(int button, int x, int y, t_env *env);
int					mouse_release_hook(int button, int x, int y, t_env *env);
int					motion_hook(int x, int y, t_env *env);
int					loop_hook(t_env *env);
int					expose_hook(t_env *env);
int					exit_hook(t_env *env);
int					modify_environment(t_env *env);
void				modify_zoom(t_env *env, int x, int y, bool in);

#endif
