#include "so_long.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

{

// MLX allows you to define its core behaviour before startup.
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(1000, 1000, "Slime Adventure", false);
	if (!mlx)
		ft_error();

	mlx_texture_t *grass1 = mlx_load_png("./assets/Forest/Grass/Grass-1.png");
	mlx_texture_t *slime1 = mlx_load_png("./assets/slime_pack/blob_all.png");
	mlx_image_t* grass = mlx_texture_to_image(mlx, grass1);
	mlx_image_t* slime = mlx_texture_to_image(mlx, slime1);
	int i = 0;
	while (i <= mlx->width)
	{
	mlx_image_to_window(mlx, grass, i, 0);
	i += 25;
	}
	mlx_image_to_window(mlx, slime, 0, 0);

	// Create and display the image.
	// mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	// if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	// 	ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(grass, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}