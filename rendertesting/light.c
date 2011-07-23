#include <stdio.h>
#include <stdint.h>

#include "light.h"

/**
* @brief Initialize all lights with random RGB values and XYZ positions 
*
* @param lights
* @param n_lights
*
* @return 
*/
uint8_t init_random_lights( light_rgb_t *lights, const uint16_t n_lights)
{
   uint16_t     l_idx;
   light_rgb_t *light;
   pos_3d_t    *pos;
   for (l_idx = 0; l_idx < n_lights; l_idx++)
     { 
       light = &lights[l_idx];
       light->r = random() % 255;
       light->g = random() % 255;
       light->b = random() % 255;

       pos = &light->pos;
       pos->x = (random() % 200) - 100;
       pos->y = (random() % 200) - 100;
       pos->z = (random() % 200) - 100;
     }

  return 0;
}

/**
* @brief Print RGB values and XYZ positions of all lights 
*
* @param lights
* @param n_lights
*
* @return 
*/
uint8_t print_light_status( const light_rgb_t *lights, const uint16_t n_lights)
{
   uint16_t           l_idx;
   const light_rgb_t *light;
   const pos_3d_t    *pos;
   for (l_idx = 0; l_idx < n_lights; l_idx++)
     { 
       light = &lights[l_idx];
       pos   = &light->pos;

       printf("l_idx = %d\n",l_idx);
       printf("  r = %d, g = %d, b = %d\n", light->r, light->g, light->b);
       printf("  x = %f, y = %f, z = %f\n", pos->x, pos->y, pos->z);
     }

  return 0;
}

/* Randomly preturb all lights' positions */
uint8_t update_lights_pos_rand( light_rgb_t       *lights, 
                                const uint16_t     n_lights, 
                                const float        dt )
{
  uint16_t     l_idx;
  light_rgb_t *light;
  pos_3d_t    *pos;
  float        dx, dy, dz;
  
  dx = dt*((random() % 255) - 100);  
  dy = dt*((random() % 255) - 100);  
  dz = dt*((random() % 255) - 100);  

  for (l_idx = 0; l_idx < n_lights; l_idx++)
    {
      light   = &lights[l_idx];
      pos     = &light->pos;
      pos->x += dx;
      pos->y += dy;
      pos->z += dz;
    }
  
  return 0;
}
