/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:28:36 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/05 23:37:48 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	ft_colorshift1(int p1, int p2, int percentage)
{
	t_point	c1;
	t_point	c2;
	int		c;

	if (p1 == p2 || percentage == 0)
		return (p1);
	c = p1;
	c1.x = p1 % 256;
	p1 /= 256;
	c1.y = p1 % 256;
	p1 /= 256;
	c1.z = p1 % 256;
	c2.x = p2 % 256;
	p2 /= 256;
	c2.y = p2 % 256;
	p2 /= 256;
	c2.z = p2 % 256;
	return (ft_colorshift2(c, c1, c2, percentage));
}

int	ft_colorshift2(int c, t_point c1, t_point c2, int percentage)
{
	int	t;

	if (c1.x > c2.x)
		c -= percentage * fabs(c2.x - c1.x) / 100;
	if (c1.x < c2.x)
		c += percentage * fabs(c2.x - c1.x) / 100;
	if (c1.y > c2.y)
		t = percentage * fabs(c2.y - c1.y) / 100;
	if (c1.y > c2.y)
		c -= 256 * t;
	if (c1.y < c2.y)
		t = percentage * fabs(c2.y - c1.y) / 100;
	if (c1.y < c2.y)
		c += 256 * t;
	if (c1.z > c2.z)
	{
		t = percentage * fabs(c2.z - c1.z) / 100;
		c -= 256 * 256 * t;
	}
	if (c1.z < c2.z)
	{
		t = percentage * fabs(c2.z - c1.z) / 100;
		c += 256 * 256 * t;
	}
	return (c);
}
