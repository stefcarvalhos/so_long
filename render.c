/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:32:30 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 16:14:18 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_renderwall(t_game *game, t_map *map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			c = map->matriz[x][y];
			if (c == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

void	ft_renderfloor(t_game *game, t_map *map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			c = map->matriz[x][y];
			if (c == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->floor, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

void	ft_renderplayer(t_game *game, t_map *map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			c = map->matriz[x][y];
			if (c == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

void	ft_renderexit(t_game *game, t_map *map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			c = map->matriz[x][y];
			if (c == 'E' || (c == '0' && x == map->pos_exit.h
					&& y == map->pos_exit.w && map->collectible > 0))
			{
				map->matriz[x][y] = 'E';
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit, y * 64, x * 64);
			}
			y++;
		}
		x++;
	}
}

void	ft_rendercoll(t_game *game, t_map *map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			c = map->matriz[x][y];
			if (c == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->coll, y * 64, x * 64);
			y++;
		}
		x++;
	}
}
