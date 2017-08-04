/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/06/28 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_color		*c5(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) { 0x009c247d, 0x00175ea5, \
		0x007155a6, 0x00d91f3f, 0x00168eab, 0x00d15280, \
		0x00791241, 0x004f5726, 0x001a8dab, 0x00ef6826, \
		0x003ab9c6, 0x00e6185f, 0x001e8bab, 0x00ed146d, \
		0x0098ceb6, 0x0031b24c, 0x00f26c53, 0x00e01d3f, \
		0x001460a5, 0x00771443, 0x001c1547, 0x00168ca7, \
		0x00f6a928, 0x008dc031};
	if (!(c[4].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c5");
	j = -1;
	while (++j <= 23)
		c[4].rgb[j] = palette[j];
	c[4].set = j;
	return (c);
}

t_color		*c6(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) {0x0055414a, 0x00241924, \
		0x00452345, 0x00552855, 0x00662d66, 0x00873787, \
		0x00981042, 0x00b63d60, 0x00a24657, 0x00af5a73, \
		0x00be8091, 0x00c6a8af, 0x00d4cdde, 0x00d4dee3, \
		0x00dde6ec, 0x00ecf6f8, 0x00f8eac9, 0x00f1d47c, \
		0x00e8bf65, 0x00dfa452, 0x00d1ab69, 0x00a86429, \
		0x006f2e1b, 0x00581a11};
	if (!(c[3].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c6");
	j = -1;
	while (++j <= 23)
		c[3].rgb[j] = palette[j];
	c[3].set = j;
	return (c);
}

t_color		*c7(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) {0x00eb6237, 0x00ec6d37, \
		0x00eb7d3e, 0x00ed8545, 0x00ee9446, 0x00f2a754, \
		0x00f4bd61, 0x00f5ce68, 0x00f7d376, 0x00f6d277, \
		0x00fadb7f, 0x00f4cb77, 0x00f5bc75, 0x00f0ab6d, \
		0x00f1af78, 0x00ee9166, 0x00ed8166, 0x00eb755c, \
		0x00e96754, 0x00de6756, 0x00eb6253, 0x00b85753, \
		0x00a25353, 0x007c3b42};
	if (!(c[2].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c7");
	j = -1;
	while (++j <= 23)
		c[2].rgb[j] = palette[j];
	c[2].set = j;
	return (c);
}

t_color		*c8(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) {0x00172849, 0x001a1e41, \
		0x00122852, 0x000e2e55, 0x00153c62, 0x001a4263, \
		0x000f446c, 0x00185c81, 0x001d77a1, 0x001f97bc, \
		0x00249db8, 0x003abbd8, 0x0023879e, 0x003d919d, \
		0x006299ac, 0x00a8c5b1, 0x00b8b181, 0x00d0b390, \
		0x00d7ae79, 0x00b28343, 0x00a7812f, 0x00e6c159, \
		0x00efd63e, 0x00f5e02f};
	if (!(c[1].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c8");
	j = -1;
	while (++j <= 23)
		c[1].rgb[j] = palette[j];
	c[1].set = j;
	return (c);
}

t_color		*c9(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) {0x0057934d, 0x0054a054, \
		0x005db556, 0x006eaf55, 0x007ec157, 0x00add165, \
		0x00d4e794, 0x00cde090, 0x00dfefcd, 0x006c425b, \
		0x004f376a, 0x0073206f, 0x00260338, 0x00464e61, \
		0x002e437a, 0x0019739e, 0x002d9594, 0x0070ae7d, \
		0x00afdb6b, 0x0055d9de, 0x00fcbfc2, 0x00c9757e, \
		0x00b5555a, 0x004c0319};
	if (!(c[0].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c9");
	j = -1;
	while (++j <= 23)
		c[0].rgb[j] = palette[j];
	c[0].set = j;
	return (c);
}
