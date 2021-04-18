#include "../includes/mlx.h"

typedef struct s_data {
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

int main(void) {
  void *mlx;
  void *mlx_win;
  t_data img;

  int x = 500, y = 500;

  mlx = mlx_init();
  mlx_win = mlx_new_window(mlx, x, y, "Hello world!");
  img.img = mlx_new_image(mlx, x, y);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                               &img.endian);

  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      my_mlx_pixel_put(&img, j, i, 0x00FF0000);
    }
  }

  mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  mlx_loop(mlx);
}
