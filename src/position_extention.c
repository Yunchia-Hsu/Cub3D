/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_extention.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:08:36 by yhsu              #+#    #+#             */
/*   Updated: 2024/11/21 16:15:40 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_texture_extension(t_game *game)
{
	int	len;

	len = ft_strlen(game->ea_texture_path);
	if (len <= 4
		|| ft_strncmp(game->ea_texture_path + (len - 4), ".png", 4) != 0)
		return (0);
	len = ft_strlen(game->so_texture_path);
	if (len <= 4
		|| ft_strncmp(game->so_texture_path + (len - 4), ".png", 4) != 0)
		return (0);
	len = ft_strlen(game->we_texture_path);
	if (len <= 4
		|| ft_strncmp(game->we_texture_path + (len - 4), ".png", 4) != 0)
		return (0);
	len = ft_strlen(game->no_texture_path);
	if (len <= 4
		|| ft_strncmp(game->no_texture_path + (len - 4), ".png", 4) != 0)
		return (0);
	return (1);
}

int	get_name(char *filename, int len)
{
	int	i;

	i = len - 1;
	while (i > 0)
	{
		if (filename[i] == '/')
			return (i);
		i--;
	}
	return (i);
}	

int	check_file_extesion(char *filename)
{
	int	len;
	int	nb;

	len = ft_strlen(filename);
	nb = get_name(filename, len);
	filename = filename + nb + 1;
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(filename + (len - 4), ".cub", 4) != 0)
	{
		return (0);
	}
	if (filename[len - 1] == '/')
	{
		return (0);
	}
	return (1);
}

void	check_player_position(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
}
