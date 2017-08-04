/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/06/28 09:36:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_color		*c0(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) {0x0000ffc6, 0x000c7d85, \
		0x001a4263, 0x00232a52, 0x003a0a37, 0x0058002a, \
		0x00800620, 0x00cb3213, 0x00ff6c10, 0x00ff6c0a, \
		0x00d2fdfc, 0x009bf3f2, 0x00162441, 0x0047254e, \
		0x00602244, 0x00792e31, 0x002c5276, 0x001f3942, \
		0x003da3a2, 0x00a92c35, 0x00922b67, 0x00033668, \
		0x00598e71, 0x0067f0ed};
	if (!(c[9].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c0");
	j = -1;
	while (++j <= 23)
		c[9].rgb[j] = palette[j];
	c[9].set = j;
	return (c);
}

t_color		*c1(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) {0x00f2f2f2, 0x00f6f6f6, \
		0x00eaeaec, 0x00e4ccdd, 0x00e7c4d7, 0x00f3c8d6, \
		0x00e1b4c6, 0x00cf92ae, 0x00cb89a9, 0x00d07da5, \
		0x00fad6b1, 0x00efe8d3, 0x00f6eabf, 0x00f3e4ae, \
		0x00e6e388, 0x00cee6d1, 0x00c3dfd0, 0x00afcfed, \
		0x00accded, 0x0088bbe8, 0x005994e1, 0x004283de, \
		0x003d89ec, 0x003473e9};
	if (!(c[8].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c1");
	j = -1;
	while (++j <= 23)
		c[8].rgb[j] = palette[j];
	c[8].set = j;
	return (c);
}

t_color		*c2(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) {0x00822790, 0x00e91c25, \
		0x00fdfa05, 0x00ee6cac, 0x00dd741b, 0x00003181, \
		0x00a21f8b, 0x00f5f9bb, 0x00088ec9, 0x00800301, \
		0x00157906, 0x00caa601, 0x00013893, 0x00141343, \
		0x00d36a02, 0x000067ae, 0x00bd3f52, 0x00da775b, \
		0x00afc5ee, 0x006f1984, 0x008bba80, 0x0074d920, \
		0x006a89be, 0x0086010d};
	if (!(c[7].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c2");
	j = -1;
	while (++j <= 23)
		c[7].rgb[j] = palette[j];
	c[7].set = j;
	return (c);
}

t_color		*c3(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) {0x00efeaeb, 0x00ebf0f7, \
		0x00e7f3f4, 0x00cae1e9, 0x00c6d8de, 0x00d4eaeb, \
		0x00bbdce1, 0x00adc6d7, 0x0093b8c1, 0x0083acbe, \
		0x007fbacf, 0x0063b6c9, 0x006abdd0, 0x0054bbd7, \
		0x0048c1cf, 0x00098eb1, 0x000879a3, 0x00076591, \
		0x00548295, 0x000c4361, 0x00032352, 0x00061047, \
		0x00043f78, 0x00011945};
	if (!(c[6].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c3");
	j = -1;
	while (++j <= 23)
		c[6].rgb[j] = palette[j];
	c[6].set = j;
	return (c);
}

t_color		*c4(t_color *c)
{
	int				j;
	unsigned int	*palette;

	palette = (unsigned int[24]) {0x005a0f08, 0x00480d05, \
		0x00661109, 0x0078160f, 0x008d1c13, 0x008c1a10, \
		0x00ab2217, 0x00bb271a, 0x00da3122, 0x00de3727, \
		0x00e84027, 0x00eb522f, 0x00ea7530, 0x00ee9b3c, \
		0x00f09a53, 0x00e3b298, 0x00f6cad2, 0x00f2cec9, \
		0x00f3effc, 0x00d6ebee, 0x00bfdaf1, 0x0084dfe4, \
		0x0028c2d1, 0x0018bacb};
	if (!(c[5].rgb = malloc(sizeof(unsigned int) * 24)))
		show_error(-3, "c4");
	j = -1;
	while (++j <= 23)
		c[5].rgb[j] = palette[j];
	c[5].set = j;
	return (c);
}
