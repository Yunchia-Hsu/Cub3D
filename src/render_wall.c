/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:06:33 by iniska            #+#    #+#             */
/*   Updated: 2024/11/15 19:04:49 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static uint32_t hexax(uint32_t r, uint32_t g, uint32_t b)
{
	return (r << 16) | (g << 8) | b;
}

static void	floor_n_ceiling(t_game *game, int ray, double bot_pxl, double top_pxl)
{
	double	i;
	uint32_t floor;
	uint32_t ceil;

	floor = hexax(game->floor_r, game->floor_g, game->floor_b);
	ceil = hexax(game->ceiling_r, game->ceiling_g, game->ceiling_b);

	i = bot_pxl;
	while (i < WINDOW_HEIGHT)
		set_pixels(game, ray, i++, 0xd6ebff); //floor  將 bot_pxl 以下的像素塗為地板顏色，模擬地板。
	i = 0;
	while (i  < top_pxl)
		set_pixels(game, ray, i++, 0x2694ab); // ceiling
}



void	set_walls(t_game *game, int ray)//計算牆壁高度及位置，並調用其他函數繪製牆壁、地板和天花板。
{
	double	wall_hi;
	double	top_pixl;
	double	bot_pixl;

	wall_hi = 0;
	game->rays->distance *= cos((game->player_angl - game->rays->ray_angl));//用 cos 修正視角的影響，確保牆壁距離的計算正確。
	if (fabs(game->rays->distance) < 0.0001)
		game->rays->distance = 0.0001;
	wall_hi = fabs((TILE / game->rays->distance) * (WINDOW_WIDTH / 2) / tan(game->fow));
	bot_pixl = (WINDOW_HEIGHT / 2) + (wall_hi / 2);
	top_pixl = (WINDOW_HEIGHT / 2) - (wall_hi / 2);
	if (bot_pixl > WINDOW_HEIGHT)
		bot_pixl = WINDOW_HEIGHT;
	if (top_pixl < 0)
		top_pixl = 0;
	game->rays->i = ray;     

	draw_wall(game, bot_pixl, top_pixl, wall_hi);
	floor_n_ceiling(game, ray, bot_pixl, top_pixl);
}
