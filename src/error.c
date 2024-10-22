/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:11:17 by yhsu              #+#    #+#             */
/*   Updated: 2024/10/16 11:26:48 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void err_message_exit(char * message)
{
	//ft_putendl_fd( "Error ", 2);
	if (message)
		dprintf(2, "there is a message here!\n");
		//ft_putendl_fd(message, 2);
	exit (1);	
}
