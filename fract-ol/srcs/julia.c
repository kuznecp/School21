/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:37:48 by myuriko           #+#    #+#             */
/*   Updated: 2022/03/06 19:37:49 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia_set(double x, double y, t_data *mlx)
{
	int		i;
	double	xx;
	double	yy;
	double	temp;

	xx = x;
	yy = y;
	i = 1;
	while (i < ITERATION)
	{
		temp = xx;
		xx = (pow(xx, 2) - pow(yy, 2)) + 0.103 + mlx->juliax;
		yy = (2 * temp * yy) + 0.321 + mlx->juliay;
		if (pow(xx, 2) + pow(yy, 2) > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy,
				(mlx->color) + 0x008DE3EC * i);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(mlx -> mlx, mlx -> win, mlx->loopx, mlx->loopy, 0);
	return (0);
}

int	julia(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			julia_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	return (0);
}

void	start_julia(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Fract'ol - julia");
	mlx.xmin = MINX;
	mlx.xmax = MAXX;
	mlx.ymin = MINY;
	mlx.ymax = MAXY;
	mlx.color = 0;
	mlx.fractol = 2;
	julia((void *)&mlx);
	mlx_key_hook(mlx.win, keys, (void *)&mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, (void *)0);
	mlx_mouse_hook(mlx.win, zoom, (void *)&mlx);
	mlx_string_put(mlx.mlx, mlx.win, 15, 10, 0x001B273C, "julia");
	mlx_loop(mlx.mlx);
}
