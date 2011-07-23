#include <stdio.h>
#include <stdint.h>

#include "position.h"

#ifndef LED
#define LED

/* Definition of RGB LED module */
typedef struct
{
  uint16_t r;
  uint16_t g;
  uint16_t b;
  pos_3d_t pos;
} led_t;

uint8_t print_led_status( const led_t    *leds, 
                          const uint16_t  n_leds );

uint8_t init_led_pos_rect_grid( led_t         *leds,
                                const uint8_t  n_x,
                                const uint8_t  n_y,
                                const uint8_t  n_z,
                                const float    size_x, 
                                const float    size_y, 
                                const float    size_z); 


#endif
