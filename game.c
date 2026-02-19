/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:16:33 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/14 19:59:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_playermove(t_game *game, int height, int width)
{
	char temp;

	temp = game->map->matriz[height][width];
	if (height < 0 || height >= game->map->height || width < 0 || width >= game->map->width)
		return;
	if(game->map->matriz[height][width] != '1')
	{
		game->map->matriz[game->map->pos_player.h][game->map->pos_player.w] = '0';
		game->map->pos_player.h = height;
		game->map->pos_player.w = width;
		game->map->matriz[height][width] = 'P';
		ft_render(game, game->map);
	}
	if (temp == 'C')
		game->map->collectible--;
	if (temp == 'E' && game->map->collectible == 0)
	{
		ft_printf("Congratulations, you win!\n");
		ft_mapfree(game->map);
		free(game->map);
		exit(0);
	}
}

void	ft_moves(t_game *game, char move)
{
	int	new_posh;
	int	new_posw;

	new_posh = game->map->pos_player.h;
	new_posw = game->map->pos_player.w;
	if(ft_strcmp(move, "up") == 0)
		new_posh = game->map->pos_player.h - 1;
	else if (ft_strcmp(move, "down") == 0)
		new_posh = game->map->pos_player.h + 1;
	else if (ft_strcmp(move, "left") == 0)
		new_posh = game->map->pos_player.w - 1;
	else if (ft_strcmp(move, "right") == 0)
		new_posh = game->map->pos_player.w + 1;
	ft_playermove(game, new_posh, new_posw);
}

int	ft_keymoves(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == 53)
		exit(0);
	if(keycode == 13 || keycode == 126 || keycode == 119)
		ft_moves(game, "up");
	else if(keycode == 1 || keycode == 125 || keycode == 115)
		ft_moves(game, "down");
	else if(keycode == 0 || keycode == 123 || keycode == 97)
		ft_moves(game, "left");
	else if(keycode == 2 || keycode == 124 || keycode == 100)
		ft_moves(game, "right");
	return (0);
}