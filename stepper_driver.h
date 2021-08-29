/*
  Stepper Motor driver application level functions
*/

#ifndef _STEPPER_DRIVER_H_
#define _STEPPER_DRIVER_H_

#include <stdint.h>

#include "low_timer.h"
#include "int_timer.h"

/*
  Stepper motor timebase defines for use with
  void stepper_driver_timebase_update(uint8_t stepperTimeBase)
*/
#define TIMEBASE_1uS    1U
#define TIMEBASE_10uS   10U
#define TIMEBASE_100uS  100U
#define TIMEBASE_1mS    1000U

struct Stepper{
  
};

void stepper_driver_init(void);
void stepper_driver_timebase_update(uint8_t stepperTimeBase);

void stepper_motor_config(struct Stepper * joint, uint32_t maxSpeed, uint32_t minSpeed);

#endif /*_STEPPER_DRIVER_H_*/
