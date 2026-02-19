/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:47 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 16:06:47 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_playermove(t_game *game, int height, int width)
{
	char	temp;

	temp = game->map->matriz[height][width];
	if (height < 0 || height >= game->map->height
		|| width < 0 || width >= game->map->width)
		return ;
	if (game->map->matriz[height][width] != '1')
	{
		game->map->matriz[game->map->pos_player.h][game->map->pos_player.w]
			= '0';
		game->map->pos_player.h = height;
		game->map->pos_player.w = width;
		game->map->matriz[height][width] = 'P';
		game->map->countmov++;
		ft_printf("%d\n", game->map->countmov);
		ft_render(game, game->map);
	}
	if (temp == 'C')
		game->map->collectible--;
	if (temp == 'E' && game->map->collectible == 0)
	{
		ft_close(game, "Congratulations, you win!");
	}
}

void	ft_moves(t_game *game, const char *move)
{
	int	new_posh;
	int	new_posw;

	new_posh = game->map->pos_player.h;
	new_posw = game->map->pos_player.w;
	if (ft_strcmp(move, "up") == 0)
		new_posh = game->map->pos_player.h - 1;
	else if (ft_strcmp(move, "down") == 0)
		new_posh = game->map->pos_player.h + 1;
	else if (ft_strcmp(move, "left") == 0)
		new_posw = game->map->pos_player.w - 1;
	else if (ft_strcmp(move, "right") == 0)
		new_posw = game->map->pos_player.w + 1;
	ft_playermove(game, new_posh, new_posw);
}

int	ft_keymoves(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
		ft_close(game, NULL);
	if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
		ft_moves(game, "up");
	else if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		ft_moves(game, "down");
	else if (keycode == XK_A || keycode == XK_a || keycode == XK_Left)
		ft_moves(game, "left");
	else if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		ft_moves(game, "right");
	return (0);
}
