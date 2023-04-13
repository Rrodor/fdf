/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:28:33 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/06 16:02:40 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	drawline(t_point p1, t_point p2, t_data *img)
{
	if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			drawlinelow(p2, p1, img);
		else
			drawlinelow(p1, p2, img);
	}
	else
	{
		if (p1.y > p2.y)
			drawlinehigh(p2, p1, img);
		else
			drawlinehigh(p1, p2, img);
	}
}

void	ft_drawgrid(t_point **grid, int sizex, int sizey, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < sizey)
	{
		while (i < sizex)
		{
			if (j + 1 < sizey)
				drawline(grid[j][i], grid[j + 1][i], img);
			if (i + 1 < sizex)
				drawline(grid[j][i], grid[j][i + 1], img);
			i++;
		}
		i = 0;
		j++;
	}
}
