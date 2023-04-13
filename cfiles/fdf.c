/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:52:13 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/13 15:58:05 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > 2000 || y < 0 || y > 2000)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlxclearing(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < 2000)
	{
		i = 0;
		while (i < 2000)
		{
			my_mlx_pixel_put(&(vars->img), i, j, 0);
			i++;
		}
		j++;
	}
}

int	ft_close2(t_vars *vars)
{
	ft_close(vars);
	return (0);
}

int	ft_redirectzoom(int keycode, t_vars *vars)
{
	if (keycode == 61)
		vars->zoom = 1.1;
	if (keycode == 45)
		vars->zoom = 0.9;
	vars->grid = fdf_zoom(vars->grid, vars->sizex, vars->sizey, vars->zoom);
	ft_mlxclearing(vars);
	ft_drawgrid(vars->grid, vars->sizex, vars->sizey, &(vars->img));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;
	char	*path;

	if (argc != 2)
		return (0);
	path = ft_strjoin("maps/test_maps/", argv[1]);
	fd = open(path, O_RDONLY);
	free(path);
	vars.grid = ft_getgrid(fd, &(vars.sizex), &(vars.sizey));
	vars.grid = fdf_translate(vars.grid, vars,
			1000 - (vars.sizex / 2) * ZOOM, 1000 - (vars.sizey / 2) * ZOOM);
	vars.grid = fdf_rotatez(vars.grid, vars.sizex, vars.sizey, -M_PI / 4);
	vars.grid = fdf_rotatex(vars.grid, vars.sizex, vars.sizey, M_PI / 4);
	vars.refgrid = copygrid(vars.grid, vars.sizex, vars.sizey);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINX, WINY, "Macron demission");
	vars.img.img = mlx_new_image(vars.mlx, WINX, WINY);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &(vars.img).bits_per_pixel,
			&(vars.img).line_length, &(vars.img).endian);
	ft_drawgrid(vars.grid, vars.sizex, vars.sizey, &(vars.img));
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, fdf_redirect, &vars);
	mlx_hook(vars.win, 17, 0L, ft_close2, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
