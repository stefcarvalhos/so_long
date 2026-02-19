/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:03:16 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/10 17:03:16 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copymap(t_map *map)
{
	char	**copymap;
	int		i;

	i = 0;
	copymap = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!copymap)
		return (NULL);
	while (i < map->height)
	{
		copymap[i] = ft_strdup(map->matriz[i]);
		if (!copymap[i])
		{
			while (i >= 0)
			{
				free(copymap[i]);
				i--;
			}
			free(copymap);
			return (NULL);
		}
		i++;
	}
	copymap[i] = NULL;
	return (copymap);
}

void	ft_flood_fill(char **copymap, int x, int y)
{
	if (copymap[x][y] == '1' || copymap[x][y] == 'S')
		return ;
	if (copymap[x][y] == '0' || copymap[x][y] == 'C' || copymap[x][y] == 'E')
		copymap[x][y] = 'S';
	ft_flood_fill(copymap, x + 1, y);
	ft_flood_fill(copymap, x - 1, y);
	ft_flood_fill(copymap, x, y + 1);
	ft_flood_fill(copymap, x, y - 1);
}

int	ft_checkfill(char **copymap)
{
	int	x;
	int	y;

	x = 0;
	while (copymap[x])
	{
		y = 0;
		while (copymap[x][y])
		{
			if (copymap[x][y] == 'C' || copymap[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	ft_validategameplay(t_game *game)
{
	char	**copymap;
	int		i;

	i = 0;
	copymap = ft_copymap(game->map);
	if (!copymap)
		ft_error(game, "Error! Could not copy map");
	ft_flood_fill(copymap, game->map->pos_player.h, game->map->pos_player.w);
	if (!ft_checkfill(copymap))
	{
		while (copymap[i])
		{
			free(copymap[i]);
			i++;
		}
		free(copymap);
		ft_error(game, "Error! The map is not playable");
	}
	while (copymap[i])
	{
		free(copymap[i]);
		i++;
	}
	free(copymap);
}

void	ft_startimg(t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->floor = NULL;
	game->exit = NULL;
	game->coll = NULL;
}
