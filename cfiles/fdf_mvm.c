/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mvm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:15:25 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/11 18:52:01 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**fdf_rotatez(t_point **grid, int sizex, int sizey, float t)
{
	int		i;
	int		j;
	t_point	z;
	t_point	**rotated;

	i = -1;
	z.x = grid[0][0].x + (grid[sizey - 1][sizex - 1].x - grid[0][0].x) / 2;
	z.y = grid[0][0].y + (grid[sizey - 1][sizex - 1].y - grid[0][0].y) / 2;
	rotated = (t_point **)malloc(sizeof(t_point *) * sizey);
	while (++i < sizey)
	{
		j = -1;
		rotated[i] = (t_point *)malloc(sizeof(t_point) * (sizex));
		while (++j < sizex)
		{
			rotated[i][j].x = (grid[i][j].x - z.x) * cos(t)
				- (grid[i][j].y - z.y) * sin(t) + z.x;
			rotated[i][j].y = (grid[i][j].x - z.x) * sin(t)
				+ (grid[i][j].y - z.y) * cos(t) + z.y;
			rotated[i][j].z = grid[i][j].z;
			rotated[i][j].c = grid[i][j].c;
		}
	}
	ft_free((void **)grid, sizey);
	return (rotated);
}

t_point	**fdf_rotatex(t_point **grid, int sizex, int sizey, float t)
{
	int		i;
	int		j;
	t_point	z;
	t_point	**rotated;

	i = -1;
	z.x = grid[0][0].x + (grid[sizey - 1][sizex - 1].x - grid[0][0].x) / 2;
	z.y = 0;
	rotated = (t_point **)malloc(sizeof(t_point *) * sizey);
	while (++i < sizey)
	{
		j = -1;
		rotated[i] = (t_point *)malloc(sizeof(t_point) * (sizex));
		while (++j < sizex)
		{
			rotated[i][j].x = grid[i][j].x;
			rotated[i][j].y = (grid[i][j].y - z.x) * cos(t)
				- (grid[i][j].z - z.y) * sin(t) + z.x;
			rotated[i][j].z = (grid[i][j].y - z.x) * sin(t)
				+ (grid[i][j].z - z.y) * cos(t) + z.y;
			rotated[i][j].c = grid[i][j].c;
		}
	}
	ft_free((void **)grid, sizey);
	return (rotated);
}

t_point	**fdf_rotatey(t_point **grid, int sizex, int sizey, float t)
{
	int		i;
	int		j;
	t_point	z;
	t_point	**rotated;

	i = -1;
	z.x = 0;
	z.y = grid[0][0].y + (grid[sizey - 1][sizex - 1].y - grid[0][0].y) / 2;
	rotated = (t_point **)malloc(sizeof(t_point *) * sizey);
	while (++i < sizey)
	{
		j = -1;
		rotated[i] = (t_point *)malloc(sizeof(t_point) * (sizex));
		while (++j < sizex)
		{
			rotated[i][j].x = (grid[i][j].z - z.x) * sin(t)
				+ (grid[i][j].x - z.y) * cos(t) + z.y;
			rotated[i][j].y = grid[i][j].y;
			rotated[i][j].z = (grid[i][j].z - z.x) * cos(t)
				- (grid[i][j].x - z.y) * sin(t) + z.x;
			rotated[i][j].c = grid[i][j].c;
		}
	}
	ft_free((void **)grid, sizey);
	return (rotated);
}

t_point	**fdf_translate(t_point **grid, t_vars vars, int horit, int vertt)
{
	int		i;
	int		j;
	t_point	**translated;			

	i = 0;
	j = 0;
	translated = (t_point **)malloc(sizeof(t_point *) * vars.sizey);
	while (i < vars.sizey)
	{
		translated[i] = (t_point *)malloc(sizeof(t_point) * vars.sizex);
		while (j < vars.sizex)
		{
			translated[i][j].x = grid[i][j].x + horit;
			translated[i][j].y = grid[i][j].y + vertt;
			translated[i][j].z = grid[i][j].z;
			translated[i][j].c = grid[i][j].c;
			j++;
		}
		j = 0;
		i++;
	}
	ft_free((void **)grid, vars.sizey);
	return (translated);
}

t_point	**fdf_zoom(t_point **grid, int sizex, int sizey, float facteur)
{
	int		i;
	int		j;
	int		xo;
	int		yo;
	t_point	**zoom;

	j = 0;
	xo = grid[0][0].x + (grid[sizey - 1][sizex - 1].x - grid[0][0].x) / 2;
	yo = grid[0][0].y + (grid[sizey - 1][sizex - 1].y - grid[0][0].y) / 2;
	zoom = (t_point **) malloc((sizey) * sizeof(t_point *));
	while (j < sizey)
	{
		i = -1;
		zoom[j] = (t_point *) malloc((sizex) * sizeof(t_point));
		while (++i < sizex)
		{
			zoom[j][i].x = (grid[j][i].x - xo) * facteur + xo;
			zoom[j][i].y = (grid[j][i].y - yo) * facteur + yo;
			zoom[j][i].z = grid[j][i].z * facteur;
			zoom[j][i].c = grid[j][i].c;
		}
		j++;
	}
	ft_free((void **)grid, sizey);
	return (zoom);
}
