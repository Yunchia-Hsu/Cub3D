
#include "../include/cub3D.h"


void check_door_position(t_game *game, char ** map)
{
	int i;
	int j;

//  int l = 0;
// 	while (game->map[l])
// 	{
// 		dprintf(2, "map[%d]: %s\n",l, game->map[l]);
// 		l++;
// 	}


	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
			{
				game->door_x = j;
				game->door_y = i;
			}
			j++;
		}
		i++;
	}
     //dprintf(2, "in position check door x: %zu, door y : %zu\n", game->door_x, game->door_y);
}


// void render_door(t_game *game, char *path)
// {
  

   
    
   
//     game->door = mlx_texture_to_image(game->mlx, door_text);
//     if (!game->door)
//     {
//         mlx_strerror(mlx_errno);
// 		clean_all_exit(game, "mlx_door_mlx_err");
//     }

    
//     dprintf(2, "door x: %zu, door y : %zu\n", game->door_x, game->door_y);
//     mlx_image_to_window(game->mlx, game->door, game->door_x , game->door_x );
//     game->door->instances[0].z = 1;
// }


void init_door(t_game *game)
{
    
	if(game->door_state != true)
		game->door_state = false;
    game->hit_door = false;
	game->d = '\0';
    check_door_position(game, game->map);

    game->door_open_texture = mlx_load_png(DOOR_PATH_OPEN);
    
    if (!game->door_open_texture)
    {
        mlx_strerror(mlx_errno);
		clean_all_exit(game, "mlx_png_err");
    }
    game->door_close_texture = mlx_load_png(DOOR_PATH_CLOSE);
    if (!game->door_close_texture)
    {
        mlx_strerror(mlx_errno);
		clean_all_exit(game, "mlx_png_err");
    }
}

void check_door(t_game *game)
{
    float distance;
    float dx;
    float dy;
    //static double last_press;
    //double current_time;

    //init_door(game);i put it in wall function 
    // 檢查玩家是否在門附近並處理互動
    dx = game->rays->p_x - game->door_x;
    dy = game->rays->p_y - game->door_y;
    distance = sqrt((dx * dx) + (dy * dy));
	//dprintf(2, "distance: %f\n", distance);
    // 如果玩家在門附近且按下 E 鍵
    //last_press = 0;
	// if (distance < 420 && game->door_state == true)
	// 	game->door_state = true;
   if (distance < 420 && game->d == 'D')
    {
       
	   
		if (game->door_state == false)
		{
		//dprintf(2, "game->d: %c \n", game->d);
			game->door_state = true;
		}
		

    }
	
        // 切換門的狀態（添加延遲以防止多次觸發）
        
        // if  (game->door_state == false)
        //     render_door(game, DOOR_PATH_CLOSE);
        // else
        // {
        //      render_door(game, DOOR_PATH_OPEN);
        //      // set game finished
        // }
           
}