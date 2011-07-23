#include <stdio.h>
#include <stdint.h>

#include "position.h"

#ifndef LIGHT
#define LIGHT

/* Definition of point light source */
typedef struct
{ 
  uint16_t r;
  uint16_t g;
  uint16_t b;
  pos_3d_t pos;
} light_rgb_t;

uint8_t init_random_lights(     light_rgb_t       *lights, 
                                const uint16_t     n_lights );
uint8_t print_light_status(     const light_rgb_t *lights, 
                                const uint16_t     n_lights );
uint8_t update_lights_pos_rand( light_rgb_t       *lights, 
                                const uint16_t     n_lights, 
                                const float        dt );

#endif

