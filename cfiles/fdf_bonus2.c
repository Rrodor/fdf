/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:11:00 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/13 16:00:39 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_redirectsing(t_vars *vars)
{
	vars->grid = fdf_singularity(vars->grid, vars->sizex, vars->sizey);
	ft_mlxclearing(vars);
	ft_drawgrid(vars->grid, vars->sizex, vars->sizey, &(vars->img));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

t_point	**fdf_singularity(t_point **grid, int sizex, int sizey)
{
	int		i;
	int		j;
	t_point	z;
	t_point	**snglrt;

	i = -1;
	z.x = grid[0][0].x + (grid[sizey - 1][sizex - 1].x - grid[0][0].x) / 2;
	z.y = grid[0][0].y + (grid[sizey - 1][sizex - 1].y - grid[0][0].y) / 2;
	snglrt = (t_point **)malloc(sizeof(t_point *) * sizey);
	while (++i < sizey)
	{
		j = -1;
		snglrt[i] = (t_point *)malloc(sizeof(t_point) * (sizex));
		while (++j < sizex)
		{
			snglrt[i][j].x = (grid[i][j].x - z.x) * cos((M_PI / 144) *
				ft_norm(z, j, i)) - (grid[i][j].y - z.y) *sin(M_PI / 36 * ft_norm(z, j, i)) + z.x;
			snglrt[i][j].y = (grid[i][j].x - z.x) * sin((M_PI / 144) * ft_norm(z, j, i))
				+ (grid[i][j].y - z.y) * cos(M_PI / 36 * ft_norm(z, j, i)) + z.y;
			snglrt[i][j].z = grid[i][j].z;
			snglrt[i][j].c = grid[i][j].c;
		}
	}
	ft_free((void **)grid, sizey);
	return (snglrt);
}

int	ft_norm(t_point z, int x, int y)
{
	return (sqrt(pow(z.x - x, 2) + (pow(z.y - y, 2))));
}

t_point	**copygrid(t_point **grid, int sizex, int sizey)
{
	int		i;
	int		j;
	t_point	**copy;

	j = 0;
	copy = (t_point **) malloc (sizey * sizeof(t_point *));
	while (j < sizey)
	{
		i = 0;
		copy[j] = (t_point *) malloc (sizex * sizeof(t_point));
		while (i < sizex)
		{
			copy[j][i] = grid[j][i];
			i++;
		}
		j++;
	}
	return (copy);
}

void	ft_resetgrid(t_vars *vars)
{
	ft_free((void **)vars->grid, vars->sizey);
	vars->grid = copygrid(vars->refgrid, vars->sizex, vars->sizey);
	ft_mlxclearing(vars);
	ft_drawgrid(vars->grid, vars->sizex, vars->sizey, &(vars->img));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
