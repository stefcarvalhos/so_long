/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:13:49 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 16:19:23 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_createwin(t_game *game, t_map *map)
{
	int	pixels;
	int	w;
	int	h;

	pixels = 64;
	w = map->width * pixels;
	h = map->height * pixels;
	game->win = mlx_new_window(game->mlx, w, h, "So Long");
	if (!game->win)
		ft_error(game, "Error creating window");
}

void	ft_images(t_game *game)
{
	int	img_h;
	int	img_w;

	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &img_w, &img_h);
	if (!game->wall)
		ft_close(game, "Error loading wall image");
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &img_w, &img_h);
	if (!game->floor)
		ft_close(game, "Error loading floor image");
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &img_w, &img_h);
	if (!game->player)
		ft_close(game, "Error loading player image");
	game->coll = mlx_xpm_file_to_image(game->mlx,
			"textures/coll.xpm", &img_w, &img_h);
	if (!game->coll)
		ft_close(game, "Error loading collectible image");
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &img_w, &img_h);
	if (!game->exit)
		ft_close(game, "Error loading exit image");
}

void	ft_render(t_game *game, t_map *map)
{
	ft_renderwall(game, map);
	ft_renderfloor(game, map);
	ft_renderplayer(game, map);
	ft_renderexit(game, map);
	ft_rendercoll(game, map);
}

void	ft_startgame(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_close(game, "Error initializing MiniLibX");
	ft_createwin(game, game->map);
	ft_images(game);
	ft_render(game, game->map);
	mlx_hook(game->win, 17, 0, ft_closex, game);
	mlx_key_hook(game->win, ft_keymoves, game);
	mlx_loop(game->mlx);
	ft_close(game, NULL);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	ft_startimg(game);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		ft_error(game, "Error memory allocation");
	ft_startmap(game->map);
	if (ac != 2)
		ft_error(game, "Error! Invalid quantity of arguments");
	if (!ft_checkfilename(av[1]))
		ft_error(game, "Error! File name is invalid");
	ft_processmap(av[1], game);
	ft_startgame(game);
	ft_mapfree(game->map);
	free(game);
	return (0);
}
