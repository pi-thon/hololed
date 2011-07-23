#include <stdio.h>
#include <stdint.h>

#include "led.h"
#include "position.h"


/**
* @brief Prints status of each LED (RGB components). 
*
* @param leds
* @param n_leds
*
* @return 
*/
uint8_t print_led_status( const led_t    *leds, 
                          const uint16_t  n_leds )
{
  uint16_t        ld_idx;
  const led_t    *led;
  const pos_3d_t *pos;
  for (ld_idx = 0; ld_idx < n_leds; ld_idx++)
    {
      led = &leds[ld_idx];
      pos = &led->pos;

      printf("led %d:\n",ld_idx);
      printf("  r = %d, g = %d, b = %d\n", led->r, led->g, led->b);    
      /*printf("  x = %f, y = %f, z = %f\n", pos->x, pos->y, pos->z);*/
    }

  return 0;
}

/**
* @brief Initializes the positions of the LEDs as a rectilinear grid in x,y,z
*        space.
*
* @param leds
* @param n_x
* @param n_y
* @param n_z
* @param size_x
* @param size_y
* @param size_z
*
* @return 
*/
uint8_t init_led_pos_rect_grid( led_t         *leds,
                                const uint8_t  n_x,
                                const uint8_t  n_y,
                                const uint8_t  n_z,
                                const float    size_x, 
                                const float    size_y, 
                                const float    size_z)
{
  uint16_t  n_leds;
  uint16_t  ld_idx;
  float     x;
  float     y;
  float     z;
  float     dx;
  float     dy;
  float     dz;
  uint8_t   x_idx;
  uint8_t   y_idx;
  uint8_t   z_idx;
  led_t    *led; 
  pos_3d_t *pos;

  n_leds = n_x * n_y * n_z; 

  dx = size_x / (n_x - 1);  
  dy = size_y / (n_y - 1);  
  dz = size_z / (n_z - 1);

  ld_idx = 0;
  x = -size_x / 2.0F;
  y = -size_y / 2.0F;
  z = -size_z / 2.0F;
  for (x_idx = 0; x_idx < n_x; x_idx++)
    {
      
      for (y_idx = 0; y_idx < n_y; y_idx++)
        {

          for (z_idx = 0; z_idx < n_z; z_idx++)
            {
 
              /* Update current LED's position */
              pos = &leds[ld_idx].pos;
              pos->x = x;
              pos->y = y;
              pos->z = z;

              /* Increment LED pointer */
              ld_idx++;
              z += dz;
            }      
          z = -size_z / 2.0F;
          y += dy;
        }      

      y = -size_y / 2.0F;
      z = -size_z / 2.0F;
      x += dx;   
    }      


  return 0;
} 




