/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:27:26 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 16:11:17 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_startmap(t_map *map)
{
	map->matriz = NULL;
	map->height = 0;
	map->width = 0;
	map->pos_player.h = 0;
	map->pos_player.w = 0;
	map->collectible = 0;
	map->countmov = 0;
	map->exit_play = 0;
	map->start_play = 0;
	map->pos_exit.h = 0;
	map->pos_exit.w = 0;
}

void	ft_alloc(t_game *game)
{
	game->map->matriz = (char **)malloc(sizeof(char *) * game->map->height);
	if (game->map->matriz == NULL)
		ft_error(game, "Error memory allocation");
}

void	ft_readmap(int fd, t_game *game)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	if (fd == -1)
		ft_error(game, "Error opening map file");
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len -1] == '\n')
			line[len - 1] = '\0';
		game->map->matriz[i] = ft_strdup(line);
		free(line);
		if (!game->map->matriz[i])
		{
			close(fd);
			ft_mapfree(game->map);
			exit(1);
		}
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_processmap(const char *file, t_game *game)
{
	int	fd;

	fd = 0;
	ft_startmap(game->map);
	fd = ft_openmap(file, game);
	ft_checksize(fd, game);
	ft_alloc(game);
	fd = ft_openmap(file, game);
	ft_readmap(fd, game);
	ft_validatechar(game);
	ft_validategameplay(game);
	ft_findplayer(game->map);
}
