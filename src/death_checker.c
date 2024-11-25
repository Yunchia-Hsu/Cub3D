/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:43:42 by iniska            #+#    #+#             */
/*   Updated: 2024/11/19 12:12:55 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	game_over_image(t_game *game)
{
	mlx_texture_t	*pic;
	int				offsex;
	int				offsey;

	if (game->death)
		pic = mlx_load_png(GAMEOVERI);
	if (game->win)
		pic = mlx_load_png(WINIMA);
	if (!pic)
		return ;
	offsex = (WIN_WIDTH - pic->width) / 2;
	offsey = (WIN_HEI - pic->height) / 2;
	game->gameover_image = mlx_texture_to_image(game->mlx, pic);
	if (!game->gameover_image)
	{
		mlx_delete_texture(pic);
		return ;
	}
	mlx_image_to_window(game->mlx, game->gameover_image, offsex, offsey);
	mlx_delete_texture(pic);
}
