#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "position.h"
#include "led.h"
#include "light.h"


uint8_t render_pt_lights_led_array( const light_rgb_t *lights, 
                                    const uint16_t     n_lights,
                                    led_t             *leds,
                                    const uint16_t     n_leds );

