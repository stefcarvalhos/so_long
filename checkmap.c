/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:03:26 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 16:38:45 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_openmap(const char *file, t_game *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Error opening map file");
	return (fd);
}

void	ft_checksize(int fd, t_game *game)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	game->map->width = ft_strlen(line) - 1;
	while (line != NULL)
	{
		game->map->height++;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		if (len != game->map->width)
		{
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			close(fd);
			ft_error(game, "Error! The map is not rectangular.");
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_checkchar(t_game *game, int x, int y, char curr)
{
	if (curr != '0' && curr != '1' && curr != 'C' && curr != 'E' && curr != 'P')
		ft_error(game, "Error! The map contains invalid character");
	if ((x == 0 || x == game->map->height - 1 || y == 0
			|| y == game->map->width -1) && curr != '1')
		ft_error(game, "Error! The map is not enclosed by walls");
	if (curr == 'P')
	{
		game->map->start_play++;
		game->map->pos_player.h = x;
		game->map->pos_player.w = y;
	}
	else if (curr == 'E')
	{
		game->map->exit_play++;
		game->map->pos_exit.h = x;
		game->map->pos_exit.w = y;
	}
	else if (curr == 'C')
		game->map->collectible++;
}

void	ft_validatechar(t_game *game)
{
	int	x;
	int	y;
	int	curr;

	x = 0;
	while (x < game->map->height)
	{
		y = 0;
		while (y < game->map->width)
		{
			curr = game->map->matriz[x][y];
			ft_checkchar(game, x, y, curr);
			y++;
		}
		x++;
	}
	if (game->map->width <= 0)
		ft_error(game, "Error! The map is empty");
	if (game->map->exit_play != 1)
		ft_error(game, "Error! Map does not contain one exit");
	if (game->map->start_play != 1)
		ft_error(game, "Error! Map does not contain one player");
	if (game->map->collectible < 1)
		ft_error(game, "Error! Map does not contain one collectible");
}

int	ft_checkfilename(char *file)
{
	int	len;

	len = ft_strlen(file);
	while (file[len] != '.')
		len--;
	if (ft_strncmp(".ber\0", &file[len], 5) == 0 && file[len - 1]
		&& file[len - 1] != '/')
		return (1);
	return (0);
}
