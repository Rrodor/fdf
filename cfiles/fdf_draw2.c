/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:55:29 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/06 16:03:13 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	drawlineinithigh(t_point p1, t_point p2, t_point *d, t_point *p)
{
	d->x = p2.x - p1.x;
	d->y = p2.y - p1.y;
	p->x = p1.x;
	p->y = p1.y;
	if (d->x < 0)
		return (-1);
	else
		return (1);
}

void	drawlinehigh(t_point p1, t_point p2, t_data *img)
{
	t_point		d;
	int			xi;
	t_point		p;
	int			perc;
	int			l;

	l = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	perc = 0;
	xi = drawlineinithigh(p1, p2, &d, &p);
	if (d.x < 0)
		d.x *= -1;
	d.z = (2 * d.x) - d.y;
	while (p.y < p2.y)
	{
		my_mlx_pixel_put(img, p.x, p.y, ft_colorshift1(p1.c, p2.c, perc));
		if (d.z > 0)
		{
			p.x += xi;
			d.z += (2 * (d.x - d.y));
		}
		else
			d.z += 2 * d.x;
		p.y++;
		perc = (sqrt(pow(p.x - p1.x, 2) + pow(p.y - p1.y, 2)) / l) * 100;
	}
}

int	drawlineinitlow(t_point p1, t_point p2, t_point *d, t_point *p)
{
	d->x = p2.x - p1.x;
	d->y = p2.y - p1.y;
	p->x = p1.x;
	p->y = p1.y;
	if (d->y < 0)
		return (-1);
	else
		return (1);
}

void	drawlinelow(t_point p1, t_point p2, t_data *img)
{
	t_point		d;
	int			yi;
	t_point		p;
	int			perc;
	int			l;

	l = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	perc = 0;
	yi = drawlineinitlow(p1, p2, &d, &p);
	if (d.y < 0)
		d.y *= -1;
	d.z = (2 * d.y) - d.x;
	while (p.x < p2.x)
	{
		my_mlx_pixel_put(img, p.x, p.y, ft_colorshift1(p1.c, p2.c, perc));
		if (d.z > 0)
		{
			p.y += yi;
			d.z += (2 * (d.y - d.x));
		}
		else
			d.z += 2 * d.y;
		p.x++;
		perc = (sqrt(pow(p.x - p1.x, 2) + pow(p.y - p1.y, 2)) / l) * 100;
	}
}
