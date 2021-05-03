#include "minirt.h"
#include "mlx.h"

int draw_scene(t_minirt *minirt) {

  t_list *camera = minirt->scene->cameras;
  t_camera *current_cam;
  t_ray ray;
  t_color color;
  while (camera != NULL) {
    current_cam = camera->content;
    int x;
    int y;
    x = 0;
    y = 0;
    while (x < minirt->scene->resolution.width) {
      y = 0;
      while (y < minirt->scene->resolution.height) {
        ray = get_ray_direction(
            (2.0f * x) / minirt->scene->resolution.width - 1.0f,
            (-2.0f * y) / minirt->scene->resolution.height + 1.0f,
            *current_cam);
        minirt->t = MAX_VALUE;
        int t = 0;
        color = raytrace(minirt, &ray, &t);
        if (t == 1) {
          // printf("x=%d,y=%d, intersect =%d\n", x, y, t);
          // return 0;
        }
        my_mlx_pixel_put(current_cam->image, x, y,
                         create_rgb(color, current_cam->image->endian));
        y += 1;
      }
      x++;
    }
    camera = camera->next;
  }

  return (0);
}

// int draw_scene(t_minirt *minirt) {

//   t_list *camera = minirt->scene->cameras;
//   t_camera *current_cam;
//   while (camera != NULL) {
//     current_cam = camera->content;
//     int x;
//     int y;
//     x = 0;
//     y = 0;
//     while (y < minirt->scene->resolution.height) {
//       x = 0;
//       while (x < minirt->scene->resolution.width) {
//         if (current_cam->id == 1)
//           my_mlx_pixel_put(&current_cam->image, x, y, 0x00FF0000);
//         else
//           my_mlx_pixel_put(&current_cam->image, x, y, 0x00FF9999);
//         x++;
//       }
//       y++;
//     }
//     camera = camera->next;
//   }

//   return (0);
// }