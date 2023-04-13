/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:35:32 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/13 15:48:29 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_redirect(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	if (keycode < 65365 && keycode > 65360)
		ft_move(keycode, vars);
	if (keycode < 123 && keycode > 119)
		ft_rotateevent(keycode, vars);
	if (keycode == 45 || keycode == 61)
		ft_redirectzoom(keycode, vars);
	if (keycode == 115)
		ft_redirectsing(vars);
	if (keycode == 114)
		ft_resetgrid(vars);
	return (0);
}

int	ft_rotateevent(int keycode, t_vars *vars)
{
	if (keycode == 120)
		vars->grid = fdf_rotatex(vars->grid, vars->sizex,
				vars->sizey, M_PI / 72);
	if (keycode == 121)
		vars->grid = fdf_rotatey(vars->grid, vars->sizex,
				vars->sizey, M_PI / 72);
	if (keycode == 122)
		vars->grid = fdf_rotatez(vars->grid, vars->sizex,
				vars->sizey, M_PI / 72);
	ft_mlxclearing(vars);
	ft_drawgrid(vars->grid, vars->sizex, vars->sizey, &(vars->img));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	ft_move(int keycode, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (keycode == 65362)
		j = -10;
	if (keycode == 65361)
		i = -10;
	if (keycode == 65363)
		i = 10;
	if (keycode == 65364)
		j = 10;
	if (i != 0 || j != 0)
	{
		vars->grid = fdf_translate(vars->grid, *vars, i, j);
		ft_mlxclearing(vars);
		ft_drawgrid(vars->grid, vars->sizex, vars->sizey, &(vars->img));
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}

void	ft_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_free((void **)vars->grid, vars->sizey);
	ft_free((void **)vars->refgrid, vars->sizey);
	exit(0);
}

void	ft_free(void **grid, int sizey)
{
	int	i;

	i = 0;
	while (i < sizey)
	{
		free (grid[i]);
		i++;
	}
	free (grid);
}
