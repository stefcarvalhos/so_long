/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:24:41 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 16:21:54 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapfree(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->matriz)
	{
		while (i < map->height)
		{
			free(map->matriz[i]);
			i++;
		}
		free(map->matriz);
		map->matriz = NULL;
	}
	free(map);
	map = NULL;
}

void	ft_error(t_game *game, const char *msg)
{
	if (msg != NULL)
	{
		ft_printf("%s\n", msg);
	}
	if (game->map != NULL)
	{
		ft_mapfree(game->map);
		game->map = NULL;
	}
	free(game->map);
	free(game);
	game = NULL;
	exit(1);
}

void	ft_findplayer(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->matriz[x][y] == 'P')
			{
				map->pos_player.h = x;
				map->pos_player.w = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

int	ft_close(t_game *game, const char *msg)
{
	if (msg != NULL)
		ft_printf("%s\n", msg);
	ft_mapfree(game->map);
	if (game->mlx)
	{
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->coll)
			mlx_destroy_image(game->mlx, game->coll);
		if (game->exit)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(1);
	return (0);
}

int	ft_closex(t_game *game)
{
	ft_mapfree(game->map);
	if (game->mlx)
	{
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->coll)
			mlx_destroy_image(game->mlx, game->coll);
		if (game->exit)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(1);
	return (0);
}
