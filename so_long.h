/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 21:14:04 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 16:25:01 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_posplayer
{
	int		h;
	int		w;
}	t_posplayer;

typedef struct s_posexit
{
	int		h;
	int		w;
}	t_posexit;

typedef struct s_map
{
	char		**matriz;
	int			height;
	int			width;
	int			collectible;
	int			start_play;
	int			exit_play;
	int			countmov;
	t_posplayer	pos_player;
	t_posexit	pos_exit;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*player;
	void	*floor;
	void	*exit;
	void	*coll;
	t_map	*map;
}	t_game;

void	ft_error(t_game *game, const char *msg);
int		ft_openmap(const char *file, t_game *game);
void	ft_checksize(int fd, t_game *game);
void	ft_mapfree(t_map *map);
void	ft_startmap(t_map *map);
void	ft_alloc(t_game *game);
void	ft_readmap(int fd, t_game *game);
void	ft_checkchar(t_game *game, int x, int y, char curr);
void	ft_validatechar(t_game *game);
void	ft_printmap(t_map *map);
void	ft_processmap(const char *file, t_game *game);
char	**ft_copymap(t_map *map);
void	ft_flood_fill(char **copymap, int x, int y);
int		ft_checkfill(char **copymap);
void	ft_validategameplay(t_game *game);
int		ft_checkfilename(char *file);
void	ft_createwin(t_game *game, t_map *map);
void	ft_images(t_game *game);
void	ft_render(t_game *game, t_map *map);
void	ft_startgame(t_game *game);
int		main(int ac, char **av);
void	ft_playermove(t_game *game, int height, int width);
void	ft_moves(t_game *game, const char *move);
int		ft_keymoves(int keycode, void *param);
void	ft_findplayer(t_map *map);
int		ft_close(t_game *game, const char *msg);
void	ft_renderwall(t_game *game, t_map *map);
void	ft_renderfloor(t_game *game, t_map *map);
void	ft_renderplayer(t_game *game, t_map *map);
void	ft_renderexit(t_game *game, t_map *map);
void	ft_rendercoll(t_game *game, t_map *map);
void	ft_startimg(t_game *game);
int		ft_closex(t_game *game);

#endif
