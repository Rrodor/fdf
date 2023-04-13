/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:04:53 by rrodor            #+#    #+#             */
/*   Updated: 2023/04/11 19:21:02 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_splitlen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

t_point	**ft_getgrid(int fd, int *sizex, int *sizey)
{
	char	*line;
	t_pars	p;
	t_point	**grid;
	char	**split;

	p.x = -1;
	grid = (t_point **)malloc(sizeof(t_point *) * 1000);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_split(line, ' ');
		grid[++p.x] = (t_point *)malloc(sizeof(t_point) * ft_splitlen(split));
		p.y = -1;
		while (split[++(p.y)])
		{
			grid[p.x][p.y].x = p.y * ZOOM;
			grid[p.x][p.y].y = p.x * ZOOM;
			grid[p.x][p.y].z = ft_atoi(split[p.y]) * ZOOM;
			grid[p.x][p.y].c = ft_getcolors(split[p.y]);
		}
		free(line);
		*sizex = ft_splitlen(split);
		ft_free((void **)split, *sizex);
	}
	*sizey = p.x + 1;
	return (grid);
}

int	ft_getcolors(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (!str[i])
		return (0x00FFFFFF);
	i++;
	return (ft_atohexi(&str[i], "0123456789abcdef", "0123456789ABCDEF"));
}

int	ft_atohexi(char *str, char *basemin, char *basemaj)
{
	int	i;
	int	j;
	int	n;

	i = 2;
	n = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != basemin[j] && str[i] != basemaj[j])
			j++;
		n = n * 16 + j;
		i++;
	}
	return (n);
}
