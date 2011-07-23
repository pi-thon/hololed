#include <stdio.h>
#include <stdint.h>

#include "light.h"
#include "led.h"
#include "position.h"

#define NUM_LIGHTS    10 
#define NUM_LEDS     27 

#define DEBUG_LEVEL   1

/* Main */
main()
{
  uint8_t      status;
  float        dt;
  uint32_t     n_times;
  uint32_t     t_idx;
  uint16_t     l_idx;
  pos_3d_t    *pos;
  light_rgb_t *lights;
  led_t       *leds;

  /* Initialize point-source lights */
  lights = malloc(NUM_LIGHTS * sizeof(light_rgb_t));
  status = init_random_lights(lights, NUM_LIGHTS);
#if DEBUG_LEVEL > 1
  status = print_light_status(lights, NUM_LIGHTS);
  printf("--------\n");
#endif

  /* Initialize LEDs */
  leds = malloc(NUM_LEDS * sizeof(led_t));
  status = init_led_pos_rect_grid(leds, 3, 3, 3, 200, 200, 200);

  dt = 0.1;
  n_times = 30; 
  for (t_idx = 0; t_idx < n_times; t_idx++)
    {
      status = update_lights_pos_rand(lights, NUM_LIGHTS, dt); 
      status = render_pt_lights_led_array(lights, NUM_LIGHTS, leds, NUM_LEDS);
#if DEBUG_LEVEL > 1
      status = print_light_status(lights, NUM_LIGHTS);
#endif
#if DEBUG_LEVEL > 0
      status = print_led_status(leds, 1);
#endif
    }

  free(lights);
  free(leds);
}





