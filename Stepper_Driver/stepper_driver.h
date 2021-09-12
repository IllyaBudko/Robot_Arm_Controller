/*
  Stepper Motor driver application level functions
*/

#ifndef _STEPPER_DRIVER_H_
#define _STEPPER_DRIVER_H_

#include <stdint.h>

#include "stm32f411xe.h"

struct Stepper{
  
};

void stepper_driver_init(void);
void stepper_driver_run(void);
void stepper_motor_config(struct Stepper * joint, uint32_t maxSpeed, uint32_t minSpeed);

#endif /*_STEPPER_DRIVER_H_*/
