/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:50:10 by iniska            #+#    #+#             */
/*   Updated: 2024/11/25 09:17:24 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	verify_movin(t_game *game, int x, int y)
{
	game->rays->p_x = x;
	game->rays->p_y = y;
	if (game->rays->p_x % TILE == 0)
		game->rays->p_x += 1;
	if (game->rays->p_y % TILE == 0)
		game->rays->p_y += 1;
}

static void	move_player(t_game *game, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	double	new_y;
	double	new_x;

	new_x = game->rays->p_x + move_x;
	new_y = game->rays->p_y + move_y;
	map_x = new_x / TILE;
	map_y = new_y / TILE;
	if (valid(game, map_y, map_x, 1))
	{
		if (BONUS > 0)
			death_checker(game, 0);
		if (game->map[map_y][map_x] == 'D'
			&& game->map[map_y][game->rays->p_x / TILE] == 'D'
			&& game->map[game->rays->p_y / TILE][map_x] == 'D')
			game->win = true;
		else if (valid(game, map_y, map_x, 2))
			verify_movin(game, new_x, new_y);
	}
}

static void	rotate(t_game *game, int i)
{
	if (i == 1)
	{
		game->player_angl += ROTATIO_SPEED;
		if (game->player_angl > 2 * PI)
			game->player_angl -= 2 * PI;
	}
	else
	{
		game->player_angl -= ROTATIO_SPEED;
		if (game->player_angl < 0)
			game->player_angl += 2 * PI;
	}
}

void	move_hook(t_game *game, double move_x, double move_y)
{
	wasd(game, &move_x, &move_y);
	if (!game->death && !game->win)
	{
		if (game->rotation == 1)
			rotate(game, 1);
		if (game->rotation == -1)
			rotate(game, 0);
	}
	game->up_down = 0;
	game->left_right = 0;
	game->rotation = 0;
	if (!game->death && !game->win)
		move_player(game, move_x, move_y);
}
