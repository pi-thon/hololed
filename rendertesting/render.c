#include <stdio.h>
#include <stdint.h>
#include <math.h>       /* For pow */

#include "position.h"
#include "led.h"
#include "light.h"


/**
* @brief Sets LED RGB values based on composite effects of multiple point
*        source lights.
*
* @param lights
* @param n_lights
* @param leds
* @param n_leds
*
* @return 
*/
uint8_t render_pt_lights_led_array( const light_rgb_t *lights, 
                                    const uint16_t     n_lights,
                                    led_t             *leds,
                                    const uint16_t     n_leds )
{
  uint16_t           lt_idx;
  uint16_t           ld_idx;
  float              dist_sq;
  const light_rgb_t *light;
  led_t             *led;
  
  for (ld_idx = 0; ld_idx < n_leds; ld_idx++)
    {
      led = &leds[ld_idx];
      led->r = 0;
      led->g = 0;
      led->b = 0;
     
      for (lt_idx = 0; lt_idx < n_lights; lt_idx++)
        {
          light = &lights[lt_idx];
          dist_sq = sqrt( pow( (light->pos.x - led->pos.x), 2 )
                    + pow( (light->pos.y - led->pos.y), 2 )  
                    + pow( (light->pos.z - led->pos.z), 2 )) ;
          /*printf("dist_sq = %f\n",dist_sq);*/
          led->r += (uint16_t) ( 10 * light->r / dist_sq );      
          led->g += (uint16_t) ( 10 * light->g / dist_sq );      
          led->b += (uint16_t) ( 10 * light->b / dist_sq );      
        }   
    }

  return 0;
}

