/*
  Stepper Motor driver application level functions
*/

#include "stepper_driver.h"

/**
  * @brief  
  *
  * @param  Parameter description
  *
  * @param  None
  *
  * @retval None
  */
void stepper_driver_init(void);

/**
  * @brief  TIM2 update timer timebase from default value
  *
  * @param  Parameter description with acceptable parameter values 
  *         This parameter can be one of the following values:
  *         @arg @ref TIMEBASE_1uS           
  *         @arg @ref TIMEBASE_10uS 
  *         @arg @ref TIMEBASE_100uS
  *         @arg @ref TIMEBASE_1mS  
  *
  * @retval None
  */
void stepper_driver_timebase_update(uint8_t stepperTimeBase);

/**
  * @brief  Stepper motor parameter and variables initialization
  *
  * @param  struct Stepper joint *, pointer to  structure
  *         which is used for working with stepper motor
  * @param  uint32_t maxSpeed, maximum speed allowed for stepper motor
  * @param  uint32_t minSpeed, minimum speed allowed for stepper motor
  *
  * @retval None
  */
void stepper_motor_config(struct Stepper * joint, uint32_t maxSpeed, uint32_t minSpeed);