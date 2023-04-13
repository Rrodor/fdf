/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:42:47 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/13 14:36:11 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define ZOOM 30
# define WINX 2000
# define WINY 2000

typedef struct s_pars
{
	int x;
	int	y;
}				t_pars;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		c;
}				t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_point		**grid;
	t_point		**refgrid;
	int			sizex;
	int			sizey;
	t_data		img;
	float		zoom;
}				t_vars;

int		main(int argc, char **argv);
void	ft_close(t_vars *vars);
int		ft_close2(t_vars *vars);
int		ft_splitlen(char **split);
t_point	**ft_getgrid(int fd, int *sizex, int *sizey);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_drawline(t_point p1, t_point p2, t_data *data);
void	ft_drawgrid(t_point **grid, int sizex, int sizey, t_data *data);
t_point	**fdf_rotatex(t_point **grid, int sizex, int sizey, float teta);
t_point	**fdf_rotatey(t_point **grid, int sizex, int sizey, float teta);
t_point	**fdf_rotatez(t_point **grid, int sizex, int sizey, float teta);
t_point	**fdf_translate(t_point **grid, t_vars vars, int horit, int vertt);
void	drawline(t_point p1, t_point p2, t_data *img);
void	drawlinelow(t_point p1, t_point p2, t_data *img);
void	drawlinehigh(t_point p1, t_point p2, t_data *img);
int		drawlineinithigh(t_point p1, t_point p2, t_point *d, t_point *p);
int		drawlineinitlow(t_point p1, t_point p2, t_point *d, t_point *p);
int		ft_getcolors(char *str);
int		ft_atohexi(char *str, char *basemin, char *basemaj);
int		ft_colorshift1(int p1, int p2, int percentage);
int		ft_colorshift2(int c, t_point c1, t_point c2, int percentage);
int		fdf_redirect(int keycode, t_vars *vars);
int		ft_rotateevent(int keycode, t_vars *vars);
int		ft_move(int keycode, t_vars *vars);
void	ft_mlxclearing(t_vars *vars);
t_point	**fdf_zoom(t_point **grid, int sizex, int sizey, float facteur);
int		ft_redirectzoom(int keycode, t_vars *vars);
void	ft_free(void **grid, int sizey);
t_point	**fdf_singularity(t_point **grid, int sizex, int sizey);
int		ft_norm(t_point z, int x, int y);
void	ft_redirectsing(t_vars *vars);
t_point	**copygrid(t_point **grid, int sizex, int sizey);
void	ft_resetgrid(t_vars *vars);

#endif
